/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 08:40:08 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/04 12:28:53 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

/*
** Order:
**  translate
**  scale
**  shear
**  rotation
**  reflect
*/

t_mat4 const	*ft_transform_get(t_transform *t)
{
	if (!(t->flags & F_TRANSFORM_OK))
	{
		t->_matrix = MAT4_I();
		ft_mat4translate(&t->_matrix, t->position);
		ft_mat4scale3(&t->_matrix, t->scale);
		ft_mat4shear(&t->_matrix, t->shear);
		ft_mat4rotate(&t->_matrix, t->rotation);
		ft_mat4reflect(&t->_matrix, t->flags);
		ft_mat4translate(&t->_matrix, t->origin);
		ft_mat4transpose(&t->_matrix);
		// t->matrix[1] = MAT4_I();
		// ft_mat4reflect_inv(t->matrix + 1, t->flags);
		// ft_mat4rotate_inv(t->matrix + 1, t->rotation);
		// ft_mat4shear(t->matrix + 1,
		// 	VEC3(0.f - t->shear.x, 0.f - t->shear.y, 0.f - t->shear.z));
		// ft_mat4scale3(t->matrix + 1,
		// 	VEC3(1.f / t->scale.x, 1.f / t->scale.y, 1.f / t->scale.z));
		// ft_mat4translate(t->matrix + 1, ft_vec3sub(VEC3_0(), t->position));
		// ft_mat4transpose(t->matrix + 1);
		t->flags |= F_TRANSFORM_OK;
	}
	return (&t->_matrix);
}
