/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 14:10:42 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/15 14:36:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static t_scop	*save_env(t_scop *scop)
{
	static t_scop	*save = NULL;

	if (scop != NULL)
		save = scop;
	return (save);
}

static void		key_callback(GLFWwindow* window, int key, int scancode,
		int action, int mode)
{
	ft_printf("key event key=%d; scancode=%d; action=%d; mode=%d;\n",
		key, scancode, action, mode);
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

void			init_callback(t_scop *scop)
{
	save_env(scop);
	glfwSetKeyCallback(scop->window, &key_callback);
}