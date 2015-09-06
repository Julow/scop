/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 11:52:01 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/07 00:56:58 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "utils.h"
#include "gl.h"

/*
** Call a callback on key up
** 'action' is a function (t_scop *scop, int key_code)
*/
# define KEY_CALLBACK		(1 << 1)
/*
** Set a flag on key down and unset it on key up
** 'action' is dst_offset << 32 | flags
*/
# define KEY_FLAG			(1 << 2)

typedef struct	s_key_event
{
	int				key_code;
	int				flags;
	t_ulong			action;
}				t_key_event;

# define KEY_EVENT(k,t,s,n,f)	((t_key_event){k,t,(offsetof(s,n)<<32)|f})

static t_key_event const	g_events[] = {
	KEY_EVENT(GLFW_KEY_W, KEY_FLAG, t_scop, flags, FLAG_MOVE_FRONT),
	KEY_EVENT(GLFW_KEY_D, KEY_FLAG, t_scop, flags, FLAG_MOVE_LEFT),
	KEY_EVENT(GLFW_KEY_S, KEY_FLAG, t_scop, flags, FLAG_MOVE_BACK),
	KEY_EVENT(GLFW_KEY_A, KEY_FLAG, t_scop, flags, FLAG_MOVE_RIGHT),
	KEY_EVENT(GLFW_KEY_UP, KEY_FLAG, t_scop, flags, FLAG_ROT_UP),
	KEY_EVENT(GLFW_KEY_RIGHT, KEY_FLAG, t_scop, flags, FLAG_ROT_RIGHT),
	KEY_EVENT(GLFW_KEY_DOWN, KEY_FLAG, t_scop, flags, FLAG_ROT_DOWN),
	KEY_EVENT(GLFW_KEY_LEFT, KEY_FLAG, t_scop, flags, FLAG_ROT_LEFT),
	KEY_EVENT(GLFW_KEY_LEFT_CONTROL, KEY_FLAG, t_scop, flags, FLAG_ACCELERATE),
	KEY_EVENT(GLFW_KEY_LEFT_SHIFT, KEY_FLAG, t_scop, flags, FLAG_MOVE_DOWN),
	KEY_EVENT(GLFW_KEY_SPACE, KEY_FLAG, t_scop, flags, FLAG_MOVE_UP),
};

static void		*save_env(t_scop *scop)
{
	static t_scop	*save = NULL;

	if (scop != NULL)
		save = scop;
	return (save);
}

static void		key_callback(GLFWwindow *window, int key, int scancode,
		int action, int mode)
{
	int				i;

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	i = -1;
	while (++i < G_ARRAY_LEN(g_events))
	{
		if (g_events[i].key_code != key)
			continue ;
		if (g_events[i].flags & KEY_CALLBACK && action == GLFW_RELEASE)
			((void(*)())g_events[i].action)(save_env(NULL), key);
		else if (g_events[i].flags & KEY_FLAG && action == GLFW_RELEASE)
			(*(int*)(save_env(NULL) + (g_events[i].action >> 32))) &= ~(g_events[i].action & 0xFFFFFFFF);
		else if (g_events[i].flags & KEY_FLAG && action == GLFW_PRESS)
			(*(int*)(save_env(NULL) + (g_events[i].action >> 32))) |= g_events[i].action & 0xFFFFFFFF;
	}
	// ft_printf("key event key=%d; scancode=%d; action=%d; mode=%d;\n",
	// 	key, scancode, action, mode);
	(void)scancode;
	(void)mode;
}

void			init_key_events(t_scop *scop)
{
	save_env(scop);
	glfwSetKeyCallback(scop->window, &key_callback);
}
