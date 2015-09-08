/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 12:15:51 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/08 15:48:28 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_loader.h"
#include "scop.h"
#include <stdlib.h>

t_bool			load_texture(char const *file, t_texture *texture)
{
	t_img			img;

	if (!ft_loadimage(file, &img))
		return (ft_fdprintf(2, "Error: %s: Cannot load textures\n", file),
			false);
	glGenTextures(1, &(texture->handle));
	glBindTexture(GL_TEXTURE_2D, texture->handle);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.width, img.height, 0, GL_BGRA,
		GL_UNSIGNED_BYTE, img.data);
	glGenerateMipmap(GL_TEXTURE_2D);
	free(img.data);
	glBindTexture(GL_TEXTURE_2D, 0);
	return (true);
}
