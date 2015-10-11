/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mtl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 19:13:37 by jaguillo          #+#    #+#             */
/*   Updated: 2015/10/11 20:42:52 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtl_loader.h"
#include "utils.h"
#include "ft_hmap.h"

static t_mtl_token const	g_mtl_tokens[] = {
	{SUBC("Ka"), &ambient_color_token},
	{SUBC("Kd"), &diffuse_color_token},
	{SUBC("Ks"), &specular_color_token},
	{SUBC("Ns"), &specular_exp_token},
	{SUBC("map_Ka"), &map_ka_token},
	{SUBC("map_Kd"), &map_kd_token},
	{SUBC("map_Ks"), &map_ks_token},
};

static t_bool	new_mtl_token(t_sub line, t_hmap *mtl_lib, t_mtl **dst)
{
	t_mtl const		default_mtl = {
		NULL,
		NULL,
		NULL,
		VEC3(1.f, 1.f, 1.f),
		VEC3(1.f, 1.f, 1.f),
		VEC3(1.f, 1.f, 1.f),
		1
	};

	if (!ft_subnextc(&line, ' '))
		return (false);
	*dst = ft_hmapput(mtl_lib, line, &default_mtl, sizeof(t_mtl)).value;
	return (true);
}

t_bool			parse_mtl(int fd, t_hmap *mtl_lib)
{
	t_mtl			*curr_mtl;
	t_sub			line;
	int				i;

	curr_mtl = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		line.length = 0;
		if (!ft_subnext(&line, IS_SPACE))
			continue ;
		if (ft_subequ(line, SUBC("newmtl"))
			&& !new_mtl_token(line, mtl_lib, &curr_mtl))
			return (false);
		if (curr_mtl == NULL)
			continue ;
		i = -1;
		while (++i < G_ARRAY_LEN(g_mtl_tokens))
			if (ft_subequ(g_mtl_tokens[i].name, line)
				&& !g_mtl_tokens[i].f(SUB(line.str + line.length, 0), curr_mtl)
				&& !IGNORE_ERROR)
				return (false);
	}
	return (true);
}
