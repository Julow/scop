/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 13:54:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/27 00:36:40 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "resources.h"
#include "math_utils.h"
#include "utils.h"
#include <stdlib.h>
#include <math.h>

#define FPS_INTERVAL		100000

/*
** obj
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
		obj->_model_m = ft_mat4identity();
		ft_mat4translate(&(obj->_model_m), obj->position);
		ft_mat4scale(&(obj->_model_m), obj->scale);
		ft_mat4rotate(&(obj->_model_m), obj->rotation);
		obj->flags &= ~F_OBJ_UPDATED;
	}
	return (&(obj->_model_m));
}
/*
** camera
*/
void			camera_move(t_camera *camera, t_vec3 pos)
{
	camera->position = pos;
	camera->flags |= F_CAMERA_UPDATED;
}

void			camera_look(t_camera *camera, t_vec3 look)
{
	camera->look_at = look;
	camera->flags |= F_CAMERA_UPDATED;
}

t_mat4			*camera_get_view(t_camera *camera)
{
	if (camera->flags & F_CAMERA_UPDATED)
	{
		camera->_view_m = ft_mat4look_at(camera->position, camera->look_at, VEC3(0.f, 1.f, 0.f));
		camera->flags &= ~F_CAMERA_UPDATED;
	}
	return (&(camera->_view_m));
}
/*
** scene
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
	S_OBJ("cube", "wall", "test", (-20.f, 0.f, -2.f), (0.f, 1.f, 0.5f), 1.f),
	S_OBJ("42", "wall", "test", (-20.f, 0.f, 5.f), (0.f, 0.f, 0.f), 1.f),
	// S_OBJ("teapot", "wall", "test", (-35.f, -7.f, 0.f), (0.f, M_PI / 2.f, 0.f), 1.f),
	// S_OBJ("shuttle", "wall", "test", (-40.f, 12.f, -1.f), (0.f, 2.f, 0.f), 0.8f),
	// S_OBJ("skyscraper", "wall", "test", (-40.f, 8.f, 9.f), (0.f, 2.f, 0.f), 0.2f),
	// S_OBJ("power_lines", "wall", "test", (-40.f, -5.f, -5.f), (0.f, 2.f, 0.f), 0.1f),
	// S_OBJ("cow", "wall", "test", (-40.f, -10.f, 9.f), (0.f, 1.f, 0.f), 1.f),
	// S_OBJ("symphysis", "wall", "test", (-40.f, 4.f, -10.f), (0.f, 2.f, 0.f), 0.5f),
};

t_bool			load_scene(t_scop *scop)
{
	t_obj			obj;
	int				i;

	i = -1;
	while (++i < G_ARRAY_LEN(g_scene))
	{
		ft_bzero(&obj, sizeof(t_obj));
		if ((obj.mesh = get_res(res_mesh, g_scene[i].mesh)) == NULL
			|| (obj.texture = get_res(res_texture, g_scene[i].texture)) == NULL
			|| (obj.shader = get_res(res_shader, g_scene[i].shader)) == NULL)
			return (false);
		obj_move(&obj, g_scene[i].pos);
		obj_rotate(&obj, g_scene[i].rot);
		obj_scale(&obj, g_scene[i].scale);
		ft_vpush_back(&(scop->objects), &obj, 1);
	}
	return (true);
}
/*
** -
*/

void			render_obj(t_scop *scop, t_obj *obj)
{
	// TODO useless uniform update
	glUniformMatrix4fv(obj->shader->model_loc, 1, GL_TRUE, (float*)obj_get_model(obj));
	glUniformMatrix4fv(obj->shader->view_loc, 1, GL_TRUE, (float*)camera_get_view(&(scop->camera)));
	glUniformMatrix4fv(obj->shader->projection_loc, 1, GL_TRUE, (float*)&(scop->projection_m));
	// -
	glUseProgram(obj->shader->handle);
	glBindTexture(GL_TEXTURE_2D, obj->texture->handle);
	glBindVertexArray(obj->mesh->vao);
	glDrawElements(GL_TRIANGLES, obj->mesh->count, GL_UNSIGNED_INT, 0);
}

void			render(t_scop *scop)
{
	int				i;

	glClearColor(0.f, 0.6f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	i = -1;
	while (++i < scop->objects.length)
		render_obj(scop, VECTOR_GET(&(scop->objects), i));
}

int				main(void)
{
	t_scop			scop;
	int				frames;
	t_ulong			last_fps;
	t_ulong			tmp;

	ft_bzero(&scop, sizeof(scop));
	scop.objects = VECTOR(t_obj);
	scop.camera = CAMERA((0.f, 0.f, 0.f), (1.f, 0.f, 0.f));
	scop.projection_m = ft_mat4perspective(PERSPECTIVE_FOV, WIN_RATIO, PERSPECTIVE_NEAR, PERSPECTIVE_FAR);
	if (!init_window(&scop) || !load_scene(&scop))
		return (1);
	init_key_events(&scop);
	frames = 0;
	last_fps = ft_clock(0);
	while (!glfwWindowShouldClose(scop.window))
	{
		tmp = ft_clock(0);
		if ((tmp - last_fps) >= FPS_INTERVAL)
		{
			ft_printf("FPS: %-4d\r", frames * 1000000 / (tmp - last_fps));
			last_fps = tmp;
			frames = 0;
		}
		frames++;
		render(&scop);
		glfwSwapBuffers(scop.window);
		glfwPollEvents();
	}
	return (glfwTerminate(), 0);
}
