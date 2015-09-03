/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mtl_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 19:12:53 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/03 19:13:56 by jaguillo         ###   ########.fr       */
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
	return (ft_subfloat(line, &(mtl->specular_exp)));
}

t_bool			map_kd_token(t_sub line, t_mtl *mtl)
{
	mtl->texture = get_res(res_texture, line);
	return (true);
}
