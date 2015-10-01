/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 11:52:01 by jaguillo          #+#    #+#             */
/*   Updated: 2015/10/01 17:59:21 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "events.h"
#include "utils.h"
#include "gl.h"

t_key_event const		g_events[] = {
	E_KEY_FLAG(GLFW_KEY_W, t_scop, flags, FLAG_MOVE_FRONT),
	E_KEY_FLAG(GLFW_KEY_W, t_scop, flags, FLAG_MOVE_FRONT),
	E_KEY_FLAG(GLFW_KEY_D, t_scop, flags, FLAG_MOVE_LEFT),
	E_KEY_FLAG(GLFW_KEY_S, t_scop, flags, FLAG_MOVE_BACK),
	E_KEY_FLAG(GLFW_KEY_A, t_scop, flags, FLAG_MOVE_RIGHT),
	E_KEY_FLAG(GLFW_KEY_LEFT_CONTROL, t_scop, flags, FLAG_ACCELERATE),
	E_KEY_FLAG(GLFW_KEY_LEFT_SHIFT, t_scop, flags, FLAG_MOVE_DOWN),
	E_KEY_FLAG(GLFW_KEY_SPACE, t_scop, flags, FLAG_MOVE_UP),
	E_KEY_CALLBACK(GLFW_KEY_ESCAPE, &on_esc),
	E_MOUSE_MOVE(&on_mouse_move),
	E_END()
};

static void		key_callback(GLFWwindow *window, int key, int scancode,
		int action, int mode)
{
	int				i;
	void *const		env = glfwGetWindowUserPointer(window);

	i = -1;
	while (g_events[++i].key_code != K_END)
	{
		if (g_events[i].key_code != key)
			continue ;
		if (g_events[i].flags & F_KEY_CALLBACK && action == GLFW_RELEASE)
			((void(*)())g_events[i].action)(window, key);
		else if (g_events[i].flags & F_KEY_FLAG && action == GLFW_RELEASE)
			(*(int*)(env + (g_events[i].action >> 32))) &=
				~(g_events[i].action & 0xFFFFFFFF);
		else if (g_events[i].flags & F_KEY_FLAG && action == GLFW_PRESS)
			(*(int*)(env + (g_events[i].action >> 32))) |=
				g_events[i].action & 0xFFFFFFFF;
	}
	(void)scancode;
	(void)mode;
}

static void		mouse_move_callback(GLFWwindow *window, double x, double y)
{
	int				i;

	i = -1;
	while (g_events[++i].key_code != K_END)
		if (g_events[i].key_code == K_MOUSE_CALLBACK)
			((void(*)())g_events[i].action)(window, x, y);
}

void			init_events(GLFWwindow *window)
{
	glfwSetKeyCallback(window, &key_callback);
	glfwSetCursorPosCallback(window, &mouse_move_callback);
}
