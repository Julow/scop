/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 16:46:02 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/27 00:02:08 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh_loader.h"

t_bool			load_mesh(char const *file, t_mesh *dst)
{
	t_mesh_data		data;
	t_bool			success;
	t_ulong			parse_t;
	t_ulong			build_t;
	t_ulong			send_t;

	data.v = VECTOR(t_vec3);
	data.vn = VECTOR(t_vec2);
	data.vt = VECTOR(t_vec3);
	data.f = VECTOR(t_face);
	data.vbo_data = VECTOR(t_mesh_vbo_data);
	data.ebo_data = VECTOR(t_mesh_ebo_data);
	parse_t = ft_clock(0);
	success = parse_mesh(file, &data);
	parse_t = ft_clock(parse_t);
	build_t = ft_clock(0);
	success = success && build_mesh(&data);
	build_t = ft_clock(build_t);
	send_t = ft_clock(0);
	success = success && send_mesh(&data, dst);
	send_t = ft_clock(send_t);
	ft_printf("Mesh loading: parse:%-5lld build:%-5lld send:%-5lld (%s)\n",
		parse_t, build_t, send_t, file);
	ft_vclear(&(data.v));
	ft_vclear(&(data.vn));
	ft_vclear(&(data.vt));
	ft_vclear(&(data.vbo_data));
	ft_vclear(&(data.ebo_data));
	return (success);
}
