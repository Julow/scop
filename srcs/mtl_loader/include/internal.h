/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 14:16:37 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:45:00 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "mtl_loader.h"
# include "ft/libft.h"
# include "mtl.h"

# define MTLLIB_SIZE		20
# define MTL_CACHE_SIZE		10

typedef struct	s_mtl_token
{
	t_sub			name;
	bool			(*f)(t_sub line, t_mtl *mtl);
}				t_mtl_token;

bool			parse_mtl(int fd, t_hmap *mtl);

bool			ambient_color_token(t_sub line, t_mtl *mtl);
bool			diffuse_color_token(t_sub line, t_mtl *mtl);
bool			specular_color_token(t_sub line, t_mtl *mtl);
bool			specular_exp_token(t_sub line, t_mtl *mtl);
bool			map_ka_token(t_sub line, t_mtl *mtl);
bool			map_kd_token(t_sub line, t_mtl *mtl);
bool			map_ks_token(t_sub line, t_mtl *mtl);

#endif
