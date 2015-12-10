/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 13:06:50 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:45:00 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "mesh_loader.h"
# include "ft/libft.h"
# include "ft/ft_vector.h"
# include "ft/ft_hmap.h"

# define MESH_CACHE_SIZE	10

/*
** vbo_data:
** float[8]
** pos    tex  norm
** x y z  u v  nx ny nz
*/

/*
** face:
** int[9]
** v1       v2       v3
** v vt vn  v vt vn  v vt vn
*/

typedef struct	s_mesh_data
{
	t_vector		v;
	t_vector		vn;
	t_vector		vt;
	t_vector		f;
	t_hmap const	*mtllib;
	t_vector		mtl;
	t_vector		vbo_data;
	t_vector		ebo_data;
}				t_mesh_data;

/*
** parse_mesh.c
*/
typedef struct	s_mesh_token
{
	t_sub			token;
	bool			(*f)(t_sub, t_mesh_data*);
}				t_mesh_token;

bool			parse_mesh(char const *file, t_mesh_data *data);

/*
** parse_mesh_tokens.c
** parse_mesh_tokens_mtl.c
*/
bool			parse_v(t_sub line, t_mesh_data *data);
bool			parse_vn(t_sub line, t_mesh_data *data);
bool			parse_vt(t_sub line, t_mesh_data *data);
bool			parse_f(t_sub line, t_mesh_data *data);
bool			parse_mtllib(t_sub line, t_mesh_data *data);
bool			parse_usemtl(t_sub line, t_mesh_data *data);

/*
** build_mesh.c
** build_mtl.c
*/
bool			build_mesh(t_mesh_data *data);
bool			build_mtl(t_mesh_data *data, t_mesh *dst);

/*
** send_mesh.c
*/
bool			send_mesh(t_mesh_data *data, t_mesh *mesh);

#endif
