/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 12:49:02 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/18 14:56:13 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include "libft.h"

# include "ft_loadimg.h"

# define GLFW_INCLUDE_GLCOREARB
# include <GLFW/glfw3.h>

# define WIN_WIDTH		500
# define WIN_HEIGHT		400

# define WIN_TITLE		"Scop"

typedef struct	s_mesh
{
	t_uint			vao;
	t_uint			vbo;
	t_uint			ebo;
	t_uint			count;
}				t_mesh;

typedef struct	s_texture
{
	t_uint			handle;
}				t_texture;

typedef struct	s_obj
{
	t_mesh			*mesh;
	t_texture		*texture;
}				t_obj;

typedef struct	s_scop
{
	GLFWwindow		*window;
	t_uint			test_shaders;
	t_obj			test_obj;
	t_texture		test_texture;
	t_mesh			test_mesh;
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
