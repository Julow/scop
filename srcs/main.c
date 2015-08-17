/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 13:54:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/17 19:16:13 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <stdlib.h>

const float		test_vertices[] = {
	0.5f, 0.5f, 0.0f,		1.0f, 0.0f, 0.0f,		1.0f, 1.0f,
	0.5f, -0.5f, 0.0f,		0.0f, 1.0f, 0.0f,		1.0f, 0.0f,
	-0.5f, -0.5f, 0.0f,		0.0f, 0.0f, 1.0f,		0.0f, 0.0f,
	-0.5f, 0.5f, 0.0f,		0.0f, 0.0f, 0.0f,		0.0f, 1.0f
};

const t_uint	test_indices[] = {
	0, 1, 3,
	1, 2, 3
};

static void		draw_background(void)
{
	glClearColor(0.6f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

static void		draw_mesh(t_mesh *mesh)
{
	glBindVertexArray(mesh->vao);
	glDrawElements(GL_TRIANGLES, mesh->count, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

static void		draw_obj(t_obj *obj)
{
	glBindTexture(GL_TEXTURE_2D, obj->texture->handle);
	draw_mesh(obj->mesh);
}

static t_obj	create_obj(t_mesh *mesh, t_texture *texture)
{
	return ((t_obj){mesh, texture});
}

static t_bool	create_texture(char const *file, t_texture *texture)
{
	t_img			img;

	if (!ft_loadimage(file, &img))
		return (ft_fdprintf(2, "Error: Cannot load textures\n"), false);
	glGenTextures(1, &(texture->handle));
	glBindTexture(GL_TEXTURE_2D, texture->handle);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.width, img.height, 0, GL_BGRA,
		GL_UNSIGNED_BYTE, img.data);
	glGenerateMipmap(GL_TEXTURE_2D);
	free(img.data);
	glBindTexture(GL_TEXTURE_2D, 0);
	return (true);
}

static t_bool	create_test_obj(t_scop *scop)
{
	if (!create_texture("res/wall.tga", &(scop->test_texture)))
		return (false);
	scop->test_mesh = create_mesh((t_mesh_params){
		.vertices = test_vertices,
		.vertice_size = sizeof(test_vertices),
		.indices = test_indices,
		.indice_size = sizeof(test_indices)
	});
	scop->test_obj = create_obj(&(scop->test_mesh), &(scop->test_texture));
	return (true);
}

int				main(void)
{
	t_scop			scop;

	if (!init_window(&scop))
		return (ft_fdprintf(2, "Error: Cannot init window\n"), 1);
	init_callback(&scop);
	if (!create_shader("res/shaders/test.vert", "res/shaders/test.frag",
		&(scop.test_shaders)))
		return (ft_fdprintf(2, "Error: Cannot load shaders\n"), 1);
	if (!create_test_obj(&scop))
		return (ft_fdprintf(2, "lol\n"), 1);
	while (!glfwWindowShouldClose(scop.window))
	{
		glfwPollEvents();
		draw_background();
		glUseProgram(scop.test_shaders);
		draw_obj(&(scop.test_obj));
		glfwSwapBuffers(scop.window);
	}
	return (glfwTerminate(), 0);
}
