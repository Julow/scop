/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_c_shear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 20:45:08 by juloo             #+#    #+#             */
/*   Updated: 2016/01/15 23:13:23 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj.h"
#include "obj_anim.h"

void			anim_c_shear(t_obj *obj, float delta)
{
	struct s_anim_obj *const	anim = (struct s_anim_obj*)obj->anim;
	t_vec3						shear;

	shear.x = (anim->to.x - anim->from.x) * delta + anim->from.x;
	shear.y = (anim->to.y - anim->from.y) * delta + anim->from.y;
	shear.z = (anim->to.z - anim->from.z) * delta + anim->from.z;
	ft_obj_shear(obj, shear, true);
}
