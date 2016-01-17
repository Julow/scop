/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 15:46:53 by juloo             #+#    #+#             */
/*   Updated: 2016/01/16 18:56:20 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj.h"

static void		child_translate(t_obj *obj, t_vec3 const *translate)
{
	uint32_t		i;

	obj->flags &= ~OBJ_F_MATRIX_OK;
	obj->world_transform.position = VEC3_ADD(obj->world_transform.position, *translate);
	i = 0;
	while (i < obj->childs.length)
		child_translate(*(t_obj**)VECTOR_GET(obj->childs, i++), translate);
}

void			ft_obj_translate(t_obj *obj, t_vec3 translate, bool set)
{
	if (set)
		translate = VEC3_SUB(translate, obj->transform.position);
	obj->transform.position = VEC3_ADD(obj->transform.position, translate);
	child_translate(obj, &translate);
}
