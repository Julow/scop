/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 12:15:51 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/27 23:39:42 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "ft/ft_hmap.h"
#include "gl.h"
#include <stdlib.h>

static t_uint	send_texture(t_img const *img)
{
	t_uint			handle;

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

t_texture const	*load_texture(t_sub file_name)
{
	static t_hmap	*cache = NULL;
	t_img			img;
	t_hpair			tmp;

	if (cache == NULL)
		cache = ft_hmapnew(TEXTURE_CACHE_SIZE, &ft_djb2);
	if ((tmp = ft_hmapget(cache, file_name)).value != NULL)
		return (tmp.value);
	tmp = ft_hmapput(cache, file_name, NULL, sizeof(t_texture));
	if (!ft_loadimage(tmp.key, &img))
	{
		ft_hmaprem(cache, file_name, NULL);
		return (NULL);
	}
	ft_memcpy(tmp.value, &(t_texture){send_texture(&img)}, sizeof(t_texture));
	free(img.data);
	return (tmp.value);
}
