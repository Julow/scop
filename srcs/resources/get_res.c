/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_res.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 13:07:02 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/26 14:10:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hmap.h"
#include "resources.h"
#include "utils.h"
#include "shader_loader.h"
#include "mesh_loader.h"
#include "texture_loader.h"

static t_res const			*g_ressources[] = {
	RES_SHADER("test", "test.vert", "test.frag"),
	RES_TEXTURE("container", "container.tga"),
	RES_TEXTURE("wall", "wall.tga"),
	RES_MESH("42", "42.obj"),
	RES_MESH("cube", "cube.obj"),
	RES_MESH("rect", "rect.obj"),
	RES_MESH("teapot", "teapot.obj"),
	RES_MESH("teapot2", "teapot2.obj")
};

static const t_res_config	g_res_conf[res_t_count] = {
	{&shader_res_loader, sizeof(t_shader)},
	{&texture_res_loader, sizeof(t_texture)},
	{&mesh_res_loader, sizeof(t_mesh)}
};

t_bool			shader_res_loader(void *dst, t_res_shader const *res)
{
	return (load_shader(res->vert_file, res->frag_file, dst));
}

t_bool			texture_res_loader(void *dst, t_res_texture const *res)
{
	return (load_texture(res->file, dst));
}

t_bool			mesh_res_loader(void *dst, t_res_mesh const *res)
{
	return (load_mesh(res->file, dst));
}

void const		*get_res(t_res_t type, t_sub name)
{
	static t_hmap	*res_caches[res_t_count] = {NULL};
	void			*res;
	int				i;

	if (type >= res_t_count || g_res_conf[type].loader == NULL)
		return (NULL);
	if (res_caches[type] == NULL)
		res_caches[type] = ft_hmapnew(10, &ft_djb2);
	if ((res = ft_hmapget(res_caches[type], name)) != NULL)
		return (res);
	i = -1;
	while (++i < G_ARRAY_LEN(g_ressources))
		if (g_ressources[i]->type == type
			&& g_ressources[i]->name.length == name.length
			&& MEM_EQU(g_ressources[i]->name.str, name.str, name.length))
		{
			res = ft_hmapput(res_caches[type], name, NULL,
				g_res_conf[type].res_size);
			if (!g_res_conf[type].loader(res, g_ressources[i]))
				ft_hmaprem(res_caches[type], name, (res = NULL));
			return (res);
		}
	return (NULL);
}
