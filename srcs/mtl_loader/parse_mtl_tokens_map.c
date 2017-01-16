/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mtl_tokens_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 17:25:33 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/16 17:40:47 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "texture_loader.h"

bool			map_ka_token(t_sub line, t_mtl *mtl)
{
	t_sub			word;

	word = SUB_START(line);
	if (!ft_subnext_is(line, &word, IS_WHITESPACE))
		return (false);
	mtl->ambient_map = load_texture(word);
	return (true);
}

bool			map_kd_token(t_sub line, t_mtl *mtl)
{
	t_sub			word;

	word = SUB_START(line);
	if (!ft_subnext_is(line, &word, IS_WHITESPACE))
		return (false);
	mtl->diffuse_map = load_texture(word);
	return (true);
}

bool			map_ks_token(t_sub line, t_mtl *mtl)
{
	t_sub			word;

	word = SUB_START(line);
	if (!ft_subnext_is(line, &word, IS_WHITESPACE))
		return (false);
	mtl->specular_map = load_texture(word);
	return (true);
}
