/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 13:54:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/21 22:53:43 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "shader_loader.h"
#include "resources.h"
#include "math_utils.h"
#include "utils.h"
#include <stdlib.h>
#include <math.h>

/*
** ========================================================================== **
** Obj management
*/
void			obj_move(t_obj *obj, t_vec3 pos)
{
	obj->position = pos;
	obj->flags |= F_OBJ_UPDATED;
}

void			obj_rotate(t_obj *obj, t_vec3 rot)
{
	obj->rotation = rot;
	obj->flags |= F_OBJ_UPDATED;
}

void			obj_scale(t_obj *obj, float scale)
{
	obj->scale = scale;
	obj->flags |= F_OBJ_UPDATED;
}

t_mat4			*obj_get_model(t_obj *obj)
{
	if (obj->flags & F_OBJ_UPDATED)
	{
		obj->model_m[0] = MAT4_I();
		ft_mat4translate(obj->model_m, obj->position);
		ft_mat4scale(obj->model_m, obj->scale);
		ft_mat4rotate(obj->model_m, obj->rotation);
		obj->model_m[1] = MAT4_I();
		ft_mat4rotate_inv(obj->model_m + 1,
			ft_vec3sub(VEC3_0(), obj->rotation));
		ft_mat4scale(obj->model_m + 1, 1.f / obj->scale);
		ft_mat4translate(obj->model_m + 1, ft_vec3sub(VEC3_0(), obj->position));
		ft_mat4transpose(obj->model_m + 1);
		obj->flags &= ~F_OBJ_UPDATED;
	}
	return (obj->model_m);
}

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
		obj_move(&obj, g_scene[i].pos);
		obj_rotate(&obj, g_scene[i].rot);
		obj_scale(&obj, g_scene[i].scale);
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
	glUniformMatrix4fv(shader->loc[0], 1, GL_TRUE, (float*)obj_get_model(obj));
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
	SHADER_DEF("test.glsl", &simple_renderer, NULL, ((char*[]){
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
	SHADER_DEF("depth.glsl", &depth_renderer, NULL, ((char*[]){
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
	glfwSwapInterval(0);
	init_key_events(&scop);
	init_mouse_events(&scop);
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
