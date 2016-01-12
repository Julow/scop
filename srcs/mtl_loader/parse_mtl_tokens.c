/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mtl_tokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 19:12:53 by jaguillo          #+#    #+#             */
/*   Updated: 2016/01/12 23:50:57 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "utils.h"

bool			ambient_color_token(t_sub line, t_mtl *mtl)
{
	return (parse_fvec(line, (float*)&(mtl->ambient_color), 3));
}

bool			diffuse_color_token(t_sub line, t_mtl *mtl)
{
	return (parse_fvec(line, (float*)&(mtl->diffuse_color), 3));
}

bool			specular_color_token(t_sub line, t_mtl *mtl)
{
	return (parse_fvec(line, (float*)&(mtl->specular_color), 3));
}

bool			specular_exp_token(t_sub line, t_mtl *mtl)
{
	float			ns;
	t_sub			word;

	word = SUB_START(line);
	if (!ft_subnext_is(line, &word, IS_SPACE) || ft_subto_float(word, &ns) == 0)
		return (false);
	mtl->specular_exp = ROUND(ns);
	return (true);
}
