/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_c_shear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 20:45:08 by juloo             #+#    #+#             */
/*   Updated: 2015/09/27 20:51:12 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_anim.h"
#include "obj.h"

void			anim_c_shear(t_obj *obj, float delta)
{
	struct s_anim_obj *const	anim = (struct s_anim_obj*)obj->anim;
	t_vec3						shear;

	shear.x = (anim->to.x - anim->from.x) * delta + anim->from.x;
	shear.y = (anim->to.y - anim->from.y) * delta + anim->from.y;
	shear.z = (anim->to.z - anim->from.z) * delta + anim->from.z;
	ft_transform_shear(&(obj->transform), shear);
}
