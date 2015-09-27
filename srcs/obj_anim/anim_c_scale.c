/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_c_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 20:10:00 by juloo             #+#    #+#             */
/*   Updated: 2015/09/27 20:51:14 by juloo            ###   ########.fr       */
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
