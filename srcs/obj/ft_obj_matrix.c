/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 16:22:42 by juloo             #+#    #+#             */
/*   Updated: 2016/01/16 01:14:16 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj.h"

t_mat4 const	*ft_obj_matrix(t_obj *obj)
{
	// if (!(obj->flags & OBJ_F_MATRIX_OK))
	{
		// obj->flags |= OBJ_F_MATRIX_OK;
		obj->world_matrix = MAT4_I();
		ft_mat4translate(&obj->world_matrix, obj->world_transform.position);
		ft_mat4scale3(&obj->world_matrix, obj->world_transform.scale);
		ft_mat4shear(&obj->world_matrix, obj->world_transform.shear);
		ft_mat4rotate(&obj->world_matrix, obj->world_transform.rotation);
		ft_mat4transpose(&obj->world_matrix);
	}
	return (&obj->world_matrix);
}
