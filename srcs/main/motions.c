/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 12:24:00 by juloo             #+#    #+#             */
/*   Updated: 2017/01/28 18:57:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "motions.h"

#include <math.h>

static t_motion_def const	g_moves[] = {
	{FLAG_MOVE_FRONT, VEC3(0.f, 0.f, -1.f)},
	{FLAG_MOVE_BACK, VEC3(0.f, 0.f, 1.f)},
	{FLAG_MOVE_RIGHT, VEC3(-1.f, 0.f, 0.f)},
	{FLAG_MOVE_LEFT, VEC3(1.f, 0.f, 0.f)},
	{FLAG_MOVE_DOWN, VEC3(0.f, -1.f, 0.f)},
	{FLAG_MOVE_UP, VEC3(0.f, 1.f, 0.f)},
};

static uint32_t	get_dir(uint32_t flags, t_vec3 *dst)
{
	uint32_t		i;
	uint32_t		length;

	*dst = VEC3_0();
	length = 0;
	i = 0;
	while (i < ARRAY_LEN(g_moves))
	{
		if (flags & g_moves[i].flag)
		{
			*dst = VEC3_ADD(*dst, g_moves[i].dir);
			length++;
		}
		i++;
	}
	return (length);
}

bool			handle_key_hold(t_scop *scop, float elapsed, t_vec3 *dst)
{
	uint32_t		length;
	t_vec3			dir;
	float			delta;

	length = get_dir(scop->flags, &dir);
	if (length == 0)
		return (false);
	delta = (scop->flags & FLAG_ACCELERATE) ? ACCELERATION : 1.f;
	delta *= elapsed * MOVE_SPEED / (float)length;
	dir = VEC3_MUL1(dir, delta);
	ft_mat4apply_vec3(&scop->camera_list.current->c.obj->world_m, &dir, 0.f);
	*dst = VEC3_ADD(*dst, dir);
	return (true);
}

bool			handle_cursor_move(t_scop *scop, t_vec2 *look)
{
	double			x;
	double			y;

	if (!(scop->flags & FLAG_CURSOR_MOVE))
		return (false);
	glfwGetCursorPos(scop->window, &x, &y);
	look->x += fmod((x - scop->cursor.x) / WIN_WIDTH * CURSOR_SPEED,
		M_PI * 2.0);
	look->y += fmod((y - scop->cursor.y) / WIN_HEIGHT * CURSOR_SPEED,
		M_PI * 2.0);
	scop->cursor = VEC2((float)x, (float)y);
	scop->flags &= ~FLAG_CURSOR_MOVE;
	return (true);
}
