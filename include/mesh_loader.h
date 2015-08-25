/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh_loader.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 12:11:38 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/25 17:07:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_LOADER_H
# define MESH_LOADER_H

# include "libft.h"
# include "ft_vector.h"
# include "math_utils.h"

typedef struct	s_mesh
{
	t_uint			vao;
	t_uint			vbo;
	t_uint			ebo;
	t_uint			count;
}				t_mesh;

/*
** Load a mesh from a file (.obj)
*/
t_bool			load_mesh(char const *file, t_mesh *dst);

/*
** internal
*/
typedef struct	s_face
{
	int				v1;
	int				vn1;
	int				vt1;
	int				v2;
	int				vn2;
	int				vt2;
	int				v3;
	int				vn3;
	int				vt3;
}				t_face;

typedef struct	s_mesh_vbo_data
{
	t_vec3			pos;
	t_vec3			col;
	t_vec2			tex;
	t_vec3			nor;
}				t_mesh_vbo_data;

typedef struct	s_mesh_ebo_data
{
	int				v1;
	int				v2;
	int				v3;
}				t_mesh_ebo_data;

typedef struct	s_mesh_data
{
	t_vector		v;
	t_vector		vn;
	t_vector		vt;
	t_vector		f;
	t_vector		vbo_data;
	t_vector		ebo_data;
}				t_mesh_data;

/*
** parse_mesh.c
*/
typedef struct	s_mesh_token
{
	t_sub			token;
	t_bool			(*f)(t_sub, t_mesh_data*);
}				t_mesh_token;

t_bool			parse_mesh(char const *file, t_mesh_data *data);

/*
** parse_mesh_tokens.c
*/
t_bool			parse_v(t_sub line, t_mesh_data *data);
t_bool			parse_vn(t_sub line, t_mesh_data *data);
t_bool			parse_vt(t_sub line, t_mesh_data *data);
t_bool			parse_f(t_sub line, t_mesh_data *data);

/*
** build_mesh.c
*/
t_bool			build_mesh(t_mesh_data *data);

/*
** send_mesh.c
*/
t_bool			send_mesh(t_mesh_data *data, t_mesh *mesh);

#endif
