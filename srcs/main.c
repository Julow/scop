/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 13:54:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/26 01:45:29 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "utils.h"
#include <stdlib.h>
#include <math.h>

static struct
{
	t_sub			name;
	char const		*vert_file;
	char const		*frag_file;
} const			g_shaders[] = {
	{SUBC("test"), "res/shaders/test.vert", "res/shaders/test.frag"}
};

static struct
{
	t_sub			name;
	char const		*texture_file;
} const			g_textures[] = {
	{SUBC("container"), "res/tga/container.tga"},
	{SUBC("wall"), "res/tga/wall.tga"}
};

static struct
{
	t_sub			name;
	char const		*obj_file;
} const			g_meshes[] = {
	{SUBC("42"), "res/obj/42.obj"},
	{SUBC("cube"), "res/obj/cube.obj"},
	{SUBC("rect"), "res/obj/rect.obj"},
	{SUBC("teapot"), "res/obj/teapot.obj"},
	{SUBC("teapot2"), "res/obj/teapot2.obj"}
};

struct
{
	t_sub			mesh;
	t_sub			texture;
	t_sub			shader;
} const			g_objs[] = {
	{SUBC("42"), SUBC("wall"), SUBC("test")}
};

t_shader const	*get_shader(t_sub name)
{
	static t_hmap	*shader_cache = NULL;
	t_shader		*shader;
	int				i;

	if (shader_cache == NULL)
		shader_cache = ft_hmapnew(5, &ft_djb2);
	if ((shader = ft_hmapget(shader_cache, name)) != NULL)
		return (shader);
	i = -1;
	while (G_ARRAY_NEXT(g_shaders, i))
		if (name.length == g_shaders[i].name.length
			&& MEM_EQU(name.str, g_shaders[i].name.str, name.length))
		{
			shader = ft_hmapput(shader_cache, name, NULL, sizeof(t_shader));
			if (!load_shader(g_shaders[i].vert_file, g_shaders[i].frag_file,
				shader))
				ft_hmaprem(shader_cache, name, NULL);
			else
				return (shader);
		}
	return (NULL);
}

t_texture const	*get_texture(t_sub name)
{
	static t_hmap	*texture_cache = NULL;
	t_texture		*texture;
	int				i;

	if (texture_cache == NULL)
		texture_cache = ft_hmapnew(5, &ft_djb2);
	if ((texture = ft_hmapget(texture_cache, name)) != NULL)
		return (texture);
	i = -1;
	while (G_ARRAY_NEXT(g_textures, i))
		if (name.length == g_textures[i].name.length
			&& MEM_EQU(name.str, g_textures[i].name.str, name.length))
		{
			texture = ft_hmapput(texture_cache, name, NULL, sizeof(t_texture));
			if (!load_texture(g_textures[i].texture_file, texture))
				ft_hmaprem(texture_cache, name, NULL);
			else
				return (texture);
		}
	return (NULL);
}

t_mesh const	*get_mesh(t_sub name)
{
	static t_hmap	*mesh_cache = NULL;
	t_mesh			*mesh;
	int				i;

	if (mesh_cache == NULL)
		mesh_cache = ft_hmapnew(5, &ft_djb2);
	if ((mesh = ft_hmapget(mesh_cache, name)) != NULL)
		return (mesh);
	i = -1;
	while (G_ARRAY_NEXT(g_meshes, i))
		if (name.length == g_meshes[i].name.length
			&& MEM_EQU(name.str, g_meshes[i].name.str, name.length))
		{
			mesh = ft_hmapput(mesh_cache, name, NULL, sizeof(t_mesh));
			if (!load_mesh(g_meshes[i].obj_file, mesh))
				ft_hmaprem(mesh_cache, name, NULL);
			else
				return (mesh);
		}
	return (NULL);
}

t_bool			create_obj(t_obj *dst, t_sub mesh, t_sub texture, t_sub shader)
{
	if ((dst->mesh = get_mesh(mesh)) == NULL
		|| (dst->texture = get_texture(texture)) == NULL
		|| (dst->shader = get_shader(shader)) == NULL)
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

	view_m = ft_mat4identity();
	ft_mat4translate(&view_m, VEC3(0.f, 0.f, -5.f));
	projection_m = ft_mat4perspective(PERSPECTIVE_FOV, WIN_RATIO,
		PERSPECTIVE_NEAR, PERSPECTIVE_FAR);
	while (!glfwWindowShouldClose(scop.window))
	{
		glfwPollEvents();
		draw_background();
//
		t_mat4			m;

		m = ft_mat4identity();
		ft_mat4translate(&m, VEC3(0.f, 0.f, 0.f));
		ft_mat4scale(&m, VEC3(0.5f, 0.5f, 0.5f));
		// ft_mat4rotate(&m, VEC3(0.f, M_PI / -2.f, 0.f));
		float rot = ((float)(ft_clock(0) % 5000000)) / 5000000.f * M_PI * 2.f;
		ft_mat4rotate(&m, VEC3(rot, rot, rot - M_PI));
		// ft_mat4rotate(&m, VEC3(0.f, -M_PI / 2 + ((float)(ft_clock(0) % 1000000)) / 1000000.f, 0.f));
		glUniformMatrix4fv(scop.test_obj.shader->model_loc, 1, GL_TRUE, (float*)&m);
		glUniformMatrix4fv(scop.test_obj.shader->view_loc, 1, GL_TRUE, (float*)&view_m);
		glUniformMatrix4fv(scop.test_obj.shader->projection_loc, 1, GL_TRUE, (float*)&projection_m);
//
		draw_obj(&(scop.test_obj));
		glfwSwapBuffers(scop.window);
	}
	return (glfwTerminate(), 0);
}
