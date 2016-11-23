/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 16:22:42 by juloo             #+#    #+#             */
/*   Updated: 2016/11/23 11:28:04 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj.h"

t_mat4 const	*obj_matrix(t_obj *obj)
{
	if (!(obj->flags & OBJ_F_MATRIX_OK))
	{
		obj->flags |= OBJ_F_MATRIX_OK;
		obj->transform_m = MAT4_I();
		ft_mat4translate(&obj->transform_m, obj->transform.position);
		ft_mat4scale3(&obj->transform_m, obj->transform.scale);
		ft_mat4shear(&obj->transform_m, obj->transform.shear);
		ft_mat4rotate(&obj->transform_m, obj->transform.rotation);
		ft_mat4transpose(&obj->transform_m);
	}
	return (&obj->transform_m);
}
