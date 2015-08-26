/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 13:54:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/26 03:29:43 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "utils.h"
#include <stdlib.h>
#include <math.h>

/*
** res
*/
typedef enum	e_res_t
{
	res_shader,
	res_texture,
	res_mesh,
	res_t_count
}				t_res_t;

typedef struct	s_res
{
	t_res_t			type;
	t_sub			name;
}				t_res;

typedef struct	s_res_shader
{
	t_res			res;
	char const		*vert_file;
	char const		*frag_file;
}				t_res_shader;

typedef struct	s_res_texture
{
	t_res			res;
	char const		*file;
}				t_res_texture;

typedef struct	s_res_mesh
{
	t_res			res;
	char const		*file;
}				t_res_mesh;

#define SHADERS_DIR		"res/shaders/"
#define TEXTURES_DIR	"res/tga/"
#define MESHES_DIR		"res/obj/"

#define RES(t,n,...)		((t_res*)&(t_res_##t){{res_##t,n},##__VA_ARGS__})

#define RES_SHADER(n,v,f)	RES(shader, SUBC(n), SHADERS_DIR v, SHADERS_DIR f)
#define RES_TEXTURE(n,f)	RES(texture, SUBC(n), TEXTURES_DIR f)
#define RES_MESH(n,f)		RES(mesh, SUBC(n), MESHES_DIR f)

static t_res const *const	g_ressources[] = {
	RES_SHADER(	"test",			"test.vert",		"test.frag"),

	RES_TEXTURE("container",	"container.tga"),
	RES_TEXTURE("wall",			"wall.tga"),

	RES_MESH(	"42",			"42.obj"),
	RES_MESH(	"cube",			"cube.obj"),
	RES_MESH(	"rect",			"rect.obj"),
	RES_MESH(	"teapot",		"teapot.obj"),
	RES_MESH(	"teapot2",		"teapot2.obj")
};

t_bool			shader_res_loader(void *dst, t_res_shader const *res)
{
	return (load_shader(res->vert_file, res->frag_file, dst));
}

t_bool			texture_res_loader(void *dst, t_res_texture const *res)
{
	return (load_texture(res->file, dst));
}

t_bool			mesh_res_loader(void *dst, t_res_mesh const *res)
{
	return (load_mesh(res->file, dst));
}

typedef struct	s_res_config
{
	t_bool			(*const loader)();
	int				res_size;
}				t_res_config;

static const t_res_config	res_conf[] = {
	{&shader_res_loader, sizeof(t_shader)},
	{&texture_res_loader, sizeof(t_texture)},
	{&mesh_res_loader, sizeof(t_mesh)}
};

/*
** Search for a ressource with type 'type' and name 'name'
** Ressources are cached (loaded once)
** Return NULL if not found or if an error occur
*/
void const		*get_res(t_res_t type, t_sub name)
{
	static t_hmap	*res_caches[res_t_count] = {NULL};
	void			*res;
	int				i;

	if (type >= res_t_count)
		return (NULL);
	if (res_caches[type] == NULL)
		res_caches[type] = ft_hmapnew(10, &ft_djb2);
	if ((res = ft_hmapget(res_caches[type], name)) != NULL)
		return (res);
	i = -1;
	while (++i < G_ARRAY_LEN(g_ressources))
		if (g_ressources[i]->type == type
			&& g_ressources[i]->name.length == name.length
			&& MEM_EQU(g_ressources[i]->name.str, name.str, name.length))
		{
			res = ft_hmapput(res_caches[type], name, NULL,
				res_conf[type].res_size);
			if (!res_conf[type].loader(res, g_ressources[i]))
				ft_hmaprem(res_caches[type], name, (res = NULL));
			return (res);
		}
	return (NULL);
}
/*
** -
*/

t_bool			create_obj(t_obj *dst, t_sub mesh, t_sub texture, t_sub shader)
{
	if ((dst->mesh = get_res(res_mesh, mesh)) == NULL
		|| (dst->texture = get_res(res_texture, texture)) == NULL
		|| (dst->shader = get_res(res_shader, shader)) == NULL)
		return (false);
	return (true);
}

static void		draw_background(void)
{
	glClearColor(0.f, 0.6f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

static void		draw_obj(t_obj *obj)
{
	glUseProgram(obj->shader->handle);
	glBindTexture(GL_TEXTURE_2D, obj->texture->handle);
	glBindVertexArray(obj->mesh->vao);
	glDrawElements(GL_TRIANGLES, obj->mesh->count, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

/*
** -
*/
#define FPS_INTERVAL		100000
#define MICRO_SEC			1000000
#define NANO_SEC			1000000000

#include <time.h>

static t_ulong	ft_clock_ns(void)
{
	struct timespec	spec;

	clock_gettime(CLOCK_MONOTONIC, &spec);
	return (spec.tv_sec * NANO_SEC + spec.tv_nsec);
}
/*
** -
*/

int				main(void)
{
	t_scop			scop;

	if (!init_window(&scop))
		return (ft_fdprintf(2, "Error: Cannot init window\n"), 1);
	init_key_events(&scop);
	if (!create_obj(&(scop.test_obj), SUBC("42"), SUBC("wall"), SUBC("test")))
		return (ft_fdprintf(2, "lol\n"), 1);
	// -
	t_mat4				view_m, projection_m;
	int					frames = 0;
	t_ulong				last_fps = ft_clock(0);

	view_m = ft_mat4identity();
	ft_mat4translate(&view_m, VEC3(0.f, 0.f, -5.f));
	projection_m = ft_mat4perspective(PERSPECTIVE_FOV, WIN_RATIO,
		PERSPECTIVE_NEAR, PERSPECTIVE_FAR);
	while (!glfwWindowShouldClose(scop.window))
	{
		t_ulong			tmp = ft_clock(0);
		if ((tmp - last_fps) >= FPS_INTERVAL)
		{
			ft_printf("FPS: %-4d\r", frames * 1000000 / (tmp - last_fps));
			last_fps = tmp;
			frames = 0;
		}
		frames++;
		glfwPollEvents();
		draw_background();
//
		t_mat4			m;

		m = ft_mat4identity();
		float progress = cosf(((float)(tmp % 5000000)) / 2500000.f * M_PI);
		ft_mat4translate(&m, VEC3(0.f, 0.f, 0.f));
		float scale = progress / M_PI + 0.5f;
		ft_mat4scale(&m, VEC3(scale, scale, scale));
		float rot = progress * 2.f;
		ft_mat4rotate(&m, VEC3(rot - M_PI, rot - M_PI, rot));
		glUniformMatrix4fv(scop.test_obj.shader->model_loc, 1, GL_TRUE, (float*)&m);
		glUniformMatrix4fv(scop.test_obj.shader->view_loc, 1, GL_TRUE, (float*)&view_m);
		glUniformMatrix4fv(scop.test_obj.shader->projection_loc, 1, GL_TRUE, (float*)&projection_m);
//
		draw_obj(&(scop.test_obj));
		glfwSwapBuffers(scop.window);
	}
	return (glfwTerminate(), 0);
}
