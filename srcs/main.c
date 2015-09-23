/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 13:54:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/23 08:48:57 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "scop.h"
#include "shader_loader.h"
#include "mesh_loader.h"
#include "resources.h"
#include "obj.h"
#include "math_utils.h"
#include "events.h"
#include "utils.h"
#include <stdlib.h>
#include <math.h>

/*
** ========================================================================== **
** Def events
*/

static void		on_mouse_move(t_scop *env, double x, double y)
{
	env->flags |= FLAG_CURSOR_MOVE;
	(void)x;
	(void)y;
}

static void		on_esc(t_scop *env, int key_code)
{
	glfwSetWindowShouldClose(env->window, GL_TRUE);
	(void)key_code;
}

t_key_event const		g_events[] = {
	E_KEY_FLAG(GLFW_KEY_W, t_scop, flags, FLAG_MOVE_FRONT),
	E_KEY_FLAG(GLFW_KEY_W, t_scop, flags, FLAG_MOVE_FRONT),
	E_KEY_FLAG(GLFW_KEY_D, t_scop, flags, FLAG_MOVE_LEFT),
	E_KEY_FLAG(GLFW_KEY_S, t_scop, flags, FLAG_MOVE_BACK),
	E_KEY_FLAG(GLFW_KEY_A, t_scop, flags, FLAG_MOVE_RIGHT),
	E_KEY_FLAG(GLFW_KEY_LEFT_CONTROL, t_scop, flags, FLAG_ACCELERATE),
	E_KEY_FLAG(GLFW_KEY_LEFT_SHIFT, t_scop, flags, FLAG_MOVE_DOWN),
	E_KEY_FLAG(GLFW_KEY_SPACE, t_scop, flags, FLAG_MOVE_UP),
	E_KEY_CALLBACK(GLFW_KEY_ESCAPE, &on_esc),
	E_MOUSE_MOVE(&on_mouse_move),
	E_END()
};

/*
** ========================================================================== **
** Scene
*/
typedef struct	s_scene_obj
{
	t_sub			mesh;
	t_sub			texture;
	t_sub			shader;
	t_vec3			pos;
	t_vec3			rot;
	float			scale;
}				t_scene_obj;

#define S_OBJ(m,t,s,p,r,k)	((t_scene_obj){SUBC(m),SUBC(t),SUBC(s),VEC3 p,VEC3 r,k})

static const t_scene_obj	g_scene[] = {
	S_OBJ("42.obj", "wall.tga", "test.glsl", (-20.f, 0.f, 5.f), (1.f, 0.2f, 0.f), 1.f),
	S_OBJ("cube.obj", "wall.tga", "test.glsl", (20.f, 0.f, 20.f), (0.f, 0.f, 0.f), 1.f),
	S_OBJ("cube.obj", "wall.tga", "test.glsl", (-700.f, 120.f, -750.f), (0.f, 0.f, 0.f), 1.f),
	S_OBJ("teapot.obj", "wall.tga", "test.glsl", (-35.f, -7.f, 0.f), (0.f, M_PI / 2.f, 0.f), 1.f),
	S_OBJ("teapot2.obj", "wall.tga", "test.glsl", (-40.f, -5.f, -5.f), (0.f, 2.f, 0.f), 0.1f),
	S_OBJ("cube.obj", "wall.tga", "test.glsl", (0.f, -55.f, 0.f), (0.f, 0.f, 0.f), 50.f),
	S_OBJ("venice.obj", "wall.tga", "test.glsl", (0.f, -40.f, 0.f), (0.f, 0.f, 0.f), 1.f),
	// S_OBJ("venice.obj", "wall.tga", "depth.glsl", (0.f, -40.f, 0.f), (0.f, 0.f, 0.f), 1.f),
};

t_bool			load_scene(t_scop *scop)
{
	t_obj			obj;
	int				i;

	i = -1;
	while (++i < G_ARRAY_LEN(g_scene))
	{
		ft_bzero(&obj, sizeof(t_obj));
		if ((obj.mesh = get_res(g_res_t.mesh, g_scene[i].mesh)) == NULL
		|| (obj.texture = get_res(g_res_t.texture, g_scene[i].texture)) == NULL
		|| (obj.shader = get_res(g_res_t.shader, g_scene[i].shader)) == NULL)
			continue ;
		ft_transform_move(&(obj.transform), g_scene[i].pos);
		ft_transform_rotate(&(obj.transform), g_scene[i].rot);
		ft_transform_scale(&(obj.transform), g_scene[i].scale);
		ft_vpush_back(&(scop->objects), &obj, 1);
	}
	return (true);
}

/*
** ========================================================================== **
** Shader def
*/

static void		depth_glsl_pre(t_shader const *shader, t_scop *scop, t_obj *obj)
{
	glUniformMatrix4fv(shader->loc[0], 1, GL_TRUE, (float*)ft_transform_get(&(obj->transform)));
	glUniformMatrix4fv(shader->loc[1], 1, GL_TRUE, (float*)camera_get_view(&(scop->camera)));
	glUniformMatrix4fv(shader->loc[2], 1, GL_TRUE, (float*)&(scop->projection_m));
	glUniform3fv(shader->loc[3], 1, (float*)&(scop->camera.position));
}

void			depth_renderer(t_scop *scop, t_obj *obj)
{
	int			i;
	int			offset;

	glUseProgram(obj->shader->handle);
	depth_glsl_pre(obj->shader, scop, obj);
	glBindVertexArray(obj->mesh->vao);
	offset = 0;
	i = -1;
	while (++i < obj->mesh->mtl_count)
		offset += obj->mesh->mtl[i].count;
	glDrawArrays(GL_TRIANGLES, 0, offset);
}

const t_shader_def	g_shader_def[] = {
	SHADER_DEF("test.glsl", &simple_renderer, NULL, ((char const*[]){
		[0] = "model",
		[1] = "view",
		[2] = "projection",
		[3] = "camera_pos",
		[4] = "lights",
		[5] = "light_count",
		[6] = "ambient_map",
		[7] = "diffuse_map",
		[8] = "specular_map",
		[9] = "ambient_color",
		[10] = "diffuse_color",
		[11] = "specular_color",
		[12] = "specular_exp",
	})),
	SHADER_DEF("depth.glsl", &depth_renderer, NULL, ((char const*[]){
		[0] = "model",
		[1] = "view",
		[2] = "projection",
		[3] = "camera_pos",
	})),
	SHADER_DEF_END()
};

/*
** ========================================================================== **
** Render obj
*/

void			render_obj(t_scop *scop, t_obj *obj)
{
	obj->shader->pre(scop, obj);
}

void			render(t_scop *scop)
{
	int				i;

	glClearColor(0.f, 0.6f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	i = -1;
	while (++i < scop->objects.length)
		render_obj(scop, VECTOR_GET(scop->objects, i));
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
	scop.objects = VECTOR(t_obj);
	scop.camera = CAMERA(VEC3_0(), VEC2_0());
	scop.projection_m = ft_mat4perspective(PERSPECTIVE_FOV, WIN_RATIO,
		PERSPECTIVE_NEAR, PERSPECTIVE_FAR);
	if (!init_window(&scop) || !load_scene(&scop))
		return (1);
	// glfwSwapInterval(0);
	init_events(scop.window, &scop);
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
	}
	ft_printf("\n");
	glfwTerminate();
	return (0);
}
