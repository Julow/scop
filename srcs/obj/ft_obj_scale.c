/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 15:46:53 by juloo             #+#    #+#             */
/*   Updated: 2016/01/16 18:56:49 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj.h"

static void		child_scale(t_obj *obj, t_vec3 const *scale)
{
	uint32_t		i;

	obj->flags &= ~OBJ_F_MATRIX_OK;
	obj->world_transform.scale = VEC3_ADD(obj->world_transform.scale, *scale);
	i = 0;
	while (i < obj->childs.length)
		child_scale(*(t_obj**)VECTOR_GET(obj->childs, i++), scale);
}

void			ft_obj_scale(t_obj *obj, t_vec3 scale, bool set)
{
	if (set)
		scale = VEC3_SUB(scale, obj->transform.scale);
	obj->transform.scale = VEC3_ADD(obj->transform.scale, scale); // TODO: mult
	child_scale(obj, &scale);
}
