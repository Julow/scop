/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 16:46:02 by jaguillo          #+#    #+#             */
/*   Updated: 2016/01/16 18:59:05 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_hmap.h"
#include "ft/ft_printf.h"
#include "ft/math.h"

#include "internal.h"

static void		init_mesh_data(t_mesh_data *data)
{
	data->v = VECTOR(t_vec3);
	data->vn = VECTOR(t_vec3);
	data->vt = VECTOR(t_vec2);
	ft_vpush(&(data->v), NULL, 1);
	ft_vpush(&(data->vn), NULL, 1);
	ft_vpush(&(data->vt), NULL, 1);
	data->f = VECTOR(int[9]);
	data->mtllib = NULL;
	data->mtl = VECTOR(t_mesh_mtl);
	ft_vpush(&(data->mtl), &(t_mesh_mtl){NULL, 0}, 1);
	data->vbo_data = VECTOR(float);
	data->ebo_data = VECTOR(int);
}

static void		clear_mesh_data(t_mesh_data *data)
{
	ft_vclear(&(data->v));
	ft_vclear(&(data->vn));
	ft_vclear(&(data->vt));
	ft_vclear(&(data->vbo_data));
	ft_vclear(&(data->ebo_data));
}

static bool		load_mesh_file(char const *file, t_mesh *dst)
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
	ft_printf("%s%-25sv:%-9dvn:%-9dvt:%-9df:%-9dvbo:%-9debo:%-9dmtl:%-9d"
		"time:%-5d %-5d %-5d\n", success ? "" : "[FAIL] ", file,
		data.v.length, data.vn.length, data.vt.length, data.f.length,
		data.vbo_data.length / 8, data.ebo_data.length / 3, data.mtl.length,
		parse_t, build_t, send_t);
	clear_mesh_data(&data);
	return (success);
}

t_mesh const	*load_mesh(t_sub file_name)
{
	static t_hmap	*cache = NULL;
	t_hpair			mesh;

	if (cache == NULL)
		cache = ft_hmapnew(MESH_CACHE_SIZE, &ft_djb2);
	if ((mesh = ft_hmapget(cache, file_name)).value != NULL)
		return (mesh.value);
	mesh = ft_hmapput(cache, file_name, NULL, sizeof(t_mesh));
	if (!load_mesh_file(mesh.key, mesh.value))
	{
		ft_hmaprem(cache, file_name, NULL);
		return (NULL);
	}
	return (mesh.value);
}
