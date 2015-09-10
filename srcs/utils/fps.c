/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 18:27:37 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/10 18:27:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_fps			fps_init(t_uint update_interval)
{
	t_ulong const	now = ft_clock(0);

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
t_bool			fps_end(t_fps *fps)
{
	t_ulong			t;

	t = ft_clock(0);
	fps->elapsed = t - fps->last_frame;
	fps->last_frame = t;
	fps->frames_time += t - fps->frame_start;
	t -= fps->last_update;
	fps->frames++;
	if (t >= fps->update_interval)
	{
		fps->average_time = fps->frames_time / fps->frames;
		fps->average_fps = ((t_ulong)fps->frames) * MICRO_SEC / t;
		fps->frames = 0;
		fps->frames_time = 0;
		fps->last_update += t;
		return (true);
	}
	return (false);
}
