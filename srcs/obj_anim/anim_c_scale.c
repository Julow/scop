/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_c_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 20:10:00 by juloo             #+#    #+#             */
/*   Updated: 2015/12/03 19:50:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_anim.h"
#include "obj.h"

void			anim_c_scale(t_obj *obj, float delta)
{
	struct s_anim_obj *const	anim = (struct s_anim_obj*)obj->anim;
	float						scale;

	scale = (anim->to.x - anim->from.x) * delta + anim->from.x;
	ft_transform_scale(&(obj->transform), scale);
}

void			anim_c_scale3(t_obj *obj, float delta)
{
	struct s_anim_obj *const	anim = (struct s_anim_obj*)obj->anim;
	t_vec3						scale;

	scale.x = (anim->to.x - anim->from.x) * delta + anim->from.x;
	scale.y = (anim->to.y - anim->from.y) * delta + anim->from.y;
	scale.z = (anim->to.z - anim->from.z) * delta + anim->from.z;
	ft_transform_scale3(&(obj->transform), scale);
}
