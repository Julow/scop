/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 11:51:02 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/19 19:42:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_loader.h"
#include "utils.h"
#include <stdlib.h>

#define AT(t,p,i)			((t*)(((void*)(p)) + (i)))

#define HEADER_SIZE			18

#define OFFSET_CM_TYPE		1
#define OFFSET_IMG_TYPE		2
#define OFFSET_PIX_SIZE		16
#define OFFSET_WIDTH		12
#define OFFSET_HEIGHT		14

static t_bool	parse_pixels(t_buff *buff, t_img *img, int size, int pixel_size)
{
	t_byte				*tmp;
	const t_byte *const	end = img->data + size;
	int					i;

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
	t_byte			header[HEADER_SIZE];
	int				pixel_size;
	int				data_size;

	if (!ft_parsen(buff, (void*)header, HEADER_SIZE))
		return (ft_error(false, "Error: Corrupt file\n"));
	pixel_size = (int)*AT(t_byte, header, OFFSET_PIX_SIZE);
	if (*AT(t_byte, header, OFFSET_CM_TYPE) != 0
		|| *AT(t_byte, header, OFFSET_IMG_TYPE) != 2
		|| (pixel_size != 32 && pixel_size != 24))
		return (ft_error(false, "Error: Unsupported format\n"));
	img->width = (int)*AT(short, header, OFFSET_WIDTH);
	img->height = (int)*AT(short, header, OFFSET_HEIGHT);
	data_size = img->width * img->height * 4;
	img->data = MAL(t_byte, data_size);
	return (parse_pixels(buff, img, data_size, pixel_size / 8));
}
