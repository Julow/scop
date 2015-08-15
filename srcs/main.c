/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 13:54:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/15 15:11:34 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void		draw(t_scop *scop)
{
	glClearColor(0.6f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	(void)scop;
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
	while (!glfwWindowShouldClose(scop.window))
	{
		glfwPollEvents();
		draw(&scop);
		glfwSwapBuffers(scop.window);
	}
	return (glfwTerminate(), 0);
}
