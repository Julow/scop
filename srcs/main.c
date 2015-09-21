/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 13:54:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/21 10:40:54 by jaguillo         ###   ########.fr       */
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
** Camera management
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
	float const		pi2 = M_PI / 2.f - 0.0001;

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
		camera->view_m = ft_mat4look_at(camera->position, look_at,
			VEC3(0.f, 1.f, 0.f));
		camera->flags &= ~F_CAMERA_UPDATED;
	}
	return (&(camera->view_m));
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
** -
*/
#define LIGHT(x,y,z,att)			{0.f, att, 0.f}, {x, y, z}
#define SPOT(x,y,z,dx,dy,dz,c,o)	{1.f, c, o}, {x, y, z}, {dx, dy, dz}

/*
** ?omg
** import math
** out("#define SPOT_CUTOFF		%f\n" % math.cos(math.pi - (math.pi / 4)))
** out("#define SPOT_OUTCUTOFF	%f\n" % math.cos(math.pi - (math.pi / 5.2)))
*/
#define SPOT_CUTOFF	-0.707107
#define SPOT_OUTCUTOFF -0.809017
/*
** ?end
*/

static t_vec3 const	g_lights[] = { // TMP
	LIGHT(20.f, 0.f, 20.f, 1000.f),
	SPOT(-700.f, 120.f, -750.f, 0.60083428991, 0.11971220728, -0.79035887006, SPOT_CUTOFF, SPOT_OUTCUTOFF),
};

/*
** ========================================================================== **
** Shader def
*/

static void		test_glsl_pre(t_shader const *shader, t_scop *scop, t_obj *obj)
{
	glUniformMatrix4fv(shader->loc[0], 2, GL_TRUE, (float*)obj_get_model(obj));
	glUniformMatrix4fv(shader->loc[1], 1, GL_TRUE, (float*)camera_get_view(&(scop->camera)));
	glUniformMatrix4fv(shader->loc[2], 1, GL_TRUE, (float*)&(scop->projection_m));
	glUniform3fv(shader->loc[3], 1, (float*)&(scop->camera.position));
	glUniform3fv(shader->loc[4], G_ARRAY_LEN(g_lights), (float*)g_lights);
	glUniform1i(shader->loc[5], G_ARRAY_LEN(g_lights));
}

static void		test_glsl_mtl(t_shader const *shader, t_scop *scop,
	t_obj const *obj, t_mtl const *mtl)
{
	t_uint			tmp;

	if (mtl == NULL)
		return ;
	glActiveTexture(GL_TEXTURE0);
	if (mtl->ambient_map != NULL)
		tmp = mtl->ambient_map->handle;
	else
		tmp = 0;
	glBindTexture(GL_TEXTURE_2D, tmp);
	glUniform1i(shader->loc[6], 0);
	glUniform3fv(shader->loc[9], 1, (float*)&(mtl->ambient_color));
	glActiveTexture(GL_TEXTURE1);
	if (mtl->diffuse_map != NULL)
		tmp = mtl->diffuse_map->handle;
	else
		tmp = 0;
	glBindTexture(GL_TEXTURE_2D, tmp);
	glUniform1i(shader->loc[7], 1);
	glUniform3fv(shader->loc[10], 1, (float*)&(mtl->diffuse_color));
	glActiveTexture(GL_TEXTURE2);
	if (mtl->specular_map != NULL)
		tmp = mtl->specular_map->handle;
	else
		tmp = 0;
	glBindTexture(GL_TEXTURE_2D, tmp);
	glUniform1i(shader->loc[8], 2);
	glUniform3fv(shader->loc[11], 1, (float*)&(mtl->specular_color));
	glUniform1i(shader->loc[12], mtl->specular_exp);
	(void)scop;
	(void)obj;
}

const t_shader_def	g_shader_def[] = {
	SHADER_DEF("test.glsl", &test_glsl_pre, &test_glsl_mtl, ((char*[]){
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
	SHADER_DEF_END()
};

/*
** ========================================================================== **
** Render obj
*/

void			render_obj(t_scop *scop, t_obj *obj)
{
	int			i;
	int			offset;

	glUseProgram(obj->shader->handle);
	obj->shader->pre(obj->shader, scop, obj);
	glBindVertexArray(obj->mesh->vao);
	offset = 0;
	i = -1;
	while (++i < obj->mesh->mtl_count)
	{
		obj->shader->mtl(obj->shader, scop, obj, obj->mesh->mtl[i]);
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
