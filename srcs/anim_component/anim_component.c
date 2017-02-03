/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_component.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 22:11:48 by jaguillo          #+#    #+#             */
/*   Updated: 2017/02/03 13:41:29 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "anim_component.h"

static void		(*const g_transforms[])(t_obj*, t_vec3) = {
	[OBJ_ANIM_TRANSLATE] = &obj_translate,
	[OBJ_ANIM_ROTATE] = &obj_rotate,
	[OBJ_ANIM_SHEAR] = &obj_shear,
	[OBJ_ANIM_SCALE] = &obj_scale,
};

static void		anim_component_update(t_anim_component *c, t_obj *obj)
{
	float			delta;

	if (c->anim.flags & F_ANIM_END)
		return ;
	delta = anim_update(&c->anim, ft_clock(0));
	g_transforms[c->type](obj, VEC3_ADD(VEC3_MUL1(c->offset, delta), c->from));
}

t_obj_component	*create_anim_component(t_anim_component_param const *param)
{
	t_anim_component *const	c = NEW(t_anim_component);

	*c = (t_anim_component){
		OBJ_COMPONENT(&anim_component_update),
		ANIM(param->duration, param->flags, param->smooth),
		param->from,
		VEC3_SUB(param->to, param->from),
		param->type
	};
	anim_start(&c->anim);
	return (V(c));
}
