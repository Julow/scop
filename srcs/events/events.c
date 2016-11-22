/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 11:52:01 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/22 12:16:19 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/gl.h"

#include "events.h"
#include "utils.h"

static void		key_callback(GLFWwindow *window, int key, int scancode,
		int action)
{
	int				i;
	void *const		env = glfwGetWindowUserPointer(window);

	i = -1;
	while (g_events[++i].key_code != K_END)
	{
		if (g_events[i].key_code != key)
			continue ;
		if (g_events[i].flags & F_KEY_CALLBACK && action == GLFW_RELEASE)
			((void(*)())g_events[i].action)(env, key);
		else if (g_events[i].flags & F_KEY_FLAG && action == GLFW_RELEASE)
			(*(int*)(env + (g_events[i].action >> 32))) &=
				~(g_events[i].action & 0xFFFFFFFF);
		else if (g_events[i].flags & F_KEY_FLAG && action == GLFW_PRESS)
			(*(int*)(env + (g_events[i].action >> 32))) |=
				g_events[i].action & 0xFFFFFFFF;
	}
	(void)scancode;
}

static void		mouse_move_callback(GLFWwindow *window, double x, double y)
{
	int				i;

	i = -1;
	while (g_events[++i].key_code != K_END)
		if (g_events[i].key_code == K_MOUSE_CALLBACK)
			((void(*)())g_events[i].action)(glfwGetWindowUserPointer(window),
				x, y);
}

void			init_events(GLFWwindow *window)
{
	glfwSetKeyCallback(window, V(&key_callback));
	glfwSetCursorPosCallback(window, &mouse_move_callback);
}
