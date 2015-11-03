/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_mtl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/07 20:24:14 by juloo             #+#    #+#             */
/*   Updated: 2015/11/03 13:09:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

t_bool			build_mtl(t_mesh_data *data, t_mesh *dst)
{
	t_mesh_mtl		*mtl;
	int				i;
	int				last;
	int				tmp;

	mtl = VECTOR_GET(data->mtl, data->mtl.length - 1);
	mtl->count = data->f.length;
	i = -1;
	last = 0;
	while (++i < data->mtl.length)
	{
		mtl = VECTOR_GET(data->mtl, i);
		tmp = mtl->count;
		mtl->count -= last;
		mtl->count *= 3;
		last = tmp;
	}
	dst->mtl = data->mtl.data;
	dst->mtl_count = data->mtl.length;
	return (true);
}
