/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_loader.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 13:16:16 by juloo             #+#    #+#             */
/*   Updated: 2015/12/10 19:45:00 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IMAGE_LOADER_H
# define FT_IMAGE_LOADER_H

# include "ft/libft.h"

/*
** ========================================================================== **
** Image loader
** -
** Supported formats:
** .tga		24 or 32 bits		no color map and no compression
** -
** Output 32 bits color map
*/

typedef struct	s_img
{
	uint32_t		*data;
	int				width;
	int				height;
}				t_img;

/*
** dst->data is allocated and can be free using free() function
** -
** Return true on success, false on error
*/
bool			ft_load_image(char const *file_name, t_img *dst);

#endif
