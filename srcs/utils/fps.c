/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 18:27:37 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/21 17:53:13 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_fps			fps_init(uint32_t update_interval)
{
	uint64_t const	now = ft_clock(0);

	return ((t_fps){now, now, 0, 0, update_interval, 0, 0, 0, 0});
}

/*
** Start of a frame
*/

void			fps_start(t_fps *fps)
{
	fps->frame_start = ft_clock(0);
}

/*
** Start of a frame
** Return true every fps->update_interval
*/

bool			fps_end(t_fps *fps)
{
	uint64_t			t;

	t = ft_clock(0);
	fps->elapsed = t - fps->last_frame;
	fps->last_frame = t;
	fps->frames_time += t - fps->frame_start;
	t -= fps->last_update;
	fps->frames++;
	if (t >= fps->update_interval)
	{
		fps->average_time = fps->frames_time / fps->frames;
		fps->average_fps = ((uint64_t)fps->frames) * T_SEC / t;
		fps->frames = 0;
		fps->frames_time = 0;
		fps->last_update += t;
		return (true);
	}
	return (false);
}
