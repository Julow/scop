/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 13:02:27 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/27 23:39:32 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_H
# define MESH_H

typedef struct s_mesh		t_mesh;
typedef struct s_mesh_mtl	t_mesh_mtl;

# include "ft/libft.h"
# include "mtl.h"

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

#endif
