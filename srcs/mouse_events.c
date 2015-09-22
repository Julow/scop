/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 16:26:07 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/22 08:12:22 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gl.h"
#include "main.h"
#include "scop.h"

static void		*save_env(t_scop *scop)
{
	static t_scop	*save = NULL;

	if (scop != NULL)
		save = scop;
	return (save);
}

static void		mouse_callback(GLFWwindow *window, double x, double y)
{
	t_scop			*const scop = save_env(NULL);

	scop->flags |= FLAG_CURSOR_MOVE;
	(void)window;
	(void)x;
	(void)y;
}

void			init_mouse_events(t_scop *scop)
{
	save_env(scop);
	glfwSetCursorPosCallback(scop->window, &mouse_callback);
}
