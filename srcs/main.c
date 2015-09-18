/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 13:54:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/18 20:05:28 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "resources.h"
#include "math_utils.h"
#include "utils.h"
#include <stdlib.h>
#include <math.h>

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
	S_OBJ("42.obj", "wall.tga", "test.glsl", (-20.f, 0.f, 5.f), (1.f, 0.2f, 0.f), 1.f),
	S_OBJ("cube.obj", "wall.tga", "test.glsl", (0.f, 10.f, 0.f), (0.f, 1.f, 0.5f), 1.f),
	S_OBJ("teapot.obj", "wall.tga", "test.glsl", (-35.f, -7.f, 0.f), (0.f, M_PI / 2.f, 0.f), 1.f),
	S_OBJ("teapot2.obj", "wall.tga", "test.glsl", (-40.f, -5.f, -5.f), (0.f, 2.f, 0.f), 0.1f),
	S_OBJ("venice.obj", "wall.tga", "test.glsl", (0.f, -40.f, 0.f), (0.f, 0.f, 0.f), 1.f),
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
** -
*/
static t_vec3 const	g_light_pos[] = { // TMP
	{-35.f, -7.f, 0.f},
	{176.f, -5.f, 55.f},
	{0.f, 50.f, 0.f},
};

void			render_obj(t_scop *scop, t_obj *obj)
{
	int			i;
	int			offset;

	glUseProgram(obj->shader->handle);
	// vertex uniforms
	glUniformMatrix4fv(obj->shader->loc[g_loc.model->index], 2, GL_TRUE, (float*)obj_get_model(obj));
	glUniformMatrix4fv(obj->shader->loc[g_loc.view->index], 1, GL_TRUE, (float*)camera_get_view(&(scop->camera)));
	glUniformMatrix4fv(obj->shader->loc[g_loc.projection->index], 1, GL_TRUE, (float*)&(scop->projection_m));
	// light uniforms
	glUniform3fv(obj->shader->loc[g_loc.camera_pos->index], 1, (float*)&(scop->camera.position));
	glUniform3fv(obj->shader->loc[g_loc.light_pos->index], G_ARRAY_LEN(g_light_pos), (float*)g_light_pos);
	glUniform1i(obj->shader->loc[g_loc.light_count->index], G_ARRAY_LEN(g_light_pos));
	// -
	glBindVertexArray(obj->mesh->vao);
	offset = 0;
	i = -1;
	while (++i < obj->mesh->mtl_count)
	{
		// material uniforms
		if (obj->mesh->mtl[i].mtl != NULL)
		{
			t_uint tmp;
			glActiveTexture(GL_TEXTURE0);
			if (obj->mesh->mtl[i].mtl->ambient_map != NULL)
				tmp = obj->mesh->mtl[i].mtl->ambient_map->handle;
			else
				tmp = 0;
			glBindTexture(GL_TEXTURE_2D, tmp);
			glUniform1i(obj->shader->loc[g_loc.ambient_map->index], 0);
			glUniform3fv(obj->shader->loc[g_loc.ambient_color->index], 1, (float*)&(obj->mesh->mtl[i].mtl->ambient_color));
			glActiveTexture(GL_TEXTURE1);
			if (obj->mesh->mtl[i].mtl->diffuse_map != NULL)
				tmp = obj->mesh->mtl[i].mtl->diffuse_map->handle;
			else
				tmp = 0;
			glBindTexture(GL_TEXTURE_2D, tmp);
			glUniform1i(obj->shader->loc[g_loc.diffuse_map->index], 1);
			glUniform3fv(obj->shader->loc[g_loc.diffuse_color->index], 1, (float*)&(obj->mesh->mtl[i].mtl->diffuse_color));
			glActiveTexture(GL_TEXTURE2);
			if (obj->mesh->mtl[i].mtl->specular_map != NULL)
				tmp = obj->mesh->mtl[i].mtl->specular_map->handle;
			else
				tmp = 0;
			glBindTexture(GL_TEXTURE_2D, tmp);
			glUniform1i(obj->shader->loc[g_loc.specular_map->index], 2);
			glUniform3fv(obj->shader->loc[g_loc.specular_color->index], 1, (float*)&(obj->mesh->mtl[i].mtl->specular_color));
			glUniform1i(obj->shader->loc[g_loc.specular_exp->index], obj->mesh->mtl[i].mtl->specular_exp);
		}
		// draw
		glDrawArrays(GL_TRIANGLES, offset, obj->mesh->mtl[i].count);
		// -
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
	t_fps			fps;
	int				last_flags;

	ft_bzero(&scop, sizeof(scop));
	scop.objects = VECTOR(t_obj);
	scop.camera = CAMERA(VEC3_0(), VEC2_0());
	scop.projection_m = ft_mat4perspective(PERSPECTIVE_FOV, WIN_RATIO, PERSPECTIVE_NEAR, PERSPECTIVE_FAR);
	if (!init_window(&scop) || !load_scene(&scop))
		return (1);
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
			ft_printf("\rFPS: %-2lld t: %-3lld flags: %016b",
				fps.average_fps, fps.average_time, scop.flags);
		}
		handle_key_hold(&scop, fps.elapsed);
		handle_cursor_move(&scop);
	}
	ft_printf("\n");
	return (glfwTerminate(), 0);
}
	
