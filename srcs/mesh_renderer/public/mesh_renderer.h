/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh_renderer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 12:15:49 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/11 18:02:28 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_RENDERER_H
# define MESH_RENDERER_H

# include "ft/ft_list.h"
# include "ft/libft.h"
# include "ft/math_mat4.h"

# include "mesh.h"
# include "obj.h"
# include "shader.h"

typedef struct s_mesh_renderer				t_mesh_renderer;
typedef struct s_mesh_renderer_component	t_mesh_renderer_component;
typedef t_sub								*t_mesh_renderer_component_param;

/*
** ========================================================================== **
** Mesh renderer
*/

/*
** Renderer object
*/
struct			s_mesh_renderer
{
	t_mat4			viewproj;
	t_list			meshes;
	t_shader const	*shader;
	t_uniform_loc	u_model;
	t_uniform_loc	u_viewproj;
	t_uniform_loc	u_diffuse_map;
};

void			mesh_renderer_init(t_mesh_renderer *dst);

/*
** Render all the meshes
*/
void			mesh_render(t_mesh_renderer *renderer);

/*
** Component
** (list item)
*/
struct			s_mesh_renderer_component
{
	t_obj_component	c;
	t_mesh_renderer	*r;
	t_mesh const	*mesh;
	t_mat4			model_m;
};

/*
** Create a mesh_renderer_component
*/
t_obj_component	*mesh_renderer_component_create(
					t_mesh_renderer_component_param const *param,
					t_mesh_renderer *r);

#endif
