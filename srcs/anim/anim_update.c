/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 19:12:19 by juloo             #+#    #+#             */
/*   Updated: 2015/09/27 19:45:45 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "anim.h"

void			anim_update(void *env, t_anim *anim, t_ulong now)
{
	float			delta;

	if (anim->flags & F_ANIM_END)
		return ;
	delta = (float)(now - anim->start_time) / anim->duration / 1000.f;
	if (delta >= 1.f)
	{
		if (anim->flags & (F_ANIM_REPEAT | F_ANIM_REPEAT_REV))
		{
			delta -= 1.f;
			if (anim->flags & F_ANIM_ONREPEAT_REV)
				anim->flags &= ~F_ANIM_ONREPEAT_REV;
			else if (anim->flags & F_ANIM_REPEAT_REV)
				anim->flags |= F_ANIM_ONREPEAT_REV;
		}
		else
		{
			anim->flags |= F_ANIM_END;
			delta = 1.f;
		}
		anim->start_time = now;
	}
	if (anim->flags & F_ANIM_ONREPEAT_REV)
		delta = 1.f - delta;
	anim->callback(env, delta);
}
