/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mesh_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 16:54:51 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:52:53 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "utils.h"
#include "ft/ft_sub.h"

bool			parse_v(t_sub line, t_mesh_data *data)
{
	return (parse_fvec(line, ft_vpush_back(&(data->v), NULL, 1), 3));
}

bool			parse_vn(t_sub line, t_mesh_data *data)
{
	return (parse_fvec(line, ft_vpush_back(&(data->vn), NULL, 1), 3));
}

bool			parse_vt(t_sub line, t_mesh_data *data)
{
	return (parse_fvec(line, ft_vpush_back(&(data->vt), NULL, 1), 2));
}

static bool		parse_f_tri(t_sub *line, int *face)
{
	int				tmp;
	int				j;

	j = -1;
	while (++j < 3)
	{
		tmp = ft_subint(*line, face + j);
		if (line->length <= tmp)
			break ;
		if (line->str[tmp] != '/')
			return (ft_error(false, "Invalid separator"));
		tmp++;
		line->str += tmp;
		line->length -= tmp;
	}
	while (++j < 3)
		face[j] = 0;
	return (true);
}

bool			parse_f(t_sub line, t_mesh_data *data)
{
	int				face[9];
	int				i;

	line.length = 0;
	i = 0;
	while (ft_subnext(&line, IS_SPACE))
	{
		if (!parse_f_tri(&line, face + i))
			return (false);
		if (i >= 6)
		{
			ft_vpush_back(&(data->f), face, 1);
			face[3] = face[6];
			face[4] = face[7];
			face[5] = face[8];
		}
		else
			i += 3;
	}
	return (true);
}
