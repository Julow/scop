/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadmesh.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 16:48:03 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/22 18:24:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LOADMESH_H
# define FT_LOADMESH_H

# include "libft.h"
# include "ft_3dmath.h"

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
	int				v2;
	int				v3;
	int				vn1;
	int				vn2;
	int				vn3;
	int				vt1;
	int				vt2;
	int				vt3;
}				t_face;

typedef struct	s_mesh_data
{
	t_tab			v; // :vector<vec3>
	t_tab			vn; // :vector<vec2>
	t_tab			vt; // :vector<vec3>
	t_tab			f; // :vector<face>
}				t_mesh_data;

/*
** Load a mesh from a file (.obj)
*/
t_bool			ft_loadmesh(char const *file, t_mesh *dst);

#endif
