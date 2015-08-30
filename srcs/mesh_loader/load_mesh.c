/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 16:46:02 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/30 16:06:22 by juloo            ###   ########.fr       */
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
	data.vn = VECTOR(t_vec3);
	data.vt = VECTOR(t_vec2);
	ft_vpush_back(&(data.v), NULL, 1);
	ft_vpush_back(&(data.vn), NULL, 1);
	ft_vpush_back(&(data.vt), NULL, 1);
	data.f = VECTOR(int[9]);
	data.vbo_data = VECTOR(float);
	data.ebo_data = VECTOR(int);
	parse_t = ft_clock(0);
	success = parse_mesh(file, &data);
	parse_t = ft_clock(parse_t);
	build_t = ft_clock(0);
	success = success && build_mesh(&data);
	build_t = ft_clock(build_t);
	send_t = ft_clock(0);
	success = success && send_mesh(&data, dst);
	send_t = ft_clock(send_t);
	ft_printf("%s%-25sv:%-9dvn:%-9dvt:%-9df:%-9dvbo:%-9debo:%-9dtime:%-5d %-5d %-5d\n",
		success ? "" : "[FAIL] ", file,
		data.v.length, data.vn.length, data.vt.length, data.f.length,
		data.vbo_data.length / 11, data.ebo_data.length / 3,
		parse_t, build_t, send_t);
	ft_vclear(&(data.v));
	ft_vclear(&(data.vn));
	ft_vclear(&(data.vt));
	ft_vclear(&(data.vbo_data));
	ft_vclear(&(data.ebo_data));
	return (success);
}
