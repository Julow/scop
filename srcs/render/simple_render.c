/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 21:56:27 by juloo             #+#    #+#             */
/*   Updated: 2015/12/04 13:34:44 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "shader.h"
#include "shader_loader.h"
#include "texture.h"
#include "mesh.h"
#include "mtl.h"
#include "gl.h"
#include "camera.h"
#include "utils.h"
#include "ft/ft_hmap.h"
#include <stdlib.h>

/*
** -
*/
#define LIGHT(x,y,z,a)				{0.f, a}, {x, y}, {z, 0.f}
#define SPOT(x,y,z,a,dx,dy,dz,c,o)	{1.f, a}, {c, o}, {x, y}, {z, dx}, {dy, dz}

static t_vec2 const	g_lights[] = {
	LIGHT(20.f, 0.f, 20.f, 1000.f),
	SPOT(-700.f, 120.f, -750.f, 1000.f, 0.6f, 0.12f, -0.79f, -0.5f, -0.6f),
};

static void		test_glsl_pre(t_shader const *shader,
					t_render_params const *params)
{
	UNIFORM(Matrix4fv, shader, "model", 1, false, (float*)params->top_matrix);
	UNIFORM(Matrix4fv, shader, "view", 1, true,
		(float*)camera_get_view(params->camera));
	UNIFORM(Matrix4fv, shader, "projection", 1, true,
		(float*)params->projection_m);
	UNIFORM(3fv, shader, "camera_pos", 1, (float*)&(params->camera->position));
	UNIFORM(2fv, shader, "lights", G_ARRAY_LEN(g_lights), (float*)g_lights);
	UNIFORM(1i, shader, "light_count", G_ARRAY_LEN(g_lights));
}

static void		test_glsl_mtl(t_shader const *shader, t_mtl const *mtl)
{
	if (mtl == NULL)
		return ;
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,
		(mtl->ambient_map != NULL) ? mtl->ambient_map->handle : 0);
	UNIFORM(1i, shader, "ambient_map", 0);
	UNIFORM(3fv, shader, "ambient_color", 1, (float*)&(mtl->ambient_color));
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D,
		(mtl->diffuse_map != NULL) ? mtl->diffuse_map->handle : 0);
	UNIFORM(1i, shader, "diffuse_map", 1);
	UNIFORM(3fv, shader, "diffuse_color", 1, (float*)&(mtl->diffuse_color));
	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D,
		(mtl->specular_map != NULL) ? mtl->specular_map->handle : 0);
	UNIFORM(1i, shader, "specular_map", 2);
	UNIFORM(3fv, shader, "specular_color", 1, (float*)&(mtl->specular_color));
	UNIFORM(1i, shader, "specular_exp", mtl->specular_exp);
}

void			simple_render(t_render_params const *params, t_mesh const *mesh)
{
	static t_shader const	*shader = NULL;
	int						i;
	int						offset;

	if (shader == NULL
		&& (shader = load_shader(SUBC("res/shaders/test.glsl"))) == NULL)
		exit(ft_error(1, "Cannot load shader"));
	glUseProgram(shader->handle);
	test_glsl_pre(shader, params);
	glBindVertexArray(mesh->vao);
	offset = 0;
	i = -1;
	while (++i < mesh->mtl_count)
	{
		test_glsl_mtl(shader, mesh->mtl[i].mtl);
		glDrawArrays(GL_TRIANGLES, offset, mesh->mtl[i].count);
		offset += mesh->mtl[i].count;
	}
}
