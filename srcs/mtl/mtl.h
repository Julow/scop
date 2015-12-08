/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 14:11:54 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/08 17:04:17 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTL_H
# define MTL_H

typedef struct s_mtl		t_mtl;

# include "ft/math.h"
# include "texture.h"

struct			s_mtl
{
	t_texture const	*ambient_map;
	t_texture const	*diffuse_map;
	t_texture const	*specular_map;
	t_vec3			ambient_color;
	t_vec3			diffuse_color;
	t_vec3			specular_color;
	int				specular_exp;
};

#endif
