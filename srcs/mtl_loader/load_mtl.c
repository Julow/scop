/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_mtl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 15:07:33 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/22 08:21:19 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtl_loader.h"
#include "utils.h"
#include "ft_hmap.h"
#include <fcntl.h>
#include <unistd.h>

t_bool			load_mtl(char const *file, t_hmap **mtl)
{
	int				fd;
	t_bool			ret;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (ft_error(false, "Cannot open %s", file));
	*mtl = ft_hmapnew(50, &ft_djb2);
	ret = parse_mtl(fd, *mtl);
	close(fd);
	if (!ret)
		ft_hmapdestroy(*mtl, NULL);
	return (ret);
}
