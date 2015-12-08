/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_mesh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 16:59:58 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/08 17:05:16 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "ft/math.h"
#include "utils.h"

static t_bool	center_vertices(t_vector *vertices)
{
	int				i;
	t_vec3			*vert;
	t_vec3			sum;

	i = -1;
	sum = VEC3(0.f, 0.f, 0.f);
	while (++i < vertices->length)
	{
		vert = VECTOR_GET(*vertices, i);
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
		vert = VECTOR_GET(*vertices, i);
		vert->x -= sum.x;
		vert->y -= sum.y;
		vert->z -= sum.z;
	}
	return (true);
}

static t_bool	build_face(t_mesh_data *data, int *face, int *ebo_id)
{
	int				i;

	i = 0;
	while (i <= 6)
	{
		if (data->v.length <= face[0 + i]
			|| data->vt.length <= face[1 + i]
			|| data->vn.length <= face[2 + i])
			return (ft_error(false, "Face out of bounds\n"));
		ft_vpush_back(&(data->vbo_data), VECTOR_GET(data->v, face[0 + i]), 3);
		ft_vpush_back(&(data->vbo_data), VECTOR_GET(data->vt, face[1 + i]), 2);
		ft_vpush_back(&(data->vbo_data), VECTOR_GET(data->vn, face[2 + i]), 3);
		ft_vpush_back(&(data->ebo_data), ebo_id, 1);
		i += 3;
		(*ebo_id)++;
	}
	return (true);
}

t_bool			build_mesh(t_mesh_data *data)
{
	int				i;
	int				ebo_id;

	if (!center_vertices(&(data->v)))
		return (false);
	ft_vreserve(&(data->vbo_data), data->f.length * 3);
	ft_vreserve(&(data->ebo_data), data->f.length);
	i = -1;
	ebo_id = 0;
	while (++i < data->f.length)
		if (!build_face(data, VECTOR_GET(data->f, i), &ebo_id))
			return (false);
	return (true);
}
