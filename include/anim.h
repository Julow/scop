/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 19:10:10 by juloo             #+#    #+#             */
/*   Updated: 2015/09/27 19:17:57 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIM_H
# define ANIM_H

# include "scop.h"

/*
** Animation
** TODO: smooth
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
};

/*
** Create an anim
** -
** d		duration (in ms)
** f		flags
** c		callback
*/
# define ANIM(d,f,c)			((t_anim){0, d, f, (void(*)(void*,float))c})

/*
** Update an anim
*/
void			anim_update(void *env, t_anim *anim, t_ulong now);

/*
** Init an anim
*/
void			anim_start(t_anim *anim);

#endif
