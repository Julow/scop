/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj_shear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 15:46:53 by juloo             #+#    #+#             */
/*   Updated: 2016/01/16 01:18:38 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj.h"

static void		child_shear(t_obj *obj, t_vec3 const *shear)
{
	uint32_t		i;

	obj->flags &= ~OBJ_F_MATRIX_OK;
	obj->transform.shear = VEC3_ADD(obj->transform.shear, *shear);
	obj->world_transform.shear = VEC3_ADD(obj->world_transform.shear, *shear);
	i = 0;
	while (i < obj->childs.length)
		child_shear(VECTOR_GET(obj->childs, i++), shear);
}

void			ft_obj_shear(t_obj *obj, t_vec3 shear, bool set)
{
	if (set)
		shear = VEC3_SUB(shear, obj->transform.shear);
	child_shear(obj, &shear);
}
