/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 13:54:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/25 17:31:03 by jaguillo         ###   ########.fr       */
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

static t_bool	create_test_obj(t_scop *scop)
{
	if (!load_texture("res/tga/container.tga", &(scop->test_texture)))
		return (false);
	if (!load_mesh("res/obj/42.obj", &(scop->test_mesh)))
		return (ft_fdprintf(2, "Error: Cannot load obj"), 1);
	scop->test_obj = ((t_obj){&(scop->test_mesh), &(scop->test_texture), &(scop->test_shaders)});
	return (true);
}

int				main(void)
{
	t_scop			scop;

	if (!init_window(&scop))
		return (ft_fdprintf(2, "Error: Cannot init window\n"), 1);
	init_key_events(&scop);
	if (!load_shader("res/shaders/test.vert", "res/shaders/test.frag",
		&(scop.test_shaders)))
		return (ft_fdprintf(2, "Error: Cannot load shaders\n"), 1);
	if (!create_test_obj(&scop))
		return (ft_fdprintf(2, "lol\n"), 1);
	// -
	t_mat4				view_m, projection_m;

	view_m = ft_mat4identity();
	projection_m = ft_mat4perspective(PERSPECTIVE_FOV, WIN_RATIO,
		PERSPECTIVE_NEAR, PERSPECTIVE_FAR);
	while (!glfwWindowShouldClose(scop.window))
	{
		glfwPollEvents();
		draw_background();
		glUseProgram(scop.test_shaders.handle);
//
		t_mat4			m;

		m = ft_mat4identity();
		ft_mat4translate(&m, VEC3(0.f, 0.f, -3.f));
		ft_mat4scale(&m, VEC3(0.5f, 0.5f, 0.5f));
		// ft_mat4rotate(&m, VEC3(0.f, M_PI / -2.f, 0.f));
		float rot = ((float)(ft_clock(0) % 5000000)) / 5000000.f * M_PI * 2.f;
		ft_mat4rotate(&m, VEC3(rot, rot, rot));
		// ft_mat4rotate(&m, VEC3(0.f, -M_PI / 2 + ((float)(ft_clock(0) % 1000000)) / 1000000.f, 0.f));
		glUniformMatrix4fv(scop.test_shaders.model_loc, 1, GL_TRUE, (float*)&m);
		glUniformMatrix4fv(scop.test_shaders.view_loc, 1, GL_TRUE, (float*)&view_m);
		glUniformMatrix4fv(scop.test_shaders.projection_loc, 1, GL_TRUE, (float*)&projection_m);
//
		draw_obj(&(scop.test_obj));
		glfwSwapBuffers(scop.window);
	}
	return (glfwTerminate(), 0);
}
