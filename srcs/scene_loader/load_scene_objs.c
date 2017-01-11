/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_scene_objs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:28:32 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/11 18:03:54 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_scene_loader.h"

static void		load_obj(t_scene_pod_object const *pod, t_obj *dst)
{
	t_scene_pod_component const	*comp;
	t_obj_component				*c;

	*dst = OBJ();
	obj_translate(dst, pod->pos);
	obj_rotate(dst, pod->rot);
	obj_scale(dst, pod->scale);
	obj_shear(dst, pod->shear);
	comp = VECTOR_IT(pod->components);
	ft_vreserve(&dst->components, pod->components.length);
	while (VECTOR_NEXT(pod->components, comp))
	{
		c = comp->c->create(comp->param, comp->c->create_param);
		if (c != NULL)
			ft_vpush(&dst->components, &c, 1);
	}
	load_scene_objs(&pod->childs, &dst->childs);
}

void			load_scene_objs(t_vector const *pods, t_vector *dst)
{
	t_scene_pod_object const	*obj;

	*dst = VECTOR(t_obj);
	ft_vreserve(dst, pods->length);
	obj = VECTOR_IT(*pods);
	while (VECTOR_NEXT(*pods, obj))
		load_obj(obj, ft_vpush(dst, NULL, 1));
}
