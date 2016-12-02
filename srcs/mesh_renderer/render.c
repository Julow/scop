/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:39:46 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/02 11:56:19 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/gl.h"

#include "mesh.h"
#include "obj.h"
#include "p_mesh_renderer.h"

/*
** -
*/
#define LIGHT(x,y,z,a)				{0.f, a}, {x, y}, {z, 0.f}
#define SPOT(x,y,z,a,dx,dy,dz,c,o)	{1.f, a}, {c, o}, {x, y}, {z, dx}, {dy, dz}

static t_vec2 const	g_lights[] = {
	LIGHT(20.f, 20.f, 20.f, 1000.f),
	SPOT(-700.f, 120.f, -750.f, 1000.f, 0.6f, 0.12f, -0.79f, -0.5f, -0.6f),
};

static void		init_global_uniforms(t_mesh_render *r)
{
	glUniformMatrix4fv(r->u_view, 1, true, (float const*)r->view);
	glUniformMatrix4fv(r->u_proj, 1, true, (float const*)r->proj);
	glUniform3fv(r->u_camera_pos, 1, (float const*)&r->camera_pos);
	glUniform2fv(r->u_lights, ARRAY_LEN(g_lights), (float const*)&g_lights);
	glUniform1i(r->u_light_count, ARRAY_LEN(g_lights));
}

static void		init_mtl_uniforms(t_mesh_render *r, t_mtl const *mtl)
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,
			(mtl->ambient_map != NULL) ? mtl->ambient_map->handle : 0);
	glUniform1i(r->u_ambient_map, 0);
	glUniform3fv(r->u_ambient_color, 1, (float const*)&mtl->ambient_color);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D,
			(mtl->diffuse_map != NULL) ? mtl->diffuse_map->handle : 0);
	glUniform1i(r->u_diffuse_map, 1);
	glUniform3fv(r->u_diffuse_color, 1, (float const*)&mtl->diffuse_color);
	glActiveTexture(GL_TEXTURE3);
	glBindTexture(GL_TEXTURE_2D,
			(mtl->specular_map != NULL) ? mtl->specular_map->handle : 0);
	glUniform1i(r->u_specular_map, 2);
	glUniform3fv(r->u_specular_color, 1, (float const*)&mtl->specular_color);
	glUniform1i(r->u_specular_exp, mtl->specular_exp);
}

void			mesh_renderer_render(t_mesh_renderer *r, t_mat4 const *model)
{
	uint32_t			i;
	uint32_t			offset;
	t_mesh_mtl const	*mtl;

	glUseProgram(r->r->shader->handle);
	init_global_uniforms(r->r);
	glUniformMatrix4fv(r->r->u_model, 1, false, (float const*)model);
	glBindVertexArray(r->mesh->vao);
	offset = 0;
	i = 0;
	while (i < r->mesh->mtl_count)
	{
		mtl = &r->mesh->mtl[i];
		if (mtl->mtl != NULL)
			init_mtl_uniforms(r->r, mtl->mtl);
		glDrawArrays(GL_TRIANGLES, offset, mtl->count);
		offset += mtl->count;
		i++;
	}
}
