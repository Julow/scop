/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 13:54:16 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/12 12:20:03 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "ft/math_mat4.h"
#include "ft/math_vec3.h"

#include "anim.h"
#include "anim_component.h"
#include "events.h"
#include "main.h"
#include "mesh.h"
#include "mesh_loader.h"
#include "mesh_renderer.h"
#include "obj.h"
#include "scene_loader.h"
#include "shader.h"
#include "utils.h"

#include <math.h>
#include <stdlib.h>

/*
** ========================================================================== **
** Scene
*/

#include "ft/file_in.h"
#include "ft/json_t.h"

/*
** anim component
*/

#include "anim_component.h"

static t_json_t_value const	g_vec3_json = JSON_T_FIXED_LIST(t_vec3,
	(x, JSON_T_VALUE(FLOAT)),
	(y, JSON_T_VALUE(FLOAT)),
	(z, JSON_T_VALUE(FLOAT))
);

static t_json_t_value const		g_anim_type_json = JSON_T_ENUM(t_obj_anim_t,
	("translate", OBJ_ANIM_TRANSLATE),
	("rotate", OBJ_ANIM_ROTATE),
	("shear", OBJ_ANIM_SHEAR),
	("scale", OBJ_ANIM_SCALE)
);

static t_json_t_value const		g_anim_smooth_json = JSON_T_ENUM(float (*)(float),
	("linear", &smooth_linear),
	("in", &smooth_in),
	("out", &smooth_out),
	("in_out", &smooth_in_out),
	("elastic", &smooth_elastic),
	("bounce", &smooth_bounce),
	("back_in", &smooth_back_in),
	("back_out", &smooth_back_out),
	("back_in_out", &smooth_back_in_out)
);

static t_json_t_value const		g_anim_flags_json = JSON_T_ENUM(uint32_t,
	("none", 0),
	("restart", F_ANIM_RESTART),
	("repeat", F_ANIM_REPEAT),
	("reverse", F_ANIM_REVERSE)
);

static t_json_t_value const		g_anim_param_json = JSON_T_DICT(t_anim_component_param,
	("from", from, g_vec3_json),
	("to", to, g_vec3_json),
	("duration", duration, JSON_T_VALUE(FLOAT)),
	("type", type, g_anim_type_json),
	("smooth", smooth, g_anim_smooth_json),
	("repeat", flags, g_anim_flags_json)
);

/*
** mesh renderer component
*/

#include "mesh_renderer.h"

/*
** -
*/

static bool		scop_load_scene(t_scop *scop)
{
	t_scene_component const	scene_components[] = {
		{ SUBC("anim"), V(&create_anim_component), NULL, &g_anim_param_json },
		{ SUBC("mesh"),
			V(&mesh_renderer_component_create), &scop->mesh_renderer,
			&JSON_T_VALUE(STRING)
		},
	};

	t_file_in *const	in = ft_in_fdopen(0);
	bool				r;

	r = load_scene(V(in), &scop->scene, &VECTORC(scene_components), WIN_RATIO);
	ft_in_close(in);
	return (r);
}

/*
** ========================================================================== **
** Render obj
*/

// static void		render_objs(t_vector *objs)
// {
// 	t_obj				*obj;

// 	obj = VECTOR_IT(*objs);
// 	while (VECTOR_NEXT(*objs, obj))
// 	{
// 		if (obj->renderer != NULL)
// 			obj->renderer->render(obj->renderer, &obj->world_m);
// 		if (obj->childs.length > 0)
// 			render_objs(&(obj->childs));
// 	}
// }

void			render(t_scop *scop)
{
	glClearColor(0.f, 0.6f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	ft_mat4mult(&scop->scene.projection_m, camera_get_view(&scop->scene.camera),
			&scop->mesh_renderer.viewproj); // TODO: only when needed
	mesh_render(&scop->mesh_renderer);
}

/*
** ========================================================================== **
** Update obj
*/

void			update(t_scop *scop)
{
	obj_update(&scop->scene.objects);
}

/*
** ========================================================================== **
** Main
*/

static void		handle_input(t_scop *scop, float elapsed)
{
	t_vec3			pos;
	t_vec2			look;

	pos = scop->scene.camera.position;
	if (handle_key_hold(scop, elapsed, &pos))
		camera_move(&(scop->scene.camera), pos);
	look = scop->scene.camera.look;
	if (handle_cursor_move(scop, &look))
		camera_look(&(scop->scene.camera), look);
}

int				main(void)
{
	t_scop			scop;
	t_fps			fps;
	int				last_flags;

	memset(&scop, 0, sizeof(scop));
	if (!init_window(&scop))
		return (1);
	mesh_renderer_init(&scop.mesh_renderer);
	if (!scop_load_scene(&scop))
		return (1);
	glfwSwapInterval(0); // TODO: tmp
	init_events(scop.window);
	fps = fps_init(200000);
	last_flags = -1;
	while (!glfwWindowShouldClose(scop.window))
	{
		fps_start(&fps);
		render(&scop);
		glfwSwapBuffers(scop.window);
		glfwPollEvents();
		if (fps_end(&fps) || scop.flags != last_flags)
		{
			last_flags = scop.flags;
			ft_printf("\rFPS: %-2lld t: %-3lld flags: %.16b "
				"pos: [ %f, %f, %f ] look: [ %f, %f ]%5 %!",
				fps.average_fps, fps.average_time, scop.flags,
				scop.scene.camera.position.x, scop.scene.camera.position.y,
				scop.scene.camera.position.z, scop.scene.camera.look.x, scop.scene.camera.look.y);
		}
		handle_input(&scop, fps.elapsed);
		update(&scop);
	}
	ft_printf("\n%!");
	glfwTerminate();
	return (0);
}
