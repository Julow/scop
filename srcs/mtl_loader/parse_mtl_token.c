/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mtl_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 19:12:53 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/14 22:02:59 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtl_loader.h"
#include "utils.h"
#include "ft_evalexpr.h"
#include "resources.h"

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
	return (ft_subint(line, &(mtl->specular_exp)));
}

t_bool			map_ka_token(t_sub line, t_mtl *mtl)
{
	if (!ft_subnext(&line, IS_SPACE))
		return (false);
	mtl->ambient_map = get_res(res_texture, line);
	return (true);
}

t_bool			map_kd_token(t_sub line, t_mtl *mtl)
{
	if (!ft_subnext(&line, IS_SPACE))
		return (false);
	mtl->diffuse_map = get_res(res_texture, line);
	return (true);
}

t_bool			map_ks_token(t_sub line, t_mtl *mtl)
{
	if (!ft_subnext(&line, IS_SPACE))
		return (false);
	mtl->specular_map = get_res(res_texture, line);
	return (true);
}
