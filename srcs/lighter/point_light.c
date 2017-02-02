/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:05:33 by jaguillo          #+#    #+#             */
/*   Updated: 2017/02/02 17:11:28 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_lighter.h"
#include "shader_loader.h"

#include <stddef.h>

/*
** ?omg
** import math
** from itertools import *
** #
** CIRCLE_VERTICE_COUNT = 12
** #
** def circle_vertice(i):
** 	d = math.pi * i * 2 / CIRCLE_VERTICE_COUNT
** 	return (math.cos(d), math.sin(d), 0)
** #
** out("\n")
** out("static float const	g_point_vertices[] = {\n")
** for v in chain(
** 		[(0, 0, 0)],
** 		map(circle_vertice, range(0, CIRCLE_VERTICE_COUNT)),
** 		[circle_vertice(0)]
** 	):
** 	out("\t%f, %f, %f,\n" % v)
** out("};\n\n")
*/

static float const	g_point_vertices[] = {
	0.000000, 0.000000, 0.000000,
	1.000000, 0.000000, 0.000000,
	0.866025, 0.500000, 0.000000,
	0.500000, 0.866025, 0.000000,
	0.000000, 1.000000, 0.000000,
	-0.500000, 0.866025, 0.000000,
	-0.866025, 0.500000, 0.000000,
	-1.000000, 0.000000, 0.000000,
	-0.866025, -0.500000, 0.000000,
	-0.500000, -0.866025, 0.000000,
	-0.000000, -1.000000, 0.000000,
	0.500000, -0.866025, 0.000000,
	0.866025, -0.500000, 0.000000,
	1.000000, 0.000000, 0.000000,
};

/*
** ?end
*/

void			render_point_lights(t_lighter *lighter)
{
	glUseProgram(lighter->point_shader.handle);
	glUniformMatrix4fv(lighter->point_u_view_m, 1, true,
			(float const*)&lighter->view_m); // TODO: only when needed
	glUniformMatrix4fv(lighter->point_u_proj_m, 1, true,
			(float const*)&lighter->proj_m); // TODO: only when needed
	check_point_vbo(lighter);
	glBindVertexArray(lighter->point_vao);
	glDrawArraysInstanced(GL_TRIANGLE_FAN, 0, lighter->point_circle_length,
			lighter->point_lights.length);
}

bool			setup_point_lights(t_lighter *dst)
{
	GLuint			circle_vbo;

	dst->point_lights = LIST(t_point_light_component);

	if (!load_shader(SUBC("srcs/lighter/render_point_light.glsl"),
			&dst->point_shader))
		return (ASSERT(!"Failed to load render_point_light.glsl"), false);
	glUseProgram(dst->point_shader.handle);
	glUniform1i(glGetUniformLocation(dst->point_shader.handle, "_u_pos"), 0); // TODO: texture management
	glUniform1i(glGetUniformLocation(dst->point_shader.handle, "_u_nor"), 1);
	glUniform1i(glGetUniformLocation(dst->point_shader.handle, "_u_col"), 2);
	dst->point_u_view_m = glGetUniformLocation(dst->point_shader.handle, "_u_view_m");
	dst->point_u_proj_m = glGetUniformLocation(dst->point_shader.handle, "_u_proj_m");
	dst->point_circle_length = ARRAY_LEN(g_point_vertices) / 3;
	dst->flags |= LIGHTER_F_POINT_VBO_INVALID;

	glGenVertexArrays(1, &dst->point_vao);
	glBindVertexArray(dst->point_vao);

	glGenBuffers(1, &circle_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, circle_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_point_vertices),
			&g_point_vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, 3 * sizeof(float), V(0));

	glGenBuffers(1, &dst->point_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, dst->point_vbo);
	// glBufferData(GL_ARRAY_BUFFER, 0, NULL, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, false, sizeof(t_point_light_data),
			V(offsetof(t_point_light_data, pos)));
	glVertexAttribDivisor(1, 1);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, false, sizeof(t_point_light_data),
			V(offsetof(t_point_light_data, intensity)));
	glVertexAttribDivisor(2, 1);
	return (true);
}

void			check_point_vbo(t_lighter *lighter)
{
	t_point_light_data		buff[lighter->point_lights.length];
	t_point_light_component	*l;
	uint32_t				i;

	if (!(lighter->flags & LIGHTER_F_POINT_VBO_INVALID))
		return ;
	l = LIST_IT(&lighter->point_lights);
	i = 0;
	while ((l = LIST_NEXT(l)))
	{
		l->index = i;
		buff[i++] = l->data;
	}
	glBindBuffer(GL_ARRAY_BUFFER, lighter->point_vbo);
	glBufferData(GL_ARRAY_BUFFER, S(t_point_light_data, i), buff, GL_DYNAMIC_DRAW);
	lighter->flags &= ~LIGHTER_F_POINT_VBO_INVALID;
	TRACE("point_vbo realloc");
}
