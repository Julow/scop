/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/09 18:45:57 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/09 18:51:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "math_utils.h"
#include <math.h>

void			camera_move(t_camera *camera, t_vec3 pos); // TMP
void			camera_look(t_camera *camera, t_vec2 look); // TMP

void			handle_key_hold(t_scop *scop, float elapsed)
{
	t_vec3			move;
	float			sin_pitch;
	int				length;

	if (scop->flags == 0)
		return ;
	move = VEC3_0();
	if (scop->flags & FLAG_ACCELERATE)
		elapsed *= ACCELERATION;
	length = 0;
	if (scop->flags & FLAG_MOVE_FRONT)
	{
		move.y -= sinf(scop->camera.look.y);
		sin_pitch = 1.f - ABS(move.y);
		move.z -= sinf(scop->camera.look.x) * sin_pitch;
		move.x -= cosf(scop->camera.look.x) * sin_pitch;
		length++;
	}
	if (scop->flags & FLAG_MOVE_BACK)
	{
		move.y += sinf(scop->camera.look.y);
		sin_pitch = 1.f - ABS(move.y);
		move.z += sinf(scop->camera.look.x) * sin_pitch;
		move.x += cosf(scop->camera.look.x) * sin_pitch;
		length++;
	}
	if (scop->flags & FLAG_MOVE_LEFT)
	{
		move.z += sinf(scop->camera.look.x - (M_PI / 2.f));
		move.x += cosf(scop->camera.look.x - (M_PI / 2.f));
		length++;
	}
	if (scop->flags & FLAG_MOVE_RIGHT)
	{
		move.z -= sinf(scop->camera.look.x - (M_PI / 2.f));
		move.x -= cosf(scop->camera.look.x - (M_PI / 2.f));
		length++;
	}
	if (scop->flags & FLAG_MOVE_UP)
	{
		move.y += 1.f;
		length++;
	}
	if (scop->flags & FLAG_MOVE_DOWN)
	{
		move.y -= 1.f;
		length++;
	}
	if (length == 0)
		return ;
	move.x = move.x * elapsed * MOVE_SPEED / (float)length;
	move.y = move.y * elapsed * MOVE_SPEED / (float)length;
	move.z = move.z * elapsed * MOVE_SPEED / (float)length;
	camera_move(&(scop->camera), move);
}

void			handle_cursor_move(t_scop *scop)
{
	double			x;
	double			y;

	if (!(scop->flags & FLAG_CURSOR_MOVE))
		return ;
	glfwGetCursorPos(scop->window, &x, &y);
	x = fmod(x / WIN_WIDTH * CURSOR_SPEED, M_PI * 2.0);
	y = fmod(y / WIN_HEIGHT * CURSOR_SPEED, M_PI * 2.0);
	camera_look(&(scop->camera), VEC2((float)x, (float)y));
	scop->flags &= ~FLAG_CURSOR_MOVE;
}
