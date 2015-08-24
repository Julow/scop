/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadmesh.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 16:48:03 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/24 18:16:45 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LOADMESH_H
# define FT_LOADMESH_H

# include "libft.h"
# include "ft_3dmath.h"
# include "ft_vector.h"

# define MEM_EQU(a,b,s)		(ft_memcmp((a), (b), (s)) == 0)

typedef struct	s_mesh
{
	t_uint			vao;
	t_uint			vbo;
	t_uint			ebo;
	t_uint			count;
}				t_mesh;

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
	t_vector		v; // :vector<vec3>
	t_vector		vn; // :vector<vec3>
	t_vector		vt; // :vector<vec2>
	t_vector		f; // :vector<face>
	t_vector		vbo_data; // :vector<tuple<vec3, vec3, vec2, vec3>>
	t_vector		ebo_data; // :vector<tuple<int, int, int>>
}				t_mesh_data;

/*
** Load a mesh from a file (.obj)
*/
t_bool			ft_loadmesh(char const *file, t_mesh *dst);

/*
** utils
*/
int				ft_subint(t_sub sub, int *dst);

#endif
