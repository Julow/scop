/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 12:49:02 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/25 14:46:39 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include "libft.h"
# include "gl.h"
# include "shader_loader.h"
# include "mesh_loader.h"
# include "texture_loader.h"

# define WIN_WIDTH			1900
# define WIN_HEIGHT			1000

# define WIN_TITLE			"Scop"

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
