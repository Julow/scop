/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gbuffer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:38:45 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/23 16:19:32 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gbuffer.h"

static GLuint	g_attach(t_vec2u win_size, GLint internal_format,
					GLenum format, GLenum type, GLenum attachment)
{
	GLuint			buff;

	glGenTextures(1, &buff);
	glBindTexture(GL_TEXTURE_2D, buff);
	glTexImage2D(GL_TEXTURE_2D, 0, internal_format, win_size.x, win_size.y,
			0, format, type, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glFramebufferTexture2D(GL_FRAMEBUFFER, attachment, GL_TEXTURE_2D, buff, 0);
	return (buff);
}

bool			gbuffer_init(t_vec2u win_size, t_gbuffer *dst)
{
	glGenFramebuffers(1, &dst->fbo);
	glBindFramebuffer(GL_FRAMEBUFFER, dst->fbo);

	dst->buff_light_i = 0;
	dst->buff_pos = g_attach(win_size, GL_RGB16F, GL_RGB, GL_FLOAT, GBUFFER_ATT_POS);
	dst->buff_nor = g_attach(win_size, GL_RGB16F, GL_RGB, GL_FLOAT, GBUFFER_ATT_NOR);
	dst->buff_col = g_attach(win_size, GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, GBUFFER_ATT_COL);
	dst->buff_light[0] = g_attach(win_size, GL_RGB16F, GL_RGB, GL_FLOAT, GBUFFER_ATT_LIGHT(dst));
	dst->buff_light[1] = g_attach(win_size, GL_RGB16F, GL_RGB, GL_FLOAT, GBUFFER_ATT_LIGHT_BACK(dst));
	g_attach(win_size, GL_DEPTH_COMPONENT24, GL_DEPTH_COMPONENT, GL_FLOAT, GL_DEPTH_ATTACHMENT);

	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
	{
		ASSERT(false, "Failed to create framebuffer");
		return (false);
	}
	return (true);
}

void			gbuffer_bind(t_gbuffer *gbuffer, GLenum const *attachs,
					uint32_t attach_count)
{
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, gbuffer->fbo);
	glDrawBuffers(attach_count, attachs);
}
