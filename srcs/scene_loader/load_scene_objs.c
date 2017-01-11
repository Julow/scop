/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_scene_objs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:28:32 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/11 13:44:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh_loader.h" // TODO: remove
#include "p_scene_loader.h"

static void		load_obj(t_mesh_render *mesh_render,
					t_scene_pod_object const *pod, t_obj *dst)
{
	t_scene_pod_component const	*comp;
	t_obj_component				*c;

	*dst = OBJ();
	obj_translate(dst, pod->pos);
	obj_rotate(dst, pod->rot);
	obj_scale(dst, pod->scale);
	obj_shear(dst, pod->shear);
	dst->renderer = create_mesh_renderer(mesh_render, load_mesh(*pod->mesh));
	comp = VECTOR_IT(pod->components);
	ft_vreserve(&dst->components, pod->components.length);
	while (VECTOR_NEXT(pod->components, comp))
	{
		c = comp->c->create(comp->param, comp->c->param);
		if (c != NULL)
			ft_vpush(&dst->components, &c, 1);
	}
	load_scene_objs(mesh_render, &pod->childs, &dst->childs);
}

void			load_scene_objs(t_mesh_render *mesh_render,
					t_vector const *pods, t_vector *dst)
{
	t_scene_pod_object const	*obj;

	*dst = VECTOR(t_obj);
	ft_vreserve(dst, pods->length);
	obj = VECTOR_IT(*pods);
	while (VECTOR_NEXT(*pods, obj))
		load_obj(mesh_render, obj, ft_vpush(dst, NULL, 1));
}
