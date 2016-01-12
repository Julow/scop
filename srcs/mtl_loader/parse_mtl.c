/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mtl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 19:13:37 by jaguillo          #+#    #+#             */
/*   Updated: 2016/01/13 00:43:11 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_hmap.h"
#include "ft/get_next_line.h"

#include "internal.h"
#include "utils.h"

static t_mtl_token const	g_mtl_tokens[] = {
	{SUBC("Ka"), &ambient_color_token},
	{SUBC("Kd"), &diffuse_color_token},
	{SUBC("Ks"), &specular_color_token},
	{SUBC("Ns"), &specular_exp_token},
	{SUBC("map_Ka"), &map_ka_token},
	{SUBC("map_Kd"), &map_kd_token},
	{SUBC("map_Ks"), &map_ks_token},
};

static bool		new_mtl_token(t_sub line, t_hmap *mtl_lib, t_mtl **dst)
{
	t_sub			word;
	t_mtl const		default_mtl = {
		NULL,
		NULL,
		NULL,
		VEC3(1.f, 1.f, 1.f),
		VEC3(1.f, 1.f, 1.f),
		VEC3(1.f, 1.f, 1.f),
		1
	};

	word = SUB_START(line);
	if (!ft_subnext_is(line, &word, IS_SPACE))
		return (false);
	*dst = ft_hmapput(mtl_lib, word, &default_mtl, sizeof(t_mtl)).value;
	return (true);
}

bool			parse_mtl(int fd, t_hmap *mtl_lib)
{
	t_mtl			*curr_mtl;
	t_sub			line;
	t_sub			word;
	int				i;

	curr_mtl = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		word = SUB_START(line);
		if (!ft_subnext_is(line, &word, IS_SPACE))
			continue ;
		line = SUB_FOR(line, SUB_OFF(line, word) + word.length);
		if (ft_subequ(word, SUBC("newmtl"))
			&& !new_mtl_token(line, mtl_lib, &curr_mtl))
			return (false);
		if (curr_mtl == NULL)
			continue ;
		i = -1;
		while (++i < ARRAY_LEN(g_mtl_tokens))
			if (ft_subequ(g_mtl_tokens[i].name, word)
				&& !g_mtl_tokens[i].f(line, curr_mtl)
				&& !IGNORE_ERROR)
				return (false);
	}
	return (true);
}
