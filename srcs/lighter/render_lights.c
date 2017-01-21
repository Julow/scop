/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_lights.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:13:08 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/21 18:29:03 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighter.h"
#include "utils.h"

#define LIGHT_BUFF_SIZE		64

static t_point_light_component	*render_point_lights(t_lighter const *lighter,
									t_gbuffer *gbuffer,
									t_point_light_component *point_light)
{
	t_vec3			light_buff[LIGHT_BUFF_SIZE];
	uint32_t		i;

	i = 0;
	while (i < LIGHT_BUFF_SIZE && point_light)
	{
		light_buff[i++] = point_light->pos;
		light_buff[i++] = point_light->intensity;
		point_light = LIST_NEXT(point_light);
	}
	GBUFFER_BIND(gbuffer, LIGHT(gbuffer));
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, GBUFFER_BUFF_LIGHT_BACK(gbuffer));
	glUniform3fv(lighter->u_point_lights, i, (float*)light_buff); // TODO: improve
	glUniform1ui(lighter->u_point_light_count, i);
	glDisable(GL_DEPTH_TEST); // TODO: light fbo ?
	render_screen_quad();
	glEnable(GL_DEPTH_TEST);
	return (point_light);
}

void			render_lights(t_lighter const *lighter, t_gbuffer *gbuffer)
{
	t_point_light_component	*point_light;

	glUseProgram(lighter->point_light_shader.handle);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, gbuffer->buff_pos);
	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, gbuffer->buff_nor);
	glActiveTexture(GL_TEXTURE3);
	glBindTexture(GL_TEXTURE_2D, gbuffer->buff_col);
	point_light = lighter->point_lights.first;
	while ((point_light = render_point_lights(lighter, gbuffer, point_light)))
		gbuffer->buff_light_i = !gbuffer->buff_light_i;
}
