/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:46:42 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/11 17:53:33 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_mesh_renderer.h"
#include "shader_loader.h"

void			mesh_renderer_init(t_mesh_renderer *dst)
{
	t_shader const *const	shader = load_shader(SUBC("srcs/mesh_renderer/render.glsl")); // TODO: improve

	HARD_ASSERT(shader != NULL, "Failed to load shader");
	*dst = (t_mesh_renderer){
		{},
		LIST(t_mesh_renderer_component),
		shader,
		.u_model = glGetUniformLocation(shader->handle, "model"),
		.u_viewproj = glGetUniformLocation(shader->handle, "viewproj"),
		.u_diffuse_map = glGetUniformLocation(shader->handle, "diffuse_map"),
	};
}
