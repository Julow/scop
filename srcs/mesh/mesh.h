/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 13:02:27 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/25 15:00:39 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_H
# define MESH_H

# include "ft/libft.h"
# include "mtl.h"

typedef struct s_mesh		t_mesh;
typedef struct s_mesh_mtl	t_mesh_mtl;

struct			s_mesh
{
	uint32_t			vao;
	uint32_t			vbo;
	uint32_t			ebo;
	t_mesh_mtl const	*mtl;
	uint32_t			mtl_count;
};

struct			s_mesh_mtl
{
	t_mtl const		*mtl;
	uint32_t		count;
};

#endif
