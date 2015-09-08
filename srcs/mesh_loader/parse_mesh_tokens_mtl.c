/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mesh_tokens_mtl.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 19:15:44 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/08 19:16:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh_loader.h"
#include "resources.h"

t_bool			parse_mtllib(t_sub line, t_mesh_data *data)
{
	line.length = 0;
	if (!ft_subnext(&line, IS_SPACE))
		return (ft_fdprintf(2, "mtllib need an argument"), false);
	if ((data->mtllib = get_res(res_mtl, line)) == NULL)
		return (false);
	data->mtllib = *(t_hmap**)data->mtllib; // TODO: emplace hmap init
	return (true);
}

t_bool			parse_usemtl(t_sub line, t_mesh_data *data)
{
	t_mtl const		*mtl;
	t_mesh_mtl		*tmp;

	line.length = 0;
	if (data->mtllib == NULL)
		// return (ft_fdprintf(2, "no mtllib loaded\n"), false);
		return (false); // TMP
	if (!ft_subnextc(&line, ' '))
		return (ft_fdprintf(2, "usemtl need an argument\n"), false);
	if ((mtl = ft_hmapget(data->mtllib, line)) == NULL)
		return (ft_fdprintf(2, "Unknown mtl: %.*s\n", line.length, line.str), false);
	tmp = VECTOR_GET(data->mtl, data->mtl.length - 1);
	tmp->count = data->f.length;
	ft_vpush_back(&(data->mtl), &(t_mesh_mtl){mtl, data->f.length}, 1);
	return (true);
}
