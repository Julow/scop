/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 15:46:53 by juloo             #+#    #+#             */
/*   Updated: 2016/01/16 01:18:55 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj.h"

static void		child_rotate(t_obj *obj, t_vec3 const *rotate)
{
	uint32_t		i;

	obj->flags &= ~OBJ_F_MATRIX_OK;
	obj->transform.rotation = VEC3_ADD(obj->transform.rotation, *rotate);
	obj->world_transform.rotation = VEC3_ADD(obj->world_transform.rotation, *rotate);
	i = 0;
	while (i < obj->childs.length)
		child_rotate(VECTOR_GET(obj->childs, i++), rotate);
}

void			ft_obj_rotate(t_obj *obj, t_vec3 rotate, bool set)
{
	if (set)
		rotate = VEC3_SUB(rotate, obj->transform.rotation);
	child_rotate(obj, &rotate);
}
