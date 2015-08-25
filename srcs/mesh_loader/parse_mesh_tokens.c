/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mesh_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 16:54:51 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/25 17:08:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh_loader.h"
#include "ft_evalexpr.h"
#include "utils.h"

static t_bool	parse_vec(t_sub line, float *vec, int len)
{
	int				i;

	line.length = 0;
	i = -1;
	while (++i < len && ft_subnext(&line, IS_SPACE))
		if (ft_subfloat(line, vec + i) == 0)
		{
			ft_printf("Invalid float: %.*s\n", line.length, line.str);
			return (false);
		}
	return (true);
}

t_bool			parse_v(t_sub line, t_mesh_data *data)
{
	return (parse_vec(line, ft_vpush_back(&(data->v), NULL, 1), 3));
}

t_bool			parse_vn(t_sub line, t_mesh_data *data)
{
	return (parse_vec(line, ft_vpush_back(&(data->vn), NULL, 1), 3));
}

t_bool			parse_vt(t_sub line, t_mesh_data *data)
{
	return (parse_vec(line, ft_vpush_back(&(data->vt), NULL, 1), 2));
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
			face[i + j] -= 1;
			if (line.length <= tmp)
				break ;
			if (line.str[tmp] != '/')
				return (ft_printf("Invalid syntax: %.*s\n",
					line.length, line.str), false);
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
