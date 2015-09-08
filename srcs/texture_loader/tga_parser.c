/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 11:51:02 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/08 15:46:09 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_loader.h"
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

static t_bool	parse(t_buff *buff, t_img *img, int data_size, int pixel_size)
{
	t_byte			*tmp;
	t_byte const	*const end = img->data + data_size;
	int				i;

	tmp = img->data;
	while (tmp < end && !BEOF(buff))
	{
		i = 0;
		while (i < pixel_size)
			tmp[i++] = BR(buff);
		while (i < 4)
			tmp[i++] = (t_byte)-1;
		tmp += 4;
	}
	return (true);
}

t_bool			tga_parser(t_buff *buff, t_img *img)
{
	t_tga_header	header;
	int				data_size;

	if (sizeof(t_tga_header) != 18)
		return (ft_printf("Error: struct tga_header not sizeof 18 (%d)\n",
			sizeof(t_tga_header)), false);
	if (!ft_parsen(buff, (void*)&header, sizeof(t_tga_header)))
		return (ft_printf("Error: Corrupt file\n"), false);
	if (header.color_map_type != 0 || header.image_type != 2
		|| (header.pixel_depth != 32 && header.pixel_depth != 24))
		return (ft_printf("Error: Unsupported format\n"), false);
	img->width = (int)header.width;
	img->height = (int)header.height;
	data_size = img->width * img->height * 4;
	img->data = MAL(t_byte, data_size);
	return (parse(buff, img, data_size, header.pixel_depth / 8));
}
