/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_renderer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 21:56:27 by juloo             #+#    #+#             */
/*   Updated: 2015/09/21 22:32:09 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "camera.h"

/*
** -
*/
#define LIGHT(x,y,z,a)				{0.f, a}, {x, y}, {z, 0.f}
#define SPOT(x,y,z,a,dx,dy,dz,c,o)	{1.f, a}, {c, o}, {x, y}, {z, dx}, {dy, dz}

/*
** ?omg
** import math
** out("#define SPOT_CUTOFF		%f\n" % math.cos(math.pi - (math.pi / 4)))
** out("#define SPOT_OUTCUTOFF	%f\n" % math.cos(math.pi - (math.pi / 5.2)))
*/
#define SPOT_CUTOFF		-0.707107
#define SPOT_OUTCUTOFF	-0.822984
/*
** ?end
*/

static t_vec2 const	g_lights[] = { // TMP
	LIGHT(20.f, 0.f, 20.f, 1000.f),
	SPOT(-700.f, 120.f, -750.f, 1000.f, 0.60083428991, 0.11971220728, -0.79035887006, SPOT_CUTOFF, SPOT_OUTCUTOFF),
};

static void		test_glsl_pre(t_shader const *shader, t_scop *scop, t_obj *obj)
{
	glUniformMatrix4fv(shader->loc[0], 2, GL_TRUE, (float*)obj_get_model(obj));
	glUniformMatrix4fv(shader->loc[1], 1, GL_TRUE, (float*)camera_get_view(&(scop->camera)));
	glUniformMatrix4fv(shader->loc[2], 1, GL_TRUE, (float*)&(scop->projection_m));
	glUniform3fv(shader->loc[3], 1, (float*)&(scop->camera.position));
	glUniform2fv(shader->loc[4], G_ARRAY_LEN(g_lights), (float*)g_lights);
	glUniform1i(shader->loc[5], G_ARRAY_LEN(g_lights));
}

static void		test_glsl_mtl(t_shader const *shader, t_scop *scop, t_obj *obj,
	t_mtl const *mtl)
{
	t_uint			tmp;

	if (mtl == NULL)
		return ;
	glActiveTexture(GL_TEXTURE0);
	if (mtl->ambient_map != NULL)
		tmp = mtl->ambient_map->handle;
	else
		tmp = 0;
	glBindTexture(GL_TEXTURE_2D, tmp);
	glUniform1i(shader->loc[6], 0);
	glUniform3fv(shader->loc[9], 1, (float*)&(mtl->ambient_color));
	glActiveTexture(GL_TEXTURE1);
	if (mtl->diffuse_map != NULL)
		tmp = mtl->diffuse_map->handle;
	else
		tmp = 0;
	glBindTexture(GL_TEXTURE_2D, tmp);
	glUniform1i(shader->loc[7], 1);
	glUniform3fv(shader->loc[10], 1, (float*)&(mtl->diffuse_color));
	glActiveTexture(GL_TEXTURE2);
	if (mtl->specular_map != NULL)
		tmp = mtl->specular_map->handle;
	else
		tmp = 0;
	glBindTexture(GL_TEXTURE_2D, tmp);
	glUniform1i(shader->loc[8], 2);
	glUniform3fv(shader->loc[11], 1, (float*)&(mtl->specular_color));
	glUniform1i(shader->loc[12], mtl->specular_exp);
	(void)scop;
	(void)obj;
}

void			simple_renderer(t_scop *scop, t_obj *obj)
{
	int						i;
	int						offset;

	glUseProgram(obj->shader->handle);
	test_glsl_pre(obj->shader, scop, obj);
	glBindVertexArray(obj->mesh->vao);
	offset = 0;
	i = -1;
	while (++i < obj->mesh->mtl_count)
	{
		test_glsl_mtl(obj->shader, scop, obj, obj->mesh->mtl[i].mtl);
		glDrawArrays(GL_TRIANGLES, offset, obj->mesh->mtl[i].count);
		offset += obj->mesh->mtl[i].count;
	}
}
