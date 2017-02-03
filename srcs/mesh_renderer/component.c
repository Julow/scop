/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:03:24 by jaguillo          #+#    #+#             */
/*   Updated: 2017/02/03 14:00:53 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh_loader.h"
#include "p_mesh_renderer.h"

static void		component_update(t_mesh_renderer_component *c, t_obj *obj)
{
	if (obj->moved)
		c->model_m = obj->world_m;
}

t_obj_component	*mesh_renderer_component_create(
					t_mesh_renderer_component_param const *param,
					t_mesh_renderer *r)
{
	t_mesh_renderer_component	*c;
	t_mesh const *const			mesh = load_mesh(**param);

	ASSERT(mesh != NULL, "Failed to load some mesh");
	c = ft_listadd(&r->meshes, r->meshes.last, 0);
	*c = (t_mesh_renderer_component){
		OBJ_COMPONENT(&component_update),
		r,
		mesh,
		MAT4_0(),
	};
	return (V(c));
}
