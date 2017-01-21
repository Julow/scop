/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gbuffer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:37:17 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/19 19:33:07 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GBUFFER_H
# define GBUFFER_H

# include "ft/gl.h"
# include "ft/libft.h"

typedef struct s_gbuffer			t_gbuffer;

/*
** ========================================================================== **
*/

struct			s_gbuffer
{
	GLuint			fbo;
	GLuint			buff_pos;
	GLuint			buff_nor;
	GLuint			buff_col;
	GLuint			buff_light[2];
	uint32_t		buff_light_i;
};

# define GBUFFER_ATT_POS		GL_COLOR_ATTACHMENT0
# define GBUFFER_ATT_NOR		GL_COLOR_ATTACHMENT1
# define GBUFFER_ATT_COL		GL_COLOR_ATTACHMENT2
# define GBUFFER_ATT_LIGHT(G)		(GL_COLOR_ATTACHMENT3 + (G)->buff_light_i)
# define GBUFFER_ATT_LIGHT_BACK(G)	(GL_COLOR_ATTACHMENT3 + 1-(G)->buff_light_i)

# define GBUFFER_BUFF_LIGHT(G)		((G)->buff_light[(G)->buff_light_i])
# define GBUFFER_BUFF_LIGHT_BACK(G)	((G)->buff_light[!(G)->buff_light_i])

/*
** Call gbuffer_bind with a variadic number of attachments
** (without the 'GBUFFER_ATT_' prefix)
*/
# define GBUFFER_BIND(G, ...)	_GBUFFER_L(G,FOR_EACH(_GBUFFER_P,,,##__VA_ARGS__))

bool			gbuffer_init(t_vec2u win_size, t_gbuffer *dst);

/*
** Bind the gbuffer to draw to attachments in 'attachs'
*/
void			gbuffer_bind(t_gbuffer *gbuffer, GLenum const *attachs,
					uint32_t attach_count);

/*
** -
*/

# define _GBUFFER_L(G,A)		_GBUFFER_ATTACH((G), ((GLenum const[]){A}))
# define _GBUFFER_ATTACH(G,A)	(gbuffer_bind(G, (A), ARRAY_LEN(A)))
# define _GBUFFER_P(ATT,_)		GBUFFER_ATT_##ATT,

#endif
