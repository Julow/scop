/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_mesh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 16:59:58 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/27 15:19:33 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh_loader.h"
#include <stdlib.h> //

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
	int					i;
	t_vec3				*vert;
	t_face				*face;
	float				color;

	if (!center_vertices(&(data->v)))
		return (false);
	i = -1;
	while (++i < data->v.length)
	{
		color = ((float)(rand() % 100)) / 100.f;
		vert = VECTOR_GET(&(data->v), i);
		ft_vpush_back(&(data->vbo_data), &(t_mesh_vbo_data){
			*vert,
			VEC3(color, color, color),
			VEC2(0.f, 0.f),
			VEC3(0.f, 0.f, 0.f)
		}, 1);
	}
	i = -1;
	while (++i < data->f.length)
	{
		face = VECTOR_GET(&(data->f), i);
		ft_vpush_back(&(data->ebo_data), &(t_mesh_ebo_data){
			face->v1,
			face->v2,
			face->v3
		}, 1);
	}
	return (true);
}
