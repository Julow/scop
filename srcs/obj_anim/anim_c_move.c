/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_c_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 20:44:58 by juloo             #+#    #+#             */
/*   Updated: 2015/11/03 10:26:54 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_anim.h"
#include "obj.h"

void			anim_c_move(t_obj *obj, float delta)
{
	struct s_anim_obj *const	anim = (struct s_anim_obj*)obj->anim;
	t_vec3						pos;

	pos.x = (anim->to.x - anim->from.x) * delta + anim->from.x;
	pos.y = (anim->to.y - anim->from.y) * delta + anim->from.y;
	pos.z = (anim->to.z - anim->from.z) * delta + anim->from.z;
	ft_transform_move(&(obj->transform), pos);
}
