/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:46:42 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/16 17:55:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_mesh_renderer.h"
#include "shader_loader.h"

static GLuint	create_dummy_texture(void)
{
	GLuint			texture;

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1, 1, 0, GL_RGB, GL_FLOAT, NULL);
	return (texture);
}

void			mesh_renderer_init(t_mesh_renderer *dst)
{
	t_shader		shader;

	if (!load_shader(SUBC("srcs/mesh_renderer/render.glsl"), &shader))
		HARD_ASSERT(false, "Failed to load shader");
	*dst = (t_mesh_renderer){
		{},
		LIST(t_mesh_renderer_component),
		shader,
		create_dummy_texture(),
		create_dummy_texture(),
		.u_model = glGetUniformLocation(shader.handle, "_u_model"),
		.u_viewproj = glGetUniformLocation(shader.handle, "_u_viewproj"),
		.u_diffuse_map = glGetUniformLocation(shader.handle, "_u_diffuse_map"),
		.u_specular_map = glGetUniformLocation(shader.handle, "_u_specular_map"),
	};
	glUseProgram(shader.handle);
	glUniform1i(dst->u_diffuse_map, 0);
	glUniform1i(dst->u_specular_map, 1);
}
