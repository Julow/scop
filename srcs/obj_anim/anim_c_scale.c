/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_c_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 20:10:00 by juloo             #+#    #+#             */
/*   Updated: 2016/11/23 11:29:44 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj.h"
#include "obj_anim.h"

void			anim_c_scale(t_obj *obj, float delta)
{
	struct s_anim_obj *const	anim = (struct s_anim_obj*)obj->anim;
	float						scale;

	scale = (anim->to.x - anim->from.x) * delta + anim->from.x;
	obj_scale(obj, VEC3(scale, scale, scale));
}

void			anim_c_scale3(t_obj *obj, float delta)
{
	struct s_anim_obj *const	anim = (struct s_anim_obj*)obj->anim;
	t_vec3						scale;

	scale.x = (anim->to.x - anim->from.x) * delta + anim->from.x;
	scale.y = (anim->to.y - anim->from.y) * delta + anim->from.y;
	scale.z = (anim->to.z - anim->from.z) * delta + anim->from.z;
	obj_scale(obj, scale);
}
