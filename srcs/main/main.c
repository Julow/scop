/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 13:54:16 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/21 19:22:25 by jaguillo         ###   ########.fr       */
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
** point light component
*/

#include "lighter.h"

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
		{ SUBC("point-light"),
			V(&create_point_light_component), &scop->lighter,
			&g_vec3_json
		}
	};

	t_file_in *const	in = ft_in_fdopen(0);
	bool				r;

	r = load_scene(V(in), &scop->scene, &VECTORC(scene_components), WIN_RATIO);
	ft_in_close(in);
	return (r);
}

/*
** ========================================================================== **
** Utils
*/

void			texture_to_quad(GLuint buff)
{
	static t_shader		*shader = NULL;

	if (shader == NULL)
	{
		shader = NEW(t_shader);
		if (!load_shader(SUBC("srcs/main/texture_to_quad.glsl"), shader))
			HARD_ASSERT(false, "Failed to load texture_to_quad.glsl");
		glUseProgram(shader->handle);
		glUniform1i(glGetUniformLocation(shader->handle, "_u_texture"), 0);
	}
	glUseProgram(shader->handle);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, buff);
	render_screen_quad();
}

/*
** ========================================================================== **
** HDR Render
** TODO: HDR
*/

#define EXPOSURE		5.f

/*
** Render to framebuffer:
** 	0: final color (vec3)
*/
void			render_hdr(t_gbuffer const *gbuffer)
{
	static t_shader		*shader = NULL;

	if (shader == NULL)
	{
		shader = NEW(t_shader);
		if (!load_shader(SUBC("srcs/main/render_hdr.glsl"), shader))
			HARD_ASSERT(false, "Failed to load texture_to_quad.glsl");
		glUseProgram(shader->handle);
		glUniform1i(glGetUniformLocation(shader->handle, "_u_col"), 0);
		glUniform1i(glGetUniformLocation(shader->handle, "_u_light"), 1);
		glUniform1f(glGetUniformLocation(shader->handle, "_u_exposure"), EXPOSURE);
	}
	glUseProgram(shader->handle);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, gbuffer->buff_col);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, GBUFFER_BUFF_LIGHT(gbuffer));
	render_screen_quad();
}

/*
** ========================================================================== **
** Render obj
*/

void			render(t_scop *scop)
{
	GBUFFER_BIND(&scop->gbuffer, POS, NOR, COL, LIGHT(&scop->gbuffer));

	glClearColor(0.f, 0.f, 0.f, 0.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	ft_mat4mult(&scop->scene.projection_m, camera_get_view(&scop->scene.camera),
			&scop->mesh_renderer.viewproj); // TODO: only when needed
	mesh_render(&scop->mesh_renderer);

	render_lights(&scop->lighter, &scop->gbuffer);

	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
	// texture_to_quad(scop->gbuffer.buff_col);
	// texture_to_quad(scop->gbuffer.buff_nor);
	// texture_to_quad(scop->gbuffer.buff_pos);
	// texture_to_quad(GBUFFER_BUFF_LIGHT(&scop->gbuffer));
	// texture_to_quad(GBUFFER_BUFF_LIGHT_BACK(&scop->gbuffer));
	render_hdr(&scop->gbuffer);
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
	if (!gbuffer_init(VEC2U(WIN_WIDTH, WIN_HEIGHT), &scop.gbuffer))
		return (1);
	mesh_renderer_init(&scop.mesh_renderer);
	if (!lighter_init(&scop.lighter))
		return (1);
	if (!scop_load_scene(&scop))
		return (1);
	// glfwSwapInterval(0); // TODO: tmp
	init_events(scop.window);
	fps = fps_init(200000);
	last_flags = -1;
	update(&scop);
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
