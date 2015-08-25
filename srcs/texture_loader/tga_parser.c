/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 11:51:02 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/17 19:17:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_loadimg.h"
#include <stdlib.h>

typedef struct	s_tga_header
{
	t_byte			id_length;
	t_byte			color_map_type;
	t_byte			image_type;
	t_byte			color_map_spec[5];
	short			x_origin;
	short			y_origin;
	short			width;
	short			height;
	t_byte			pixel_depth;
	t_byte			image_spec;
}				t_tga_header;

t_bool			tga_parser(t_buff *buff, t_img *img)
{
	t_tga_header	header;
	int				data_size;

	if (sizeof(t_tga_header) != 18)
		return (ft_printf("Error: struct tga_header not sizeof 18 (%d)\n",
			sizeof(t_tga_header)), false);
	if (!ft_parsen(buff, (void*)&header, sizeof(t_tga_header)))
		return (false);
	if (header.color_map_type != 0 || header.image_type != 2
		|| header.pixel_depth != 32)
		return (ft_printf("Error: Unsupported format\n"), false);
	img->width = (int)header.width;
	img->height = (int)header.height;
	data_size = img->width * img->height * 4;
	img->data = MAL(t_byte, data_size);
	if (!ft_parsen(buff, NULL, header.id_length))
		return (false);
	if (!ft_parsen(buff, (void*)img->data, data_size))
	{
		free(img->data);
		return (false);
	}
	return (true);
}
