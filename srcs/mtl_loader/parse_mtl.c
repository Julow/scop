/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mtl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 19:13:37 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/12 15:49:21 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_dstr.h"
#include "ft/ft_in.h"

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

static t_mtl const			g_default_mtl = {
	NULL,
	NULL,
	NULL,
	VEC3(1.f, 1.f, 1.f),
	VEC3(1.f, 1.f, 1.f),
	VEC3(1.f, 1.f, 1.f),
	1
};

static bool		new_mtl_token(t_sub line, t_mtllib *mtllib, t_mtl **dst)
{
	t_sub			word;
	t_mtllib_mtl	*mtl;

	word = SUB_START(line);
	if (!ft_subnext_is(line, &word, IS_SPACE))
		return (false);
	mtl = MALLOC(sizeof(t_mtllib_mtl) + word.length);
	memcpy(ENDOF(mtl), word.str, word.length);
	*mtl = (t_mtllib_mtl){
		SET_HEAD(),
		SUB(ENDOF(mtl), word.length),
		g_default_mtl
	};
	ft_set_insert(&mtllib->mtls, mtl, &mtl->name);
	*dst = &mtl->mtl;
	return (true);
}

bool			parse_mtl(t_in *in, t_mtllib *mtl_lib)
{
	t_mtl			*curr_mtl;
	t_sub			line;
	t_dstr			line_buff;
	t_sub			word;
	int				i;

	curr_mtl = NULL;
	line_buff = DSTR0();
	while (ft_read_line(in, &line_buff))
	{
		line = DSTR_SUB(line);
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
