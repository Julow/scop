/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 13:06:50 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/12 15:25:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "ft/ft_vector.h"
# include "ft/libft.h"
# include "ft/set.h"

# include "mesh_loader.h"
# include "mtl_loader.h"

typedef struct s_cached_mesh		t_cached_mesh;

/*
** vbo_data:
** float[8]
** pos    tex  norm
** x y z  u v  nx ny nz
*/

/*
** face:
** uint[9]
** v1       v2       v3
** v vt vn  v vt vn  v vt vn
*/

typedef struct	s_mesh_data
{
	t_vector		v;
	t_vector		vn;
	t_vector		vt;
	t_vector		f;
	t_mtllib const	*mtllib;
	t_vector		mtl;
	t_vector		vbo_data;
	t_vector		ebo_data;
}				t_mesh_data;

struct			s_cached_mesh
{
	t_set_h			set_head;
	t_sub			file_name;
	t_mesh			mesh;
};

/*
** parse_mesh.c
*/
typedef struct	s_mesh_token
{
	t_sub			token;
	bool			(*f)(t_sub, t_mesh_data*);
}				t_mesh_token;

bool			parse_mesh(t_sub file, t_mesh_data *data);

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
