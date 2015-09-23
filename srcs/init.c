/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 19:10:14 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/23 19:10:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "scop.h"
#include "events.h"

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
