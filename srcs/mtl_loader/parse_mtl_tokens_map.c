/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mtl_tokens_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 17:25:33 by jaguillo          #+#    #+#             */
/*   Updated: 2015/10/11 20:44:55 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtl_loader.h"
#include "texture_loader.h"

t_bool			map_ka_token(t_sub line, t_mtl *mtl)
{
	if (!ft_subnext(&line, IS_SPACE))
		return (false);
	mtl->ambient_map = load_texture(line);
	return (true);
}

t_bool			map_kd_token(t_sub line, t_mtl *mtl)
{
	if (!ft_subnext(&line, IS_SPACE))
		return (false);
	mtl->diffuse_map = load_texture(line);
	return (true);
}

t_bool			map_ks_token(t_sub line, t_mtl *mtl)
{
	if (!ft_subnext(&line, IS_SPACE))
		return (false);
	mtl->specular_map = load_texture(line);
	return (true);
}
