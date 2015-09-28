/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_c_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 20:45:05 by juloo             #+#    #+#             */
/*   Updated: 2015/09/27 20:51:10 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_anim.h"
#include "obj.h"

void			anim_c_rot(t_obj *obj, float delta)
{
	struct s_anim_obj *const	anim = (struct s_anim_obj*)obj->anim;
	t_vec3						rot;

	rot.x = (anim->to.x - anim->from.x) * delta + anim->from.x;
	rot.y = (anim->to.y - anim->from.y) * delta + anim->from.y;
	rot.z = (anim->to.z - anim->from.z) * delta + anim->from.z;
	ft_transform_rotate(&(obj->transform), rot);
}