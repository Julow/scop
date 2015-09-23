/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 11:52:01 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/23 18:50:07 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "utils.h"
#include "gl.h"

static void		*save_env(void *env)
{
	static void	*save = NULL;

	if (env != NULL)
		save = env;
	return (save);
}

static void		key_callback(GLFWwindow *window, int key, int scancode,
		int action, int mode)
{
	int				i;

	i = -1;
	while (g_events[++i].key_code != K_END)
	{
		if (g_events[i].key_code != key)
			continue ;
		if (g_events[i].flags & F_KEY_CALLBACK && action == GLFW_RELEASE)
			((void(*)())g_events[i].action)(save_env(NULL), key);
		else if (g_events[i].flags & F_KEY_FLAG && action == GLFW_RELEASE)
			(*(int*)(save_env(NULL) + (g_events[i].action >> 32))) &=
				~(g_events[i].action & 0xFFFFFFFF);
		else if (g_events[i].flags & F_KEY_FLAG && action == GLFW_PRESS)
			(*(int*)(save_env(NULL) + (g_events[i].action >> 32))) |=
				g_events[i].action & 0xFFFFFFFF;
	}
	(void)window;
	(void)scancode;
	(void)mode;
}

static void		mouse_move_callback(GLFWwindow *window, double x, double y)
{
	int				i;

	i = -1;
	while (g_events[++i].key_code != K_END)
		if (g_events[i].key_code == K_MOUSE_CALLBACK)
			((void(*)())g_events[i].action)(save_env(NULL), x, y);
	(void)window;
}

void			init_events(GLFWwindow *window, void *env)
{
	save_env(env);
	glfwSetKeyCallback(window, &key_callback);
	glfwSetCursorPosCallback(window, &mouse_move_callback);
}
