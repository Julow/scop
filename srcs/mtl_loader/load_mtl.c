/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_mtl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 15:07:33 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/27 23:39:26 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "utils.h"
#include "ft/ft_hmap.h"
#include "ft/ft_printf.h"
#include <fcntl.h>
#include <unistd.h>

static void		lol(void *mtl)
{
	ft_hmapdestroy(mtl, NULL);
}

t_hmap const	*load_mtl(t_sub file_name)
{
	static t_hmap	*cache = NULL;
	t_hpair			mtllib;
	int				fd;
	t_bool			ret;

	if (cache == NULL)
		cache = ft_hmapnew(MTL_CACHE_SIZE, &ft_djb2);
	if ((mtllib = ft_hmapget(cache, file_name)).value != NULL)
		return (mtllib.value);
	mtllib = ft_hmapputp(cache, file_name, ft_hmapnew(MTLLIB_SIZE, &ft_djb2));
	if ((fd = open(mtllib.key, O_RDONLY)) < 0)
	{
		ft_hmaprem(cache, file_name, &lol);
		ft_dprintf(2, "Error: Cannot open %s\n", mtllib.key);
		return (NULL);
	}
	ret = parse_mtl(fd, mtllib.value);
	close(fd);
	if (ret)
		return (mtllib.value);
	ft_hmapdestroy(mtllib.value, NULL);
	return (NULL);
}
