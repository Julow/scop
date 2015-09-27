/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 19:10:10 by juloo             #+#    #+#             */
/*   Updated: 2015/09/28 00:06:08 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIM_H
# define ANIM_H

# include "scop.h"

/*
** Animation
*/

# define F_ANIM_END				(1 << 1)
# define F_ANIM_REPEAT			(1 << 2)
# define F_ANIM_REPEAT_REV		(1 << 3)

# define F_ANIM_ONREPEAT_REV	(1 << 4)

struct			s_anim
{
	t_ulong			start_time;
	float			duration;
	int				flags;
	void			(*callback)(void *env, float delta);
	float			(*smooth)(float delta);
};

/*
** Create an anim
** -
** d		duration (in ms)
** f		flags
** c		callback
** s		smooth function
*/
# define ANIM(d,f,c,s)			((t_anim){0,d,f,(void(*)(void*,float))c,s})

/*
** Update an anim
*/
void			anim_update(void *env, t_anim *anim, t_ulong now);

/*
** Init an anim
*/
void			anim_start(t_anim *anim);

/*
** Smooths
*/
float			smooth_linear(float delta);

float			smooth_in(float delta);
float			smooth_out(float delta);
float			smooth_in_out(float delta);

float			smooth_elastic(float delta);

float			smooth_bounce(float delta);

float			smooth_back_in(float delta);
float			smooth_back_out(float delta);
float			smooth_back_in_out(float delta);

#endif
