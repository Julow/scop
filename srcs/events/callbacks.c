/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 19:10:51 by jaguillo          #+#    #+#             */
/*   Updated: 2015/10/01 17:57:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			on_mouse_move(GLFWwindow *window, double x, double y)
{
	t_scop *const	scop = glfwGetWindowUserPointer(window);

	scop->flags |= FLAG_CURSOR_MOVE;
	(void)x;
	(void)y;
}

void			on_esc(GLFWwindow *window, int key_code)
{
	glfwSetWindowShouldClose(window, GL_TRUE);
	(void)key_code;
}
