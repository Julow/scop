/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mesh_tokens_mtl.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 19:15:44 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/16 15:24:08 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "mtl_loader.h"
#include "utils.h"

bool			parse_mtllib(t_sub line, t_mesh_data *data)
{
	t_sub			word;

	word = SUB_START(line);
	if (!ft_subnext_is(line, &word, IS_WHITESPACE))
		return (ft_error(false, "mtllib need an argument"));
	if ((data->mtllib = load_mtl(line)) == NULL)
		return (false);
	return (true);
}

bool			parse_usemtl(t_sub line, t_mesh_data *data)
{
	t_mtl const		*mtl;
	t_mesh_mtl		*tmp;
	t_sub			word;

	if (data->mtllib == NULL)
		return (false);
	word = SUB_START(line);
	if (!ft_subnext_is(line, &word, IS_WHITESPACE))
		return (ft_error(false, "usemtl need an argument"));
	if ((mtl = mtllib_get(data->mtllib, word)) == NULL)
		return (false);
	tmp = VECTOR_GET(data->mtl, data->mtl.length - 1);
	tmp->count = data->f.length;
	ft_vpush(&(data->mtl), &(t_mesh_mtl){mtl, data->f.length}, 1);
	return (true);
}
