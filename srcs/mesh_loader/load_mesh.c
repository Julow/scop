/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 16:46:02 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/25 17:12:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh_loader.h"

t_bool			load_mesh(char const *file, t_mesh *dst)
{
	t_mesh_data		data;
	t_bool			success;
	t_ulong			t;

	data.v = VECTOR(t_vec3);
	data.vn = VECTOR(t_vec2);
	data.vt = VECTOR(t_vec3);
	data.f = VECTOR(t_face);
	data.vbo_data = VECTOR(t_mesh_vbo_data);
	data.ebo_data = VECTOR(t_mesh_ebo_data);
	t = ft_clock(0);
	success = parse_mesh(file, &data);
	t = ft_clock(t);
	ft_printf("Mesh parsing time: %lldμs\n", t);
	t = ft_clock(0);
	if (success)
		success = build_mesh(&data);
	t = ft_clock(t);
	ft_printf("Mesh building time: %lldμs\n", t);
	t = ft_clock(0);
	if (success)
		success = send_mesh(&data, dst);
	t = ft_clock(t);
	ft_printf("Mesh sending time: %lldμs\n", t);
	ft_vclear(&(data.v));
	ft_vclear(&(data.vn));
	ft_vclear(&(data.vt));
	ft_vclear(&(data.vbo_data));
	ft_vclear(&(data.ebo_data));
	return (success);
}
