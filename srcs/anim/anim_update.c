/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 19:12:19 by juloo             #+#    #+#             */
/*   Updated: 2016/11/23 18:19:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "anim.h"

static float	anim_smooth(t_anim *anim, float delta)
{
	if (!(anim->flags & _F_ANIM_REVERSE))
		delta = anim->smooth(delta);
	if (anim->flags & _F_ANIM_REPEAT)
		delta = 1.f - delta;
	if (anim->flags & _F_ANIM_REVERSE)
		delta = anim->smooth(delta);
	return (delta);
}

float			anim_update(t_anim *anim, uint64_t now)
{
	float			delta;

	if (anim->flags & F_ANIM_END)
		return (1.f);
	delta = (float)(now - anim->start_time) / anim->duration / 1000.f;
	if (delta >= 1.f)
	{
		if (anim->flags & (F_ANIM_RESTART | F_ANIM_REPEAT))
		{
			delta -= 1.f;
			if (anim->flags & _F_ANIM_REPEAT)
				anim->flags &= ~_F_ANIM_REPEAT;
			else if (anim->flags & F_ANIM_REPEAT)
				anim->flags |= _F_ANIM_REPEAT;
		}
		else
		{
			anim->flags |= F_ANIM_END;
			delta = 1.f;
		}
		anim->start_time = now;
	}
	return (anim_smooth(anim, delta));
}
