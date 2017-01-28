/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 18:08:48 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/28 18:09:44 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj.h"

void			obj_bind(t_obj *obj, t_obj_component *c)
{
	ASSERT(c->obj == NULL, "Component rebind");
	c->obj = obj;
	ft_vpush(&obj->components, &c, 1);
}
