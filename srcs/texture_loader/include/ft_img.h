/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 14:27:32 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/03 14:28:56 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IMG_H
# define FT_IMG_H

# include "libft.h"
# include "ft_buff.h"

/*
** ========================================================================== **
** Load an image file
** -
** Formats:
** .tga		24 or 32 bits		no color map and no compression
** -
** TODO: move it in it's module
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

#endif
