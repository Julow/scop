/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 11:29:16 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/28 17:35:10 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj.h"

static void		obj_update_components(t_vector *components, t_obj *obj)
{
	t_obj_component	**c;

	c = VECTOR_IT(*components);
	while (VECTOR_NEXT(*components, c))
	{
		(*c)->update(*c, obj);
	}
}

static void		get_local_m(t_transform const *t, t_mat4 *dst, t_mat4 *inv)
{
	*dst = ft_mat4transform(t->position, t->rotation, t->shear, t->scale);
	*inv = ft_mat4transform_inv(t->position, t->rotation, t->shear, t->scale);
}

static void		obj_update_world_m(t_obj *obj, t_obj const *parent)
{
	t_mat4			local_m;
	t_mat4			local_inv_m;

	if (parent == NULL)
	{
		get_local_m(&obj->local, &obj->world_m, &obj->world_inv_m);
	}
	else
	{
		get_local_m(&obj->local, &local_m, &local_inv_m);
		ft_mat4mult(&parent->world_m, &local_m, &obj->world_m);
		ft_mat4mult(&parent->world_inv_m, &local_inv_m, &obj->world_inv_m);
	}
}

static void		obj_update_loop(t_vector *objs,
					t_obj const *parent, bool parent_moved)
{
	t_obj			*obj;
	bool			moving;

	obj = VECTOR_IT(*objs);
	while (VECTOR_NEXT(*objs, obj))
	{
		obj_update_components(&obj->components, obj);
		moving = parent_moved || obj->moving;
		if (moving)
			obj_update_world_m(obj, parent);
		obj_update_loop(&obj->childs, obj, moving);
		obj->moving = false;
		obj->moved = moving;
	}
}

void			obj_update(t_vector *objs)
{
	obj_update_loop(objs, NULL, false);
}
