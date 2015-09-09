/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 13:54:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/09 18:51:10 by jaguillo         ###   ########.fr       */
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
		obj->model_m[0] = MAT4_I();
		ft_mat4translate(obj->model_m, obj->position);
		ft_mat4scale(obj->model_m, obj->scale);
		ft_mat4rotate(obj->model_m, obj->rotation);
		obj->model_m[1] = MAT4_I();
		ft_mat4rotate_inv(obj->model_m + 1, ft_vec3sub(VEC3_0(), obj->rotation));
		ft_mat4scale(obj->model_m + 1, 1.f / obj->scale);
		ft_mat4translate(obj->model_m + 1, ft_vec3sub(VEC3_0(), obj->position));
		ft_mat4transpose(obj->model_m + 1);
		obj->flags &= ~F_OBJ_UPDATED;
	}
	return (obj->model_m);
}

/*
** camera
*/
void			camera_move(t_camera *camera, t_vec3 pos)
{
	camera->position.x += pos.x;
	camera->position.y += pos.y;
	camera->position.z += pos.z;
	camera->flags |= F_CAMERA_UPDATED;
}

void			camera_look(t_camera *camera, t_vec2 look)
{
	float const		pi2 = M_PI / 2.f - 0.0001; // lol

	camera->look.x = look.x;
	camera->look.y = look.y;
	if (camera->look.y > pi2)
		camera->look.y = pi2;
	else if (camera->look.y < -pi2)
		camera->look.y = -pi2;
	camera->flags |= F_CAMERA_UPDATED;
}

t_mat4			*camera_get_view(t_camera *camera)
{
	t_vec3			look_at;

	if (camera->flags & F_CAMERA_UPDATED)
	{
		look_at = ft_vec3front(camera->look);
		look_at.x += camera->position.x;
		look_at.y += camera->position.y;
		look_at.z += camera->position.z;
		camera->view_m = ft_mat4look_at(camera->position, look_at, VEC3(0.f, 1.f, 0.f));
		camera->flags &= ~F_CAMERA_UPDATED;
	}
	return (&(camera->view_m));
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
	S_OBJ("cube.obj", "wall.tga", "test", (-20.f, 0.f, -2.f), (0.f, 1.f, 0.5f), 1.f),
	S_OBJ("42.obj", "wall.tga", "test", (-20.f, 0.f, 5.f), (1.f, 0.2f, 0.f), 1.f),
	S_OBJ("teapot.obj", "wall.tga", "test", (-35.f, -7.f, 0.f), (0.f, M_PI / 2.f, 0.f), 1.f),
	S_OBJ("shuttle.obj", "wall.tga", "test", (-40.f, 12.f, -1.f), (0.f, 2.f, 0.f), 0.8f),
	S_OBJ("skyscraper.obj", "wall.tga", "test", (-40.f, 8.f, 9.f), (0.f, 2.f, 0.f), 0.2f),
	S_OBJ("power_lines.obj", "wall.tga", "test", (-40.f, -5.f, -5.f), (0.f, 2.f, 0.f), 0.1f),
	S_OBJ("cow.obj", "wall.tga", "test", (-40.f, -10.f, 9.f), (0.f, 1.f, 0.5f), 1.f),
	S_OBJ("venice.obj", "wall.tga", "test", (0.f, -40.f, 0.f), (0.f, 0.f, 0.f), 0.5f),
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
			continue ;
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
static t_vec3 const	g_light_pos[] = { // TMP
	{-35.f, -7.f, 0.f},
	{176.f, -5.f, 55.f}
};

void			render_obj(t_scop *scop, t_obj *obj)
{
	int			i;
	int			offset;

	glUseProgram(obj->shader->handle);
	// TODO useless uniform update
	glUniformMatrix4fv(obj->shader->model_loc, 2, GL_TRUE, (float*)obj_get_model(obj));
	glUniformMatrix4fv(obj->shader->view_loc, 1, GL_TRUE, (float*)camera_get_view(&(scop->camera)));
	glUniformMatrix4fv(obj->shader->projection_loc, 1, GL_TRUE, (float*)&(scop->projection_m));
	//glUniform3fv
	glUniform3fv(obj->shader->lightpos_loc, G_ARRAY_LEN(g_light_pos), (float*)g_light_pos);
	glUniform1i(obj->shader->lightcount_loc, G_ARRAY_LEN(g_light_pos));
	// -
	glBindVertexArray(obj->mesh->vao);
	offset = 0;
	i = -1;
	while (++i < obj->mesh->mtl_count)
	{
		if (obj->mesh->mtl[i].mtl != NULL && obj->mesh->mtl[i].mtl->texture != NULL)
			glBindTexture(GL_TEXTURE_2D, obj->mesh->mtl[i].mtl->texture->handle);
		else
			glBindTexture(GL_TEXTURE_2D, obj->texture->handle);
		// TODO here set ambient/diffuse/specular
		glDrawArrays(GL_TRIANGLES, offset, obj->mesh->mtl[i].count);
		offset += obj->mesh->mtl[i].count;
	}
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

int				main(void)
{
	t_scop			scop;
	int				frames;
	t_ulong			last_fps;
	t_ulong			last_render;
	t_ulong			now;

	ft_bzero(&scop, sizeof(scop));
	scop.objects = VECTOR(t_obj);
	scop.camera = CAMERA(VEC3_0(), VEC2_0());
	scop.projection_m = ft_mat4perspective(PERSPECTIVE_FOV, WIN_RATIO, PERSPECTIVE_NEAR, PERSPECTIVE_FAR);
	if (!init_window(&scop) || !load_scene(&scop))
		return (1);
	init_key_events(&scop);
	init_mouse_events(&scop);
	frames = 0;
	last_render = ft_clock(0);
	last_fps = last_render;
	while (!glfwWindowShouldClose(scop.window))
	{
		render(&scop);
		glfwSwapBuffers(scop.window);
		glfwPollEvents();
		now = ft_clock(0);
		if ((now - last_fps) >= FPS_INTERVAL)
		{
			ft_printf("\rFPS: %-2lld flags: %016b", frames * 1000000 / (now - last_fps), scop.flags);
			last_fps = now;
			frames = 0;
		}
		frames++;
		handle_key_hold(&scop, (float)(now - last_render));
		handle_cursor_move(&scop);
		last_render = now;
	}
	ft_printf("\n");
	return (glfwTerminate(), 0);
}
	
