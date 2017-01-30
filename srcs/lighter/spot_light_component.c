/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot_light_component.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:12:40 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/30 16:37:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math_mat4.h"
#include "lighter.h"

#include <math.h>

static void		component_update(t_spot_light_component *c, t_obj *obj)
{
	if (obj->moved)
	{
		c->pos = VEC3_0();
		ft_mat4apply_vec3(&obj->world_m, &c->pos, 1.f);
		c->dir = VEC3(0.f, 0.f, 1.f);
		ft_mat4apply_vec3(&obj->world_m, &c->dir, 0.f);
	}
}

t_spot_light_component	*create_spot_light_component(
							t_spot_light_param const *param,
							t_lighter *lighter)
{
	t_spot_light_component	*c;

	c = ft_listadd(&lighter->spot_lights, lighter->spot_lights.last, 0);
	*c = (t_spot_light_component){
		OBJ_COMPONENT(&component_update),
		{},
		{},
		param->intensity,
		VEC2(cosf(param->cutoff), cosf(param->cutoff + param->cutoff_border)),
	};
	return (c);
}
