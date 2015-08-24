/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 13:54:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/24 19:27:21 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <stdlib.h>
#include <math.h>

static void		draw_background(void)
{
	glClearColor(0.f, 0.6f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

static void		draw_obj(t_obj *obj)
{
	glBindTexture(GL_TEXTURE_2D, obj->texture->handle);
	glBindVertexArray(obj->mesh->vao);
	glDrawElements(GL_TRIANGLES, obj->mesh->count, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
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
	if (!create_texture("res/tga/container.tga", &(scop->test_texture)))
		return (false);
	if (!ft_loadmesh("res/obj/42.obj", &(scop->test_mesh)))
		return (ft_fdprintf(2, "Error: Cannot load obj"), 1);
	scop->test_obj = ((t_obj){&(scop->test_mesh), &(scop->test_texture)});
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
	scop.test_mat_loc = glGetUniformLocation(scop.test_shaders, "test_mat");
	while (!glfwWindowShouldClose(scop.window))
	{
		glfwPollEvents();
		draw_background();
		glUseProgram(scop.test_shaders);
//
		t_mat4			m;

		ft_mat4identity(&m);
		ft_mat4translate(&m, VEC3(0.f, 0.f, 0.f));
		ft_mat4rotate(&m, VEC3(0.f, -M_PI / 2, 0.f));
		ft_mat4scale(&m, VEC3(0.5f, 0.5f, 0.5f));
		glUniformMatrix4fv(scop.test_mat_loc, 1, GL_TRUE, (float*)&m);
//
		draw_obj(&(scop.test_obj));
		glfwSwapBuffers(scop.window);
	}
	return (glfwTerminate(), 0);
}
