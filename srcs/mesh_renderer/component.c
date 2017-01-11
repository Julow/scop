/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:03:24 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/11 18:01:08 by jaguillo         ###   ########.fr       */
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
	t_mesh_renderer_component *const	c = ft_listadd(&r->meshes, r->meshes.last, 0);
	t_mesh const *const					mesh = load_mesh(**param);

	ASSERT(mesh != NULL, "Failed to load some mesh");
	*c = (t_mesh_renderer_component){
		OBJ_COMPONENT(&component_update),
		r,
		mesh,
		{}
	};
	return (V(c));
}
