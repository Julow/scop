/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_component.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 22:11:48 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/23 22:12:13 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "anim_component.h"

static void		(*const obj_transform[])(t_obj*, t_vec3) = {
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
	obj_transform[c->type](obj, VEC3_ADD(VEC3_MUL1(c->offset, delta), c->from));
}

t_obj_component	*create_anim_component(t_vec3 from, t_vec3 to, float duration,
					float (*smooth)(float), t_obj_anim_t type, uint32_t flags)
{
	t_anim_component *const	c = NEW(t_anim_component);

	*c = (t_anim_component){
		OBJ_COMPONENT(&anim_component_update),
		ANIM(duration, flags, smooth),
		from,
		VEC3_SUB(to, from),
		type
	};
	anim_start(&c->anim);
	return (V(c));
}
