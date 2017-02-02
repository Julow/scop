/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:12:00 by jaguillo          #+#    #+#             */
/*   Updated: 2017/02/02 17:15:57 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighter.h"
#include "p_lighter.h"

bool			lighter_init(t_lighter *dst)
{
	memset(dst, 0, sizeof(t_lighter));
	return (setup_point_lights(dst));
}

void			render_lights(t_lighter *lighter, t_gbuffer *gbuffer)
{
	GBUFFER_BIND(gbuffer, LIGHT(gbuffer));
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, gbuffer->buff_pos);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, gbuffer->buff_nor);
	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, gbuffer->buff_col);

	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);
	glDisable(GL_DEPTH_TEST);

	render_point_lights(lighter);

	glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
}
