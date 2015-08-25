/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 11:54:03 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/25 12:53:53 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_LOADER_H
# define TEXTURE_LOADER_H

# include "libft.h"

typedef struct	s_texture
{
	t_uint			handle;
}				t_texture;

/*
** Load a texture from a file
*/
t_bool			load_texture(char const *file, t_texture *texture);

/*
** ========================================================================== **
** Load an image file
** -
** Supported formats:
** .tga		(32 bits, no color map, uncompressed)
*/

typedef struct	s_img
{
	t_byte			*data;
	int				width;
	int				height;
}				t_img;

# define LOAD_IMAGE_BUFF	512

typedef struct	s_imgtype
{
	t_sub			ext;
	t_bool			(*f)(t_buff *buff, t_img *img);
}				t_imgtype;

/*
** Load an image file and fill 'img'
** Return false if an error occur
*/
t_bool			ft_loadimage(char const *file, t_img *img);

/*
** Load a .tga file
** no color map, 32 bit, alpha
*/
t_bool			tga_parser(t_buff *buff, t_img *img);

#endif
