/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_mesh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 16:59:58 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/30 16:20:41 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh_loader.h"

static t_bool	center_vertices(t_vector *vertices)
{
	int				i;
	t_vec3			*vert;
	t_vec3			sum;

	i = -1;
	sum = VEC3(0.f, 0.f, 0.f);
	while (++i < vertices->length)
	{
		vert = VECTOR_GET(vertices, i);
		sum.x += vert->x;
		sum.y += vert->y;
		sum.z += vert->z;
	}
	sum.x /= vertices->length;
	sum.y /= vertices->length;
	sum.z /= vertices->length;
	i = -1;
	while (++i < vertices->length)
	{
		vert = VECTOR_GET(vertices, i);
		vert->x -= sum.x;
		vert->y -= sum.y;
		vert->z -= sum.z;
	}
	return (true);
}

t_bool			build_mesh(t_mesh_data *data)
{
	int				i;
	int				j;
	int				*face;
	int				v_index;

	if (!center_vertices(&(data->v)))
		return (false);
	i = -1;
	v_index = 0;
	while (++i < data->f.length)
	{
		face = VECTOR_GET(&(data->f), i);
		j = 0;
		while (j <= 6)
		{
			if (data->v.length <= face[0 + j]
				|| data->vt.length <= face[1 + j]
				|| data->vn.length <= face[2 + j])
				return (ft_printf("Face #%d out of bounds (%d %d %d) / (%d %d %d)",
					i, face[0 + j], face[1 + j], face[2 + j], data->v.length,
					data->vt.length, data->vn.length), false);
			ft_vpush_back(&(data->vbo_data), VECTOR_GET(&(data->v), face[0 + j]), 3);
			ft_vpush_back(&(data->vbo_data), &VEC3(0.f, 0.f, 0.f), 3);
			ft_vpush_back(&(data->vbo_data), VECTOR_GET(&(data->vt), face[1 + j]), 2);
			ft_vpush_back(&(data->vbo_data), VECTOR_GET(&(data->vn), face[2 + j]), 3);
			ft_vpush_back(&(data->ebo_data), &v_index, 1);
			j += 3;
			v_index++;
		}
	}
	return (true);
}
