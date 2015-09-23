/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_renderer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 21:56:27 by juloo             #+#    #+#             */
/*   Updated: 2015/09/23 19:16:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "main.h"
#include "shader_loader.h"
#include "texture_loader.h"
#include "mesh_loader.h"
#include "mtl_loader.h"
#include "obj.h"
#include "resources.h"
#include "camera.h"
#include "ft_hmap.h"

/*
** -
*/
#define LIGHT(x,y,z,a)				{0.f, a}, {x, y}, {z, 0.f}
#define SPOT(x,y,z,a,dx,dy,dz,c,o)	{1.f, a}, {c, o}, {x, y}, {z, dx}, {dy, dz}

static t_vec2 const	g_lights[] = {
	LIGHT(20.f, 0.f, 20.f, 1000.f),
	SPOT(-700.f, 120.f, -750.f, 1000.f, 0.6f, 0.12f, -0.79f, -0.5f, -0.6f),
};

static void		test_glsl_pre(t_shader const *shader, t_scop *scop, t_obj *obj)
{
	glUniformMatrix4fv(UNIFORM(shader, "model"), 2, GL_TRUE,
		(float*)ft_transform_get(&(obj->transform)));
	glUniformMatrix4fv(UNIFORM(shader, "view"), 1, GL_TRUE,
		(float*)camera_get_view(&(scop->camera)));
	glUniformMatrix4fv(UNIFORM(shader, "projection"), 1, GL_TRUE,
		(float*)&(scop->projection_m));
	glUniform3fv(UNIFORM(shader, "camera_pos"), 1,
		(float*)&(scop->camera.position));
	glUniform2fv(UNIFORM(shader, "lights"), G_ARRAY_LEN(g_lights),
		(float*)g_lights);
	glUniform1i(UNIFORM(shader, "light_count"), G_ARRAY_LEN(g_lights));
}

static void		test_glsl_mtl(t_shader const *shader, t_scop *scop, t_obj *obj,
	t_mtl const *mtl)
{
	if (mtl == NULL)
		return ;
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,
		(mtl->ambient_map != NULL) ? mtl->ambient_map->handle : 0);
	glUniform1i(UNIFORM(shader, "ambient_map"), 0);
	glUniform3fv(UNIFORM(shader, "ambient_color"), 1,
		(float*)&(mtl->ambient_color));
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D,
		(mtl->diffuse_map != NULL) ? mtl->diffuse_map->handle : 0);
	glUniform1i(UNIFORM(shader, "diffuse_map"), 1);
	glUniform3fv(UNIFORM(shader, "diffuse_color"), 1,
		(float*)&(mtl->diffuse_color));
	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D,
		(mtl->specular_map != NULL) ? mtl->specular_map->handle : 0);
	glUniform1i(UNIFORM(shader, "specular_map"), 2);
	glUniform3fv(UNIFORM(shader, "specular_color"), 1,
		(float*)&(mtl->specular_color));
	glUniform1i(UNIFORM(shader, "specular_exp"), mtl->specular_exp);
	(void)scop;
	(void)obj;
}

void			simple_renderer(t_scop *scop, t_obj *obj)
{
	static t_shader const	*shader = NULL;
	int						i;
	int						offset;

	if (shader == NULL
		&& (shader = get_res(g_res_t.shader, SUBC("test.glsl"))) == NULL)
	{
		ft_printf("load shader\n\n");
		return ;
	}
	glUseProgram(shader->handle);
	test_glsl_pre(shader, scop, obj);
	glBindVertexArray(obj->mesh->vao);
	offset = 0;
	i = -1;
	while (++i < obj->mesh->mtl_count)
	{
		test_glsl_mtl(shader, scop, obj, obj->mesh->mtl[i].mtl);
		glDrawArrays(GL_TRIANGLES, offset, obj->mesh->mtl[i].count);
		offset += obj->mesh->mtl[i].count;
	}
}
