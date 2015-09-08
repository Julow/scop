/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mesh_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 16:54:51 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/08 15:19:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh_loader.h"
#include "ft_evalexpr.h"
#include "resources.h"
#include "utils.h"

t_bool			parse_v(t_sub line, t_mesh_data *data)
{
	return (parse_fvec(line, ft_vpush_back(&(data->v), NULL, 1), 3));
}

t_bool			parse_vn(t_sub line, t_mesh_data *data)
{
	return (parse_fvec(line, ft_vpush_back(&(data->vn), NULL, 1), 3));
}

t_bool			parse_vt(t_sub line, t_mesh_data *data)
{
	return (parse_fvec(line, ft_vpush_back(&(data->vt), NULL, 1), 2));
}

t_bool			parse_f(t_sub line, t_mesh_data *data)
{
	int				face[9];
	int				tmp;
	int				i;
	int				j;

	line.length = 0;
	i = 0;
	while (ft_subnext(&line, IS_SPACE))
	{
		j = -1;
		while (++j < 3)
		{
			tmp = ft_subint(line, face + i + j);
			if (line.length <= tmp)
			{
				while (++j < 3)
					face[i + j] = 0;
				break ;
			}
			if (line.str[tmp] != '/')
				return (ft_printf("Invalid separator: '%c'\n", line.str[tmp]),
					false);
			tmp++;
			line.str += tmp;
			line.length -= tmp;
		}
		if ((i += 3) >= 9)
		{
			ft_vpush_back(&(data->f), face, 1);
			ft_memmove(face + 3, face + 6, S(int, 3));
			i -= 3;
		}
	}
	return (true);
}

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
