/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_mesh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 16:59:58 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/22 12:19:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/math_vec3.h"

#include "internal.h"
#include "utils.h"

static bool		center_vertices(t_vector *vertices)
{
	uint32_t		i;
	t_vec3			*vert;
	t_vec3			sum;

	i = 0;
	sum = VEC3(0.f, 0.f, 0.f);
	while (i < vertices->length)
	{
		vert = VECTOR_GET(*vertices, i);
		sum = VEC3_ADD(sum, *vert);
		i++;
	}
	sum = VEC3_DIV1(sum, vertices->length);
	i = 0;
	while (i < vertices->length)
	{
		vert = VECTOR_GET(*vertices, i);
		*vert = VEC3_SUB(*vert, sum);
		i++;
	}
	return (true);
}

static bool		build_face(t_mesh_data *data, uint32_t *face, uint32_t *ebo_id)
{
	uint32_t		i;

	i = 0;
	while (i <= 6)
	{
		if (data->v.length <= face[0 + i]
			|| data->vt.length <= face[1 + i]
			|| data->vn.length <= face[2 + i])
			return (ft_error(false, "Face out of bounds\n"));
		ft_vpush(&(data->vbo_data), VECTOR_GET(data->v, face[0 + i]), 3);
		ft_vpush(&(data->vbo_data), VECTOR_GET(data->vt, face[1 + i]), 2);
		ft_vpush(&(data->vbo_data), VECTOR_GET(data->vn, face[2 + i]), 3);
		ft_vpush(&(data->ebo_data), ebo_id, 1);
		i += 3;
		(*ebo_id)++;
	}
	return (true);
}

bool			build_mesh(t_mesh_data *data)
{
	uint32_t		i;
	uint32_t		ebo_id;

	if (!center_vertices(&(data->v)))
		return (false);
	ft_vreserve(&(data->vbo_data), data->f.length * 3);
	ft_vreserve(&(data->ebo_data), data->f.length);
	i = 0;
	ebo_id = 0;
	while (i < data->f.length)
	{
		if (!build_face(data, VECTOR_GET(data->f, i), &ebo_id))
			return (false);
		i++;
	}
	return (true);
}
