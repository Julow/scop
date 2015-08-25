/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 12:49:02 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/25 17:31:21 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include "libft.h"
# include "gl.h"
# include "shader_loader.h"
# include "mesh_loader.h"
# include "texture_loader.h"

# define WIN_RATIO			(3.f / 2.f)
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

typedef struct	s_scop
{
	GLFWwindow		*window;

// textures		:hmap<string, texture>
// meshes		:hmap<string, mesh>
// shaders		:hmap<string, shader>

// objects		:vector<obj>

	t_shader		test_shaders;
	t_obj			test_obj;
	t_texture		test_texture;
	t_mesh			test_mesh;
}				t_scop;

t_bool			init_window(t_scop *scop);

void			init_key_events(t_scop *scop);

#endif
