/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 12:49:02 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/24 15:50:54 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include "libft.h"

# include "ft_loadimg.h"
# include "ft_loadmesh.h"
# include "ft_3dmath.h"

# define GLFW_INCLUDE_GLCOREARB
# include <GLFW/glfw3.h>

# define WIN_WIDTH			1900
# define WIN_HEIGHT			1000

# define WIN_TITLE			"Scop"

typedef struct	s_texture
{
	t_uint			handle;
}				t_texture;

typedef struct	s_obj
{
	t_mesh			*mesh;
	t_texture		*texture;
	// t_vec3			position;
	// t_vec3			rotation;
	// float			scale;
	// t_mat4			matrix_cache;
}				t_obj;

typedef struct	s_scop
{
	GLFWwindow		*window;

// textures		:hmap<string, texture>
// meshes		:hmap<string, mesh>
// shaders		:hmap<string, shader>

// objects		:vector<obj>

	t_uint			test_shaders;
	t_obj			test_obj;
	t_texture		test_texture;
	t_mesh			test_mesh;
	t_uint			test_mat_loc; // uniform location
}				t_scop;

/*
** create_mesh.c
*/
typedef struct	s_mesh_params
{
	float const		*vertices;
	int				vertice_size;
	t_uint const	*indices;
	int				indice_size;
}				t_mesh_params;

t_mesh			create_mesh(t_mesh_params params);

/*
** create_shader.c
*/
t_bool			create_shader(char const *vert, char const *frag, t_uint *p);

/*
** window.c
*/
t_bool			init_window(t_scop *scop);

/*
** callback.c
*/
void			init_callback(t_scop *scop);

/*
** utils
*/
t_ulong			ft_time(t_ulong start);

#endif
