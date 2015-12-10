/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mesh_tokens_mtl.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 19:15:44 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:52:31 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "mtl_loader.h"
#include "utils.h"
#include "ft/ft_hmap.h"
#include "ft/ft_sub.h"

bool			parse_mtllib(t_sub line, t_mesh_data *data)
{
	line.length = 0;
	if (!ft_subnext(&line, IS_SPACE))
		return (ft_error(false, "mtllib need an argument"));
	if ((data->mtllib = load_mtl(line)) == NULL)
		return (false);
	return (true);
}

bool			parse_usemtl(t_sub line, t_mesh_data *data)
{
	t_mtl const		*mtl;
	t_mesh_mtl		*tmp;

	line.length = 0;
	if (data->mtllib == NULL)
		return (false);
	if (!ft_subnextc(&line, ' '))
		return (ft_error(false, "usemtl need an argument\n"));
	if ((mtl = ft_hmapget(data->mtllib, line).value) == NULL)
		return (false);
	tmp = VECTOR_GET(data->mtl, data->mtl.length - 1);
	tmp->count = data->f.length;
	ft_vpush_back(&(data->mtl), &(t_mesh_mtl){mtl, data->f.length}, 1);
	return (true);
}
