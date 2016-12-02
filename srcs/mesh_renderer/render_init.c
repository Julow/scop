/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:27:57 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/01 19:52:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/gl.h"

#include "p_mesh_renderer.h"
#include "shader.h"
#include "shader_loader.h"

void			mesh_render_init(t_mesh_render *dst)
{
	t_shader const *const	shader = load_shader(SUBC("res/shaders/test.glsl"));

	HARD_ASSERT(shader != NULL, "Failed to load shader");
	*dst = (t_mesh_render){
		NULL,
		NULL,
		VEC3_0(),
		shader,
		.u_model = glGetUniformLocation(shader->handle, "model"),
		.u_view = glGetUniformLocation(shader->handle, "view"),
		.u_proj = glGetUniformLocation(shader->handle, "projection"),
		.u_camera_pos = glGetUniformLocation(shader->handle, "camera_pos"),
		.u_lights = glGetUniformLocation(shader->handle, "lights"),
		.u_light_count = glGetUniformLocation(shader->handle, "light_count"),
		.u_ambient_map = glGetUniformLocation(shader->handle, "ambient_map"),
		.u_ambient_color = glGetUniformLocation(shader->handle, "ambient_color"),
		.u_diffuse_map = glGetUniformLocation(shader->handle, "diffuse_map"),
		.u_diffuse_color = glGetUniformLocation(shader->handle, "diffuse_color"),
		.u_specular_map = glGetUniformLocation(shader->handle, "specular_map"),
		.u_specular_color = glGetUniformLocation(shader->handle, "specular_color"),
		.u_specular_exp = glGetUniformLocation(shader->handle, "specular_exp"),
	};
}
