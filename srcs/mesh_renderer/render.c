/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:28:18 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/11 19:43:31 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_mesh_renderer.h"

static void		draw_mesh(t_mesh const *mesh)
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
		if (mtl->mtl != NULL)
			; // write mtl uniforms
		else
			; // default mtl
		glDrawArrays(GL_TRIANGLES, offset, mtl->count);
		offset += mtl->count;
		i++;
	}
}

void			mesh_render(t_mesh_renderer *renderer)
{
	t_mesh_renderer_component const	*mesh;

	mesh = LIST_IT(&renderer->meshes);
	glUseProgram(renderer->shader->handle);
	glUniformMatrix4fv(renderer->u_viewproj, 1, true,
			(float const*)&renderer->viewproj); // TODO: only when needed
	while ((mesh = LIST_NEXT(mesh)))
	{
		glUniformMatrix4fv(renderer->u_model, 1, false,
				(float const*)&mesh->model_m);
		draw_mesh(mesh->mesh);
	}
}
