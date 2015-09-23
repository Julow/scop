/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 08:47:58 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/23 18:58:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_EVENTS_H
# define KEY_EVENTS_H

# include "scop.h"
# include "gl.h"

# define F_KEY_CALLBACK		(1 << 1)
# define F_KEY_FLAG			(1 << 2)

# define K_MOUSE_CALLBACK	(-1)
# define K_END				(-2)

struct			s_key_event
{
	int				key_code;
	int				flags;
	t_ulong			action;
};

/*
** Set a flag on key down and unset it on key up
** 'action' is dst_offset << 32 | flags
** (Not available for mouse events)
*/
# define E_KEY_FLAG(k,s,n,f)	(t_key_event){k,F_KEY_FLAG,_E_KEY_FLAG(s,n)|f}
# define _E_KEY_FLAG(s,n)		(offsetof(s,n)<<32)

/*
** Call 'f' on key up
** f(void *env, int key_code)
*/
# define E_KEY_CALLBACK(k,f)	(t_key_event){k,F_KEY_CALLBACK,(t_ulong)f}

/*
** Call 'f' on mouse move
** f(void *env, double x, double y)
*/
# define E_MOUSE_MOVE(f)		(t_key_event){K_MOUSE_CALLBACK,0,(t_ulong)f}

/*
** To be set a the end of g_events
*/
# define E_END()				(t_key_event){K_END,0,0}

/*
** extern g_key_events have to be implemented
*/
extern t_key_event const		g_events[];

/*
** Init events
*/
void			init_events(GLFWwindow *window, void *scop);

#endif
