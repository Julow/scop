/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:19:54 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/21 17:32:34 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighter.h"
#include "shader_loader.h"

bool			lighter_init(t_lighter *dst)
{
	t_shader		shader;

	if (!load_shader(SUBC("srcs/lighter/point_light.glsl"), &shader))
		return (ASSERT(!"Failed to load point_light.glsl"), false);
	*dst = (t_lighter){
		LIST(t_point_light_component),
		shader,
		glGetUniformLocation(shader.handle, "_u_point_lights"),
		glGetUniformLocation(shader.handle, "_u_point_light_count"),
	};
	glUseProgram(shader.handle);
	glUniform1i(glGetUniformLocation(shader.handle, "_u_light_back"), 0); // TODO: texture management
	glUniform1i(glGetUniformLocation(shader.handle, "_u_pos"), 1);
	glUniform1i(glGetUniformLocation(shader.handle, "_u_nor"), 2);
	glUniform1i(glGetUniformLocation(shader.handle, "_u_col"), 3);
	return (true);
}
