/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 13:54:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/15 19:35:56 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

const float		test_vertices[] = {
	0.5f, 0.5f, 0.0f,	1.0f, 0.0f, 0.0f,
	0.5f, -0.5f, 0.0f,	0.0f, 1.0f, 0.0f,
	-0.5f, -0.5f, 0.0f,	0.0f, 0.0f, 1.0f,
	-0.5f, 0.5f, 0.0f,	0.0f, 0.0f, 0.0f
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

int				main(void)
{
	t_scop			scop;

	if (!init_window(&scop))
		return (ft_fdprintf(2, "Error: Cannot init window\n"), 1);
	init_callback(&scop);
	if (!create_shader("res/shaders/test.vert", "res/shaders/test.frag",
		&(scop.test_shaders)))
		return (ft_fdprintf(2, "Error: Cannot load shaders\n"), 1);
	scop.test_mesh = create_mesh((t_mesh_params){
		.vertices = test_vertices,
		.vertice_size = sizeof(test_vertices),
		.indices = test_indices,
		.indice_size = sizeof(test_indices)
	});
	while (!glfwWindowShouldClose(scop.window))
	{
		glfwPollEvents();
		draw_background();
		glUseProgram(scop.test_shaders);
		draw_mesh(&(scop.test_mesh));
		glfwSwapBuffers(scop.window);
	}
	return (glfwTerminate(), 0);
}
