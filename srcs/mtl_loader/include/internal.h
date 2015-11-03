/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 14:16:37 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/03 14:17:34 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "mtl_loader.h"
# include "libft.h"
# include "mtl.h"

# define MTLLIB_SIZE		20
# define MTL_CACHE_SIZE		10

typedef struct	s_mtl_token
{
	t_sub			name;
	t_bool			(*f)(t_sub line, t_mtl *mtl);
}				t_mtl_token;

t_bool			parse_mtl(int fd, t_hmap *mtl);

t_bool			ambient_color_token(t_sub line, t_mtl *mtl);
t_bool			diffuse_color_token(t_sub line, t_mtl *mtl);
t_bool			specular_color_token(t_sub line, t_mtl *mtl);
t_bool			specular_exp_token(t_sub line, t_mtl *mtl);
t_bool			map_ka_token(t_sub line, t_mtl *mtl);
t_bool			map_kd_token(t_sub line, t_mtl *mtl);
t_bool			map_ks_token(t_sub line, t_mtl *mtl);

#endif
