/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 13:54:16 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/16 19:35:12 by jaguillo         ###   ########.fr       */
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
** Setup gbuffer
*/

static GLuint	setup_g_attach(t_vec2u win_size, GLint internal_format,
					GLenum format, GLenum type, GLenum attachment)
{
	GLuint			buff;

	glGenTextures(1, &buff);
	glBindTexture(GL_TEXTURE_2D, buff);
	glTexImage2D(GL_TEXTURE_2D, 0, internal_format, win_size.x, win_size.y,
			0, format, type, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glFramebufferTexture2D(GL_FRAMEBUFFER, attachment, GL_TEXTURE_2D, buff, 0);
	return (buff);
}

void			setup_gbuffer(t_gbuffer *dst, t_vec2u win_size)
{
	glGenFramebuffers(1, &dst->fbo);
	glBindFramebuffer(GL_FRAMEBUFFER, dst->fbo);

	dst->buff_pos = setup_g_attach(win_size, GL_RGB16F, GL_RGB, GL_FLOAT, GL_COLOR_ATTACHMENT0);
	dst->buff_nor = setup_g_attach(win_size, GL_RGB16F, GL_RGB, GL_FLOAT, GL_COLOR_ATTACHMENT1);
	dst->buff_col = setup_g_attach(win_size, GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE, GL_COLOR_ATTACHMENT2);

	glDrawBuffers(3, (GLuint[]){
		GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2
	});
}

/*
** ========================================================================== **
** Utils
*/

static float const	g_quad_vertices[] = {
	-1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
	-1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
	1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
	1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
};

static GLuint	init_quad(void)
{
	GLuint			quad_vao;
	GLuint			quad_vbo;

	glGenVertexArrays(1, &quad_vao);
	glBindVertexArray(quad_vao);
	glGenBuffers(1, &quad_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, quad_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_quad_vertices), &g_quad_vertices,
			GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), NULL);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), V(3 * sizeof(float)));
	return (quad_vao);
}

/*
** Render a full screen quad
** -
** layout=0 vec3 pos;
** layout=1 vec2 tex;
*/
void			render_screen_quad(void)
{
	static GLuint	quad_vao;
	static bool		quad_vao_init = false;

	if (!quad_vao_init)
	{
		quad_vao = init_quad();
		quad_vao_init = true;
	}
	glBindVertexArray(quad_vao);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

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
** Blinn-Phong lightning
** TODO: BlinnPhongRenderer
*/

/*
** Compute blinn-phong lightning for the gbuffer 'in'
** Render to framebuffer:
** 	0: light intensity (vec3)
*/
void			blinn_phong_lightning(t_gbuffer const *in)
{
	static t_shader		*shader = NULL;

	if (shader == NULL)
	{
		shader = NEW(t_shader);
		if (!load_shader(SUBC("srcs/main/blinn_phong_lightning.glsl"), shader))
			HARD_ASSERT(false, "Failed to load blinn_phong_lightning.glsl");
		glUseProgram(shader->handle);
		glUniform1i(glGetUniformLocation(shader->handle, "_u_pos"), 0);
		glUniform1i(glGetUniformLocation(shader->handle, "_u_nor"), 1);
		glUniform1i(glGetUniformLocation(shader->handle, "_u_col"), 2);
	}
	glUseProgram(shader->handle);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, in->buff_pos);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, in->buff_nor);
	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, in->buff_col);
	render_screen_quad();
}

/*
** ========================================================================== **
** Render obj
*/

void			render(t_scop *scop)
{
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, scop->gbuffer.fbo);

	glClearColor(0.f, 0.f, 0.f, 0.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	ft_mat4mult(&scop->scene.projection_m, camera_get_view(&scop->scene.camera),
			&scop->mesh_renderer.viewproj); // TODO: only when needed
	mesh_render(&scop->mesh_renderer);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	// texture_to_quad(scop->gbuffer.buff_col);
	blinn_phong_lightning(&scop->gbuffer);
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
	setup_gbuffer(&scop.gbuffer, VEC2U(WIN_WIDTH, WIN_HEIGHT));
	mesh_renderer_init(&scop.mesh_renderer);
	if (!scop_load_scene(&scop))
		return (1);
	// glfwSwapInterval(0); // TODO: tmp
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
