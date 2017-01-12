/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 14:16:37 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/12 15:29:23 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "ft/ft_in.h"
# include "ft/libft.h"
# include "ft/set.h"

# include "mtl.h"
# include "mtl_loader.h"

typedef struct s_cached_mtllib		t_cached_mtllib;
typedef struct s_mtl_token			t_mtl_token;

/*
** ========================================================================== **
*/

struct			s_cached_mtllib
{
	t_set_h			set_head;
	t_sub			file_name;
	t_mtllib		mtllib;
};

struct			s_mtl_token
{
	t_sub			name;
	bool			(*f)(t_sub line, t_mtl *mtl);
};

bool			parse_mtl(t_in *in, t_mtllib *mtl_lib);

bool			ambient_color_token(t_sub line, t_mtl *mtl);
bool			diffuse_color_token(t_sub line, t_mtl *mtl);
bool			specular_color_token(t_sub line, t_mtl *mtl);
bool			specular_exp_token(t_sub line, t_mtl *mtl);
bool			map_ka_token(t_sub line, t_mtl *mtl);
bool			map_kd_token(t_sub line, t_mtl *mtl);
bool			map_ks_token(t_sub line, t_mtl *mtl);

#endif
