/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 12:15:51 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/12 15:41:12 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/gl.h"
#include "ft/img.h"
#include "ft/img_loader.h"
#include "ft/set.h"

#include "p_texture_loader.h"
#include "texture_loader.h"

#include <stdlib.h>

static uint32_t	send_texture(t_img const *img)
{
	uint32_t			handle;

	glGenTextures(1, &handle);
	glBindTexture(GL_TEXTURE_2D, handle);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img->width, img->height, 0, GL_BGRA,
		GL_UNSIGNED_BYTE, img->data);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	return (handle);
}

static int		cached_texture_cmp(t_cached_texture const *t, t_sub const *key)
{
	return (SUB_CMP(t->file_name, *key));
}

t_texture const	*load_texture(t_sub file_name)
{
	static t_set		cache = SET(&cached_texture_cmp, 0);
	t_cached_texture	*t;
	t_img				img;

	t = ft_set_get(&cache, &file_name);
	if (t == NULL)
	{
		if (!ft_load_img(file_name, &img))
			return (NULL);
		t = MALLOC(sizeof(t_cached_texture) + file_name.length);
		memcpy(ENDOF(t), file_name.str, file_name.length);
		*t = (t_cached_texture){
			SET_HEAD(),
			SUB(ENDOF(t), file_name.length),
			{ send_texture(&img) },
		};
		free(img.data);
	}
	return (&t->texture);
}
