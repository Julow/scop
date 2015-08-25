/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 12:49:02 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/25 19:36:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include "libft.h"
# include "ft_vector.h"
# include "ft_hmap.h"
# include "gl.h"
# include "shader_loader.h"
# include "mesh_loader.h"
# include "texture_loader.h"

# define WIN_RATIO			1.f
// # define WIN_RATIO			(3.f / 2.f)
# define WIN_HEIGHT			800
# define WIN_WIDTH			((int)(WIN_HEIGHT * WIN_RATIO))

# define WIN_TITLE			"Scop"

# define PERSPECTIVE_FOV	42.f
# define PERSPECTIVE_NEAR	0.01f
# define PERSPECTIVE_FAR	1000.f

typedef struct	s_obj
{
	t_mesh const	*mesh;
	t_texture const	*texture;
	t_shader const	*shader;
	// t_vec3			position;
	// t_vec3			rotation;
	// float			scale;
	// t_mat4			matrix_cache;
}				t_obj;

# define OBJ(m,t,s)			((t_obj){(m), (t), (s), 0, 0, 0, 0})

typedef struct	s_scop
{
	GLFWwindow		*window;
	ft_hmap			*textures;
	ft_hmap			*meshes;
	ft_hmap			*shaders;
	ft_vector		objects;
}				t_scop;

t_bool			init_window(t_scop *scop);

void			init_key_events(t_scop *scop);

#else
# pragma message "lol"
#endif
