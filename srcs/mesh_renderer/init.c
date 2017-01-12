/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:46:42 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/12 16:00:52 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_mesh_renderer.h"
#include "shader_loader.h"

void			mesh_renderer_init(t_mesh_renderer *dst)
{
	t_shader		shader;

	if (!load_shader(SUBC("srcs/mesh_renderer/render.glsl"), &shader))
		HARD_ASSERT(false, "Failed to load shader");
	*dst = (t_mesh_renderer){
		{},
		LIST(t_mesh_renderer_component),
		shader,
		.u_model = glGetUniformLocation(shader.handle, "model"),
		.u_viewproj = glGetUniformLocation(shader.handle, "viewproj"),
		.u_diffuse_map = glGetUniformLocation(shader.handle, "diffuse_map"),
	};
}
