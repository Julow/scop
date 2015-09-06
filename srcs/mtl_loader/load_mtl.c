/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_mtl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 15:07:33 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/06 02:41:49 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtl_loader.h"
#include "utils.h"
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

t_bool			load_mtl(char const *file, t_hmap **mtl)
{
	int				fd;
	t_bool			ret;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (ft_fdprintf(2, "Failed to load %s: %s\n",
			file, strerror(errno)), false);
	*mtl = ft_hmapnew(50, &ft_djb2);
	ret = parse_mtl(fd, *mtl);
	close(fd);
	if (!ret)
		ft_hmapdestroy(*mtl, NULL);
	return (ret);
}
