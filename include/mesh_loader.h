/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh_loader.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 12:11:38 by jaguillo          #+#    #+#             */
/*   Updated: 2015/10/14 15:11:31 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_LOADER_H
# define MESH_LOADER_H

typedef struct s_mesh		t_mesh;
typedef struct s_mesh_mtl	t_mesh_mtl;

// module: mesh_loader
// public require libft
// public require libft::vector
// public require libft::hmpa
// public require mtl_loader
// private require gl
// private require math_utils
// private require utils
// private extern require fcntl
// private extern require unistd

# include "ft_vector.h"
# include "mtl_loader.h"

# define MESH_CACHE_SIZE	10

struct			s_mesh
{
	t_uint				vao;
	t_uint				vbo;
	t_uint				ebo;
	t_mesh_mtl const	*mtl;
	int					mtl_count;
};

struct			s_mesh_mtl
{
	t_mtl const		*mtl;
	int				count;
};

/*
** Load a mesh from a file (.obj)
** -
** Return NULL on error
*/
t_mesh const	*load_mesh(t_sub file_name);

/*
** internal
*/
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
	t_bool			(*f)(t_sub, t_mesh_data*);
}				t_mesh_token;

t_bool			parse_mesh(char const *file, t_mesh_data *data);

/*
** parse_mesh_tokens.c
** parse_mesh_tokens_mtl.c
*/
t_bool			parse_v(t_sub line, t_mesh_data *data);
t_bool			parse_vn(t_sub line, t_mesh_data *data);
t_bool			parse_vt(t_sub line, t_mesh_data *data);
t_bool			parse_f(t_sub line, t_mesh_data *data);
t_bool			parse_mtllib(t_sub line, t_mesh_data *data);
t_bool			parse_usemtl(t_sub line, t_mesh_data *data);

/*
** build_mesh.c
** build_mtl.c
*/
t_bool			build_mesh(t_mesh_data *data);
t_bool			build_mtl(t_mesh_data *data, t_mesh *dst);

/*
** send_mesh.c
*/
t_bool			send_mesh(t_mesh_data *data, t_mesh *mesh);

#endif
