/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh_renderer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:12:37 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/25 14:36:11 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_RENDERER_H
# define MESH_RENDERER_H

# include "ft/math_mat4.h"
# include "ft/math_vec3.h"

# include "obj.h"
# include "shader.h"

typedef struct s_mesh_render		t_mesh_render;
typedef struct s_mesh_renderer		t_mesh_renderer;

/*
** ========================================================================== **
*/

/*
** Mesh render object
*/
struct			s_mesh_render
{
	t_mat4 const	*view;
	t_mat4 const	*proj; // TODO: viewproj
	t_vec3			camera_pos;
	t_shader const	*shader;
	t_uniform_loc	u_model;
	t_uniform_loc	u_view;
	t_uniform_loc	u_proj;
	t_uniform_loc	u_camera_pos;
	t_uniform_loc	u_lights;
	t_uniform_loc	u_light_count;
	t_uniform_loc	u_ambient_map;
	t_uniform_loc	u_ambient_color;
	t_uniform_loc	u_diffuse_map;
	t_uniform_loc	u_diffuse_color;
	t_uniform_loc	u_specular_map;
	t_uniform_loc	u_specular_color;
	t_uniform_loc	u_specular_exp;
};

void			mesh_render_init(t_mesh_render *dst);

/*
** Mesh renderer (to be attached on an object)
*/
struct			s_mesh_renderer
{
	t_obj_renderer	renderer;
	t_mesh_render	*r;
	t_mesh const	*mesh;
};

t_obj_renderer	*create_mesh_renderer(t_mesh_render *r, t_mesh const *mesh);

#endif
