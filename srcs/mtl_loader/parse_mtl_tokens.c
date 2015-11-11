/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mtl_tokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 19:12:53 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/11 19:38:55 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "utils.h"
#include "ft_sub.h"

t_bool			ambient_color_token(t_sub line, t_mtl *mtl)
{
	return (parse_fvec(line, (float*)&(mtl->ambient_color), 3));
}

t_bool			diffuse_color_token(t_sub line, t_mtl *mtl)
{
	return (parse_fvec(line, (float*)&(mtl->diffuse_color), 3));
}

t_bool			specular_color_token(t_sub line, t_mtl *mtl)
{
	return (parse_fvec(line, (float*)&(mtl->specular_color), 3));
}

t_bool			specular_exp_token(t_sub line, t_mtl *mtl)
{
	float			ns;

	if (!ft_subnext(&line, IS_SPACE) || ft_subfloat(line, &ns) == 0)
		return (false);
	mtl->specular_exp = ROUND(ns);
	return (true);
}
