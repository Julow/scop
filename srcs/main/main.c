/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 13:54:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/07 16:22:55 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "shader.h"
#include "mesh.h"
#include "mesh_loader.h"
#include "obj.h"
#include "anim.h"
#include "obj_anim.h"
#include "renderer.h"
#include "math_utils.h"
#include "ft_printf.h"
#include "events.h"
#include "utils.h"
#include <stdlib.h>
#include <math.h>

/*
** ========================================================================== **
** Scene
*/
typedef struct	s_scene_obj
{
	t_sub			mesh;
	t_renderer		*renderer;
	t_anim			*anim;
	t_vec3			pos;
	t_vec3			rot;
	t_vec3			shear;
	float			scale;
	int				reflect;
}				t_scene_obj;

#define S_OBJ(m,e,a,p,r,h,k,f)	((t_scene_obj){SUBC(m),e,a,VEC3 p,VEC3 r,VEC3 h,k,f})

static const t_scene_obj	g_scene[] = {
	S_OBJ("res/obj/42.obj", RENDERER(SIMPLE), ANIM_SCALE(1200, F_ANIM_REPEAT, 0.8f, 2.f, &smooth_elastic), (-20.f, 0.f, 5.f), (1.f, 0.2f, 0.f), (0.f, 0.f, 0.f), 1.f, 0),
	S_OBJ("res/obj/cube.obj", RENDERER(SIMPLE), NULL, (20.f, 0.f, 20.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), 1.f, 0),
	S_OBJ("res/obj/cube.obj", RENDERER(SIMPLE), NULL, (-700.f, 120.f, -750.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), 1.f, 0),
	S_OBJ("res/obj/teapot.obj", RENDERER(SIMPLE), ANIM_ROT(2000, F_ANIM_RESTART, (0.f, 0.f, 0.f), (0.f, M_PI * 2.f, 0.f), &smooth_out), (-35.f, -7.f, 0.f), (0.f, M_PI / 2.f, 0.f), (0.f, 0.f, 0.f), 1.f, 0),
	S_OBJ("res/obj/teapot2.obj", RENDERER(SIMPLE), ANIM_MOVE(1800, F_ANIM_RESTART, (10.f, -10.f, 0.f), (10.f, 10.f, 0.f), &smooth_bounce), (-40.f, -5.f, -5.f), (0.f, 2.f, 0.f), (0.f, 0.f, 0.f), 0.5f, 0),
	S_OBJ("res/obj/teapot2.obj", RENDERER(SIMPLE), ANIM_MOVE(1800, F_ANIM_REPEAT, (20.f, -10.f, 0.f), (20.f, 10.f, 0.f), &smooth_bounce), (-40.f, -5.f, -5.f), (0.f, 2.f, 0.f), (0.f, 0.f, 0.f), 0.5f, 0),
	S_OBJ("res/obj/teapot2.obj", RENDERER(SIMPLE), ANIM_MOVE(1800, F_ANIM_REVERSE, (0.f, -10.f, 0.f), (0.f, 10.f, 0.f), &smooth_bounce), (-40.f, -5.f, -5.f), (0.f, 2.f, 0.f), (0.f, 0.f, 0.f), 0.5f, 0),
	S_OBJ("res/obj/cube.obj", RENDERER(SIMPLE), ANIM_SHEAR(4000, F_ANIM_REPEAT, (0.5f, 0.f, 0.f), (-0.5f, 0.5f, -0.5f), &smooth_in_out), (300.f, -10.f, -50.f), (0.f, 0.f, 0.f), (0.f, 0.5f, 0.5f), 50.f, 0),
	// S_OBJ("res/obj/venice.obj", RENDERER(SIMPLE), ANIM_SCALE(1200, F_ANIM_REPEAT, 0.8f, 2.f, &smooth_elastic), (0.f, -40.f, 0.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), 1.f, 0),
	S_OBJ("res/obj/venice.obj", RENDERER(SIMPLE), NULL, (0.f, -40.f, 0.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), 1.f, 0),
	// S_OBJ("venice.obj", RENDERER(DEPTH), NULL, (0.f, -40.f, 0.f), (0.f, 0.f, 0.f), (0.f, 0.f, 0.f), 1.f, 0),
};

t_bool			load_scene(t_scop *scop)
{
	t_obj			*obj;
	int				i;

	i = -1;
	while (++i < G_ARRAY_LEN(g_scene))
	{
		obj = (*(g_scene[i].renderer))();
		if ((obj->mesh = load_mesh(g_scene[i].mesh)) == NULL)
			continue ;
		obj->anim = g_scene[i].anim;
		if (obj->anim != NULL)
			anim_start(obj->anim);
		ft_transform_move(&(obj->transform), g_scene[i].pos);
		ft_transform_rotate(&(obj->transform), g_scene[i].rot);
		ft_transform_scale(&(obj->transform), g_scene[i].scale);
		ft_transform_reflect(&(obj->transform), g_scene[i].reflect);
		ft_transform_shear(&(obj->transform), g_scene[i].shear);
		ft_vpush_back(&(scop->objects), &obj, 1);
	}
	return (true);
}

/*
** ========================================================================== **
** Anim obj
*/

void			anim(t_scop *scop)
{
	const t_ulong	now = ft_clock(0);
	t_obj			*obj;
	int				i;

	i = -1;
	while (++i < scop->objects.length)
	{
		obj = *(t_obj**)VECTOR_GET(scop->objects, i);
		if (obj->anim != NULL)
			anim_update(obj, obj->anim, now);
	}
}

/*
** ========================================================================== **
** Render obj
*/

void			render(t_scop *scop)
{
	t_render_params		params;
	t_obj				*obj;
	int					i;

	params = (t_render_params){&(scop->camera), &(scop->projection_m)};
	glClearColor(0.f, 0.6f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	i = -1;
	while (++i < scop->objects.length)
	{
		obj = *(t_obj**)VECTOR_GET(scop->objects, i);
		obj->render(&params, obj);
	}
}

/*
** ========================================================================== **
** Main
*/

static void		handle_input(t_scop *scop, float elapsed)
{
	t_vec3			pos;
	t_vec2			look;

	if (handle_key_hold(scop, elapsed, &pos))
		camera_move(&(scop->camera), pos);
	if (handle_cursor_move(scop, &look))
		camera_look(&(scop->camera), look);
}

int				main(void)
{
	t_scop			scop;
	t_fps			fps;
	int				last_flags;

	ft_bzero(&scop, sizeof(scop));
	scop.objects = VECTOR(t_obj*);
	scop.camera = CAMERA(VEC3_0(), VEC2_0());
	scop.projection_m = ft_mat4perspective(PERSPECTIVE_FOV, WIN_RATIO,
		PERSPECTIVE_NEAR, PERSPECTIVE_FAR);
	camera_move(&(scop.camera), VEC3(-57.2f, -6.7f, 10.6f));
	camera_look(&(scop.camera), VEC2(2.9f, 0.01f));
	if (!init_window(&scop) || !load_scene(&scop))
		return (1);
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
			ft_printf("\rFPS: %-2lld t: %-3lld flags: %016b "
				"pos: [ %f, %f, %f ] look: [ %f, %f ]%5 ",
				fps.average_fps, fps.average_time, scop.flags,
				scop.camera.position.x, scop.camera.position.y,
				scop.camera.position.z, scop.camera.look.x, scop.camera.look.y);
		}
		handle_input(&scop, fps.elapsed);
		anim(&scop);
	}
	ft_printf("\n");
	glfwTerminate();
	return (0);
}
