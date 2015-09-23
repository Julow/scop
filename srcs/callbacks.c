/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 19:10:51 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/23 19:11:01 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			on_mouse_move(t_scop *env, double x, double y)
{
	env->flags |= FLAG_CURSOR_MOVE;
	(void)x;
	(void)y;
}

void			on_esc(t_scop *env, int key_code)
{
	glfwSetWindowShouldClose(env->window, GL_TRUE);
	(void)key_code;
}
