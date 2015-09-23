/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 08:40:08 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/23 11:48:16 by jaguillo         ###   ########.fr       */
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
		ft_printf("Warning: updating matrix\n");
		t->matrix[0] = MAT4_I();
		ft_mat4translate(t->matrix, t->position);
		ft_mat4scale(t->matrix, t->scale);
		ft_mat4shear(t->matrix, t->shear);
		ft_mat4rotate(t->matrix, t->rotation);
		ft_mat4reflect(t->matrix, t->flags);
		t->matrix[1] = MAT4_I();
		ft_mat4reflect_inv(t->matrix + 1, t->flags);
		ft_mat4rotate_inv(t->matrix + 1, t->rotation);
		ft_mat4shear(t->matrix + 1,
			VEC3(0.f - t->shear.x, 0.f - t->shear.y, 0.f - t->shear.z));
		ft_mat4scale(t->matrix + 1, 1.f / t->scale);
		ft_mat4translate(t->matrix + 1, ft_vec3sub(VEC3_0(), t->position));
		ft_mat4transpose(t->matrix + 1);
		t->flags |= F_TRANSFORM_OK;
	}
	return (t->matrix);
}
