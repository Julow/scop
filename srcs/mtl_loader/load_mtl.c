/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_mtl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 15:07:33 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/12 15:30:42 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/file_in.h"
#include "ft/ft_in.h"
#include "ft/ft_printf.h"

#include "internal.h"
#include "utils.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int		mtllib_mtl_cmp(t_mtllib_mtl const *mtl, t_sub const *key)
{
	return (SUB_CMP(mtl->name, *key));
}

static int		cached_mtllib_cmp(t_cached_mtllib const *lib, t_sub const *key)
{
	return (SUB_CMP(lib->file_name, *key));
}

static bool		load_mtllib(t_sub file_name, t_mtllib *dst)
{
	t_file_in		*in;
	bool			r;

	*dst = (t_mtllib){
		SET(&mtllib_mtl_cmp, 0),
	};
	if ((in = ft_in_open(file_name)) == NULL)
		return (false);
	r = parse_mtl(V(in), dst);
	ft_in_close(in);
	return (r);
}

t_mtllib const	*load_mtl(t_sub file_name)
{
	static t_set	cache = SET(&cached_mtllib_cmp, 0);
	t_cached_mtllib	*mtllib;

	mtllib = ft_set_get(&cache, &file_name);
	if (mtllib == NULL)
	{
		mtllib = MALLOC(sizeof(t_cached_mtllib) + file_name.length);
		memcpy(ENDOF(mtllib), file_name.str, file_name.length);
		mtllib->set_head = SET_HEAD();
		mtllib->file_name = SUB(ENDOF(mtllib), file_name.length);
		if (!load_mtllib(file_name, &mtllib->mtllib))
		{
			free(mtllib);
			return (NULL);
		}
	}
	return (&mtllib->mtllib);
}
