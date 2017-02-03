/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 16:46:02 by jaguillo          #+#    #+#             */
/*   Updated: 2017/02/03 16:17:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "internal.h"

#include <stdlib.h>

static void		init_mesh_data(t_mesh_data *data)
{
	data->v = VECTOR(t_vec3);
	data->vn = VECTOR(t_vec3);
	data->vt = VECTOR(t_vec2);
	ft_vpush(&(data->v), &VEC3_0(), 1);
	ft_vpush(&(data->vn), &VEC3_0(), 1);
	ft_vpush(&(data->vt), &VEC2_0(), 1);
	data->f = VECTOR(uint32_t[9]);
	data->mtllib = NULL;
	data->mtl = VECTOR(t_mesh_mtl);
	ft_vpush(&(data->mtl), &(t_mesh_mtl){NULL, 0}, 1);
	data->vbo_data = VECTOR(float);
	data->ebo_data = VECTOR(uint32_t);
}

static void		clear_mesh_data(t_mesh_data *data)
{
	ft_vclear(&(data->v));
	ft_vclear(&(data->vn));
	ft_vclear(&(data->vt));
	ft_vclear(&(data->vbo_data));
	ft_vclear(&(data->ebo_data));
}

static bool		load_mesh_file(t_sub file, t_mesh *dst)
{
	t_mesh_data		data;
	bool			success;
	uint64_t		parse_t;
	uint64_t		build_t;
	uint64_t		send_t;

	init_mesh_data(&data);
	parse_t = ft_clock(0);
	success = parse_mesh(file, &data);
	parse_t = ft_clock(parse_t);
	build_t = ft_clock(0);
	success = success && build_mesh(&data) && build_mtl(&data, dst);
	build_t = ft_clock(build_t);
	send_t = ft_clock(0);
	success = success && send_mesh(&data, dst);
	send_t = ft_clock(send_t);
	ft_printf("%s%-25tsv:%-9dvn:%-9dvt:%-9df:%-9dvbo:%-9debo:%-9dmtl:%-9d"
		"time:%-5d %-5d %-5d\n", success ? "" : "[FAIL] ", file,
		data.v.length, data.vn.length, data.vt.length, data.f.length,
		data.vbo_data.length / 8, data.ebo_data.length / 3, data.mtl.length,
		parse_t, build_t, send_t);
	clear_mesh_data(&data);
	return (success);
}

static int		cached_mesh_cmp(t_cached_mesh const *mesh, t_sub const *key)
{
	return (SUB_CMP(mesh->file_name, *key));
}

t_mesh const	*load_mesh(t_sub file_name)
{
	static t_set	cache = SET(&cached_mesh_cmp, 0);
	t_cached_mesh	*cached_mesh;

	cached_mesh = ft_set_get(&cache, &file_name);
	if (cached_mesh == NULL)
	{
		cached_mesh = MALLOC(sizeof(t_cached_mesh) + file_name.length);
		memcpy(ENDOF(cached_mesh), file_name.str, file_name.length);
		cached_mesh->set_head = SET_HEAD();
		cached_mesh->file_name = SUB(ENDOF(cached_mesh), file_name.length);
		if (!load_mesh_file(file_name, &cached_mesh->mesh))
		{
			free(cached_mesh);
			return (NULL);
		}
		ft_set_insert(&cache, cached_mesh, &file_name);
	}
	return (&cached_mesh->mesh);
}
