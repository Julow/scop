/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:28:18 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/16 17:55:28 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_mesh_renderer.h"

static t_mtl const	g_default_mtl = {
	NULL,
	NULL,
	NULL,
	VEC3(0.f, 0.f, 0.f),
	VEC3(0.05f, 0.25f, 0.3f),
	VEC3(0.5f, 0.5f, 0.5f),
	16,
};

static void		bind_map_or_color(t_texture const *map, t_vec3 const *color,
					GLuint default_map)
{
	if (map != NULL)
	{
		glBindTexture(GL_TEXTURE_2D, map->handle);
	}
	else
	{
		glBindTexture(GL_TEXTURE_2D, default_map);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 1, 1, GL_RGB, GL_FLOAT, color);
	}
}

static void		push_mtl(t_mesh_renderer *r, t_mtl const *mtl)
{
	glActiveTexture(GL_TEXTURE0);
	bind_map_or_color(mtl->diffuse_map, &mtl->diffuse_color,
			r->default_diffuse_map);
	glActiveTexture(GL_TEXTURE1);
	bind_map_or_color(mtl->specular_map, &mtl->specular_color,
			r->default_specular_map);
}

static void		draw_mesh(t_mesh_renderer *r, t_mesh const *mesh)
{
	uint32_t			offset;
	uint32_t			i;
	t_mesh_mtl const	*mtl;

	glBindVertexArray(mesh->vao);
	i = 0;
	offset = 0;
	while (i < mesh->mtl_count)
	{
		mtl = &mesh->mtl[i];
		push_mtl(r, (mtl->mtl == NULL) ? &g_default_mtl : mtl->mtl);
		glDrawArrays(GL_TRIANGLES, offset, mtl->count);
		offset += mtl->count;
		i++;
	}
}

void			mesh_render(t_mesh_renderer *renderer)
{
	t_mesh_renderer_component const	*mesh;

	mesh = LIST_IT(&renderer->meshes);
	glUseProgram(renderer->shader.handle);
	glUniformMatrix4fv(renderer->u_viewproj, 1, true,
			(float const*)&renderer->viewproj); // TODO: only when needed
	while ((mesh = LIST_NEXT(mesh)))
	{
		glUniformMatrix4fv(renderer->u_model, 1, false,
				(float const*)&mesh->model_m);
		draw_mesh(renderer, mesh->mesh);
	}
}
