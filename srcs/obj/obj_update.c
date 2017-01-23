/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 11:29:16 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/23 17:52:54 by jaguillo         ###   ########.fr       */
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

static void		obj_update_world_m(t_obj *obj, t_mat4 const *parent_m)
{
	t_mat4 const	local_m = ft_mat4transform(obj->local.position,
				obj->local.rotation, obj->local.shear, obj->local.scale);

	if (parent_m == NULL)
		obj->world_m = local_m;
	else
		ft_mat4mult(parent_m, &local_m, &obj->world_m);
}

static void		obj_update_loop(t_vector *objs,
					t_mat4 const *parent_m, bool parent_moved)
{
	t_obj			*obj;
	bool			moving;

	obj = VECTOR_IT(*objs);
	while (VECTOR_NEXT(*objs, obj))
	{
		obj_update_components(&obj->components, obj);
		moving = parent_moved || obj->moving;
		if (moving)
			obj_update_world_m(obj, parent_m);
		obj_update_loop(&obj->childs, &obj->world_m, moving);
		obj->moving = false;
		obj->moved = moving;
	}
}

void			obj_update(t_vector *objs)
{
	obj_update_loop(objs, NULL, false);
}
