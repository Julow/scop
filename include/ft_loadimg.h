/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadimg.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 11:54:03 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/17 18:24:31 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LOADIMG_H
# define FT_LOADIMG_H

# include "libft.h"

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

/*
** Load an image file into 'img'
** Return false if an error occur
*/
t_bool			ft_loadimage(char const *file, t_img *img);

#endif
