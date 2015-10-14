/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 11:54:03 by jaguillo          #+#    #+#             */
/*   Updated: 2015/10/14 15:15:24 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_LOADER_H
# define TEXTURE_LOADER_H

typedef struct s_texture	t_texture;

// module: texture_loader
// public require libft
// private require utils
// private require gl
// private require libft::buff
// private require libft::hmap
// private extern require stdlib
// private extern require fcntl

# include "libft.h"

# define TEXTURE_CACHE_SIZE	10

struct			s_texture
{
	t_uint			handle;
};

/*
** Load a texture from a file
** -
** Return NULL on error
*/
t_texture const	*load_texture(t_sub file_name);

/*
** ========================================================================== **
** Load an image file
** -
** Formats:
** .tga		24 or 32 bits		no color map and no compression
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
*/
t_bool			tga_parser(t_buff *buff, t_img *img);

/*
** Internal
*/
t_texture		*texture_cache_get(char const *file);
void			texture_cache_new(char const *file, t_texture *texture);

#endif
