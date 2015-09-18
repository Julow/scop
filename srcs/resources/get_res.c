/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_res.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 13:07:02 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/18 16:26:06 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hmap.h"
#include "ft_dstr.h"
#include "resources.h"
#include "shader_loader.h"
#include "mesh_loader.h"
#include "mtl_loader.h"
#include "texture_loader.h"
#include "utils.h"

/*
** ?enum-def res_t
*/

struct s_enum_res_t const	g_res_t = {
	&(struct s_evalue_res_t){0, SHADERS_DIR, &load_shader, sizeof(t_shader)},
	&(struct s_evalue_res_t){1, TEXTURES_DIR, &load_texture, sizeof(t_texture)},
	&(struct s_evalue_res_t){2, MESHES_DIR, &load_mesh, sizeof(t_mesh)},
	&(struct s_evalue_res_t){3, MATERIALS_DIR, &load_mtl, sizeof(t_mtl)},
	4,
	(t_res_t const*)&g_res_t
};

/*
** ?end
*/

void const		*get_res(t_res_t type, t_sub name)
{
	static t_hmap	*res_caches[RES_T_COUNT] = {NULL};
	void			*res;
	t_dstr			file_name;

	if (res_caches[type->index] == NULL)
		res_caches[type->index] = ft_hmapnew(10, &ft_djb2);
	if ((res = ft_hmapget(res_caches[type->index], name)) != NULL)
		return (res);
	file_name = DSTR0();
	ft_dstradd(&file_name, ft_sub(type->basedir, 0, -1));
	ft_dstradd(&file_name, name);
	res = ft_hmapput(res_caches[type->index], name, NULL, type->res_size);
	if (!type->loader(file_name.str, res))
		ft_hmaprem(res_caches[type->index], name, (res = NULL));
	return (res);
}
