/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_res.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 13:07:02 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/08 14:26:35 by jaguillo         ###   ########.fr       */
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

static const t_res_config	g_res_conf[res_t_count] = {
	{SHADERS_DIR, &load_shader, sizeof(t_shader)},
	{TEXTURES_DIR, &load_texture, sizeof(t_texture)},
	{MESHES_DIR, &load_mesh, sizeof(t_mesh)},
	{MATERIALS_DIR, &load_mtl, sizeof(t_hmap*)}
};

void const		*get_res(t_res_t type, t_sub name)
{
	static t_hmap	*res_caches[res_t_count] = {NULL};
	void			*res;
	t_dstr			file_name;

	if (type >= res_t_count || type >= G_ARRAY_LEN(g_res_conf))
		return (NULL);
	if (res_caches[type] == NULL)
		res_caches[type] = ft_hmapnew(10, &ft_djb2);
	if ((res = ft_hmapget(res_caches[type], name)) != NULL)
		return (res);
	file_name = DSTR0();
	ft_dstradd(&file_name, g_res_conf[type].basedir, -1);
	ft_dstradd(&file_name, name.str, name.length);
	res = ft_hmapput(res_caches[type], name, NULL, g_res_conf[type].res_size);
	if (!g_res_conf[type].loader(file_name.str, res))
		ft_hmaprem(res_caches[type], name, (res = NULL));
	return (res);
}
