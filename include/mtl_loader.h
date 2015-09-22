/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtl_loader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 15:08:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/22 08:17:19 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTL_LOADER_H
# define MTL_LOADER_H

# include "scop.h"
# include "math_utils.h"

/*
** newmtl <name>				Create a mtl
** Ka <float> <float> <float>	ambient
** Kd <float> <float> <float>	diffuse
** Ks <float> <float> <float>	specular
** Ns <float>					specular exponent
** map_Ka <file>				ambient map
** map_Kd <file>				diffuse map
** map_Ks <file>				specular map
*/

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

/*
** Load mtls from a file
*/
t_bool			load_mtl(char const *file, t_hmap **mtl);

/*
** internal
*/
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
