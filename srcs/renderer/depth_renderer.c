/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depth_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 23:27:24 by juloo             #+#    #+#             */
/*   Updated: 2015/11/04 23:54:33 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderers.h"
#include "gl.h"
#include "shader_loader.h"
#include "shader.h"
#include "camera.h"

static void		depth_glsl_pre(t_shader const *shader,
					t_render_params const *params, t_obj *obj)
{
	UNIFORM(Matrix4fv, shader, "model", 1, GL_TRUE, (float*)ft_transform_get(&(obj->transform)));
	UNIFORM(Matrix4fv, shader, "view", 1, GL_TRUE, (float*)camera_get_view(params->camera));
	UNIFORM(Matrix4fv, shader, "projection", 1, GL_TRUE, (float*)params->projection_m);
	UNIFORM(3fv, shader, "camera_pos", 1, (float*)&(params->camera->position));
}

static void		depth_renderer(t_render_params const *params, t_obj *obj)
{
	static t_shader const	*shader = NULL;
	int						i;
	int						offset;

	if (shader == NULL
		&& (shader = load_shader(SUBC("depth.glsl"))) == NULL)
		return ;
	glUseProgram(shader->handle);
	depth_glsl_pre(shader, params, obj);
	glBindVertexArray(obj->mesh->vao);
	offset = 0;
	i = -1;
	while (++i < obj->mesh->mtl_count)
		offset += obj->mesh->mtl[i].count;
	glDrawArrays(GL_TRIANGLES, 0, offset);
}

t_obj			*depth_renderer_init(void)
{
	t_obj *const	obj = MAL1(t_obj);

	obj->render = &depth_renderer;
	return (obj);
}
