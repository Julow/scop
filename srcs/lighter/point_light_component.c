/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_light_component.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 16:49:17 by jaguillo          #+#    #+#             */
/*   Updated: 2017/02/02 15:22:19 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math_mat4.h"

#include "lighter.h"
#include "p_lighter.h"

static void		component_update(t_point_light_component *c, t_obj *obj)
{
	if (obj->moved)
	{
		check_point_vbo(c->l);
		c->data.pos = VEC3_0();
		ft_mat4apply_vec3(&obj->world_m, &c->data.pos, 1.f);
		glBindBuffer(GL_ARRAY_BUFFER, c->l->point_vbo);
		glBufferSubData(GL_ARRAY_BUFFER, S(t_point_light_data, c->index),
				sizeof(t_point_light_data), &c->data);
		// TRACE("point_vbo update");
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
		0,
		{
			{},
			*param,
		},
	};
	lighter->flags |= LIGHTER_F_POINT_VBO_INVALID;
	return (c);
}
