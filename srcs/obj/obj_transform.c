/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:25:23 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/23 11:26:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj.h"

void			obj_translate(t_obj *obj, t_vec3 translate)
{
	obj->transform.position = translate;
	obj->flags &= ~OBJ_F_MATRIX_OK;
}

void			obj_rotate(t_obj *obj, t_vec3 rotate)
{
	obj->transform.rotation = rotate;
	obj->flags &= ~OBJ_F_MATRIX_OK;
}

void			obj_shear(t_obj *obj, t_vec3 shear)
{
	obj->transform.shear = shear;
	obj->flags &= ~OBJ_F_MATRIX_OK;
}

void			obj_scale(t_obj *obj, t_vec3 scale)
{
	obj->transform.scale = scale;
	obj->flags &= ~OBJ_F_MATRIX_OK;
}
