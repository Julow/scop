/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 19:10:10 by juloo             #+#    #+#             */
/*   Updated: 2016/11/23 17:10:47 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIM_H
# define ANIM_H

# include "ft/libft.h"

typedef struct s_anim		t_anim;

/*
** Animation
*/

# define F_ANIM_END				(1 << 1)
# define F_ANIM_RESTART			(1 << 2)
# define F_ANIM_REPEAT			(1 << 3)
# define F_ANIM_REVERSE			(F_ANIM_REPEAT | _F_ANIM_REVERSE)

# define _F_ANIM_REPEAT			(1 << 4)
# define _F_ANIM_REVERSE		(1 << 5)

struct			s_anim
{
	uint64_t		start_time;
	float			duration;
	int				flags;
	float			(*smooth)(float delta);
};

/*
** Create an anim
** -
** d		duration (in ms)
** f		flags
** s		smooth function
*/
# define ANIM(D,F,S)			((t_anim){0, (D), (F), (S)})

/*
** Update an anim
*/
float			anim_update(t_anim *anim, uint64_t now);

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
