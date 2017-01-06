/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:25:23 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/05 11:37:45 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj.h"

void			obj_translate(t_obj *obj, t_vec3 translate)
{
	obj->local.position = translate;
	obj->moving = true;
}

void			obj_rotate(t_obj *obj, t_vec3 rotate)
{
	obj->local.rotation = rotate;
	obj->moving = true;
}

void			obj_shear(t_obj *obj, t_vec3 shear)
{
	obj->local.shear = shear;
	obj->moving = true;
}

void			obj_scale(t_obj *obj, t_vec3 scale)
{
	obj->local.scale = scale;
	obj->moving = true;
}
