/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/09 18:45:57 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/23 18:54:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h" // TODO: move
#include "motions.h"
#include <math.h>

static void		move_front(t_vec2 dir, t_vec3 *move, float inv)
{
	float			sin_pitch;

	sin_pitch = sinf(dir.y) * inv;
	move->y += sin_pitch;
	sin_pitch = (1.f - ABS(sin_pitch)) * inv;
	move->z += sinf(dir.x) * sin_pitch;
	move->x += cosf(dir.x) * sin_pitch;
}

static void		move_lateral(t_vec2 dir, t_vec3 *move, float inv)
{
	move->z += sinf(dir.x - (M_PI / 2.f)) * inv;
	move->x += cosf(dir.x - (M_PI / 2.f)) * inv;
}

static void		move_vertical(t_vec2 dir, t_vec3 *move, float inv)
{
	move->y += 1.f * inv;
	(void)dir;
}

static t_motion_def const	g_moves[] = {
	{FLAG_MOVE_FRONT, &move_front, -1.f},
	{FLAG_MOVE_BACK, &move_front, 1.f},
	{FLAG_MOVE_RIGHT, &move_lateral, -1.f},
	{FLAG_MOVE_LEFT, &move_lateral, 1.f},
	{FLAG_MOVE_DOWN, &move_vertical, -1.f},
	{FLAG_MOVE_UP, &move_vertical, 1.f}
};

t_bool			handle_key_hold(t_scop *scop, float elapsed, t_vec3 *pos)
{
	t_vec3			move;
	int				length;
	int				i;

	if (scop->flags == 0)
		return (false);
	move = VEC3_0();
	if (scop->flags & FLAG_ACCELERATE)
		elapsed *= ACCELERATION;
	length = 0;
	i = -1;
	while (++i < G_ARRAY_LEN(g_moves))
		if (scop->flags & g_moves[i].flag)
		{
			g_moves[i].f(scop->camera.look, &move, g_moves[i].inv);
			length++;
		}
	if (length == 0)
		return (false);
	pos->x = move.x * elapsed * MOVE_SPEED / (float)length;
	pos->y = move.y * elapsed * MOVE_SPEED / (float)length;
	pos->z = move.z * elapsed * MOVE_SPEED / (float)length;
	return (true);
}

t_bool			handle_cursor_move(t_scop *scop, t_vec2 *look)
{
	double			x;
	double			y;

	if (!(scop->flags & FLAG_CURSOR_MOVE))
		return (false);
	glfwGetCursorPos(scop->window, &x, &y);
	x = fmod(x / WIN_WIDTH * CURSOR_SPEED, M_PI * 2.0);
	y = fmod(y / WIN_HEIGHT * CURSOR_SPEED, M_PI * 2.0);
	scop->flags &= ~FLAG_CURSOR_MOVE;
	*look = VEC2((float)x, (float)y);
	return (true);
}
