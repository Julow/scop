/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadimage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 11:50:32 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/28 00:13:12 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_img.h"
#include "ft/ft_buff.h"
#include <fcntl.h>

t_imgtype const	g_imgtypes[] = {
	{SUBC(".tga"), &tga_parser},
	{SUB("", 0), NULL}
};

t_bool			ft_loadimage(char const *file, t_img *img)
{
	t_sub			ext;
	char			buff[LOAD_IMAGE_BUFF];
	int				i;
	int				fd;

	ext = ft_sub((char*)file, -1, -1);
	while (--(ext.str) >= file)
	{
		ext.length++;
		if (ext.str[0] == '.')
		{
			i = -1;
			while (g_imgtypes[++i].f != NULL)
				if (g_imgtypes[i].ext.length == ext.length
					&& !ft_memcmp(g_imgtypes[i].ext.str, ext.str, ext.length))
				{
					if ((fd = open(file, O_RDONLY)) < 0)
						return (false);
					return (g_imgtypes[i].f(&BUFF(fd, buff, LOAD_IMAGE_BUFF),
						img));
				}
		}
	}
	return (false);
}
