/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_lights.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:13:08 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/30 14:27:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighter.h"
#include "utils.h"

// TODO: share macro with glsl code
#define POINT_LIGHT_BUFF		64
#define SPOT_LIGHT_BUFF			64

static t_point_light_component const
				*load_point_lights(
					t_lighter const *lighter,
					t_point_light_component const *point_light)
{
	uint32_t		i;
	t_vec3			buff[POINT_LIGHT_BUFF];

	i = 0;
	while (point_light && i < POINT_LIGHT_BUFF)
	{
		buff[i++] = point_light->pos;
		buff[i++] = point_light->intensity;
		point_light = LIST_NEXT(point_light);
	}
	glUniform3fv(lighter->u_point_lights, i, (float*)buff);
	glUniform1ui(lighter->u_point_light_count, i);
	return (point_light);
}

static t_spot_light_component const
				*load_spot_lights(
					t_lighter const *lighter,
					t_spot_light_component const *spot_light)
{
	uint32_t		i;
	t_vec3			buff[SPOT_LIGHT_BUFF];

	i = 0;
	while (spot_light && i < SPOT_LIGHT_BUFF)
	{
		buff[i++] = spot_light->pos;
		buff[i++] = spot_light->dir;
		buff[i++] = spot_light->intensity;
		buff[i++] = VEC3(spot_light->cutoff.x, spot_light->cutoff.y, 0.f);
		spot_light = LIST_NEXT(spot_light);
	}
	glUniform3fv(lighter->u_spot_lights, i, (float*)buff);
	glUniform1ui(lighter->u_spot_light_count, i);
	return (spot_light);
}

void			render_lights(t_lighter const *lighter, t_gbuffer *gbuffer)
{
	t_point_light_component const	*point_light;
	t_spot_light_component const	*spot_light;

	point_light = lighter->point_lights.first;
	spot_light = lighter->spot_lights.first;
	if (!point_light && !spot_light)
		return ;
	glUseProgram(lighter->render_shader.handle);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, gbuffer->buff_pos);
	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, gbuffer->buff_nor);
	glActiveTexture(GL_TEXTURE3);
	glBindTexture(GL_TEXTURE_2D, gbuffer->buff_col);
	while (true)
	{
		// TODO: improve (using fbo)
		point_light = load_point_lights(lighter, point_light);
		spot_light = load_spot_lights(lighter, spot_light);

		GBUFFER_BIND(gbuffer, LIGHT(gbuffer));
		glDisable(GL_DEPTH_TEST);
		render_screen_quad();
		glEnable(GL_DEPTH_TEST);

		if (!point_light && !spot_light)
			break ;
		gbuffer->buff_light_i = !gbuffer->buff_light_i;
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, GBUFFER_BUFF_LIGHT_BACK(gbuffer));
	}
}
