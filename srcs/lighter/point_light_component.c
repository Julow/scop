/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_light_component.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 16:49:17 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/21 17:42:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math_mat4.h"
#include "lighter.h"

static void		component_update(t_point_light_component *c, t_obj *obj)
{
	if (obj->moved)
	{
		c->pos = VEC3_0();
		ft_mat4apply_vec3(&obj->world_m, &c->pos, 1.f);
	}
}

t_point_light_component	*create_point_light_component(
							t_point_light_param const *param,
							t_lighter *lighter)
{
	t_point_light_component	*c;

	c = ft_listadd(&lighter->point_lights, lighter->point_lights.last, 0);
	*c = (t_point_light_component){
		OBJ_COMPONENT(&component_update),
		lighter,
		{},
		*param,
	};
	return (c);
}
