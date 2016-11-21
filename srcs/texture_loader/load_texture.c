/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 12:15:51 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/21 17:55:23 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_hmap.h"
#include "ft/gl.h"
#include "ft/img.h"
#include "ft/img_loader.h"

#include "texture_loader.h"

#include <stdlib.h>

#define TEXTURE_CACHE_SIZE		10

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

t_texture const	*load_texture(t_sub file_name)
{
	static t_hmap	*cache = NULL;
	t_img			img;
	t_hpair			tmp;

	if (cache == NULL)
		cache = ft_hmapnew(TEXTURE_CACHE_SIZE, &ft_djb2);
	if ((tmp = ft_hmapget(cache, file_name)).value != NULL)
		return (tmp.value);
	if (!ft_load_img(file_name, &img))
		return (NULL);
	tmp = ft_hmapput(cache, file_name, NULL, sizeof(t_texture));
	ft_memcpy(tmp.value, &(t_texture){send_texture(&img)}, sizeof(t_texture));
	free(img.data);
	return (tmp.value);
}
