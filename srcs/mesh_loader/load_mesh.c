/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 16:46:02 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/25 13:00:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_evalexpr.h"
#include "gl.h"
#include "mesh_loader.h"
#include "utils.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>//

static t_bool	parse_v(t_sub line, t_mesh_data *data);
static t_bool	parse_vn(t_sub line, t_mesh_data *data);
static t_bool	parse_vt(t_sub line, t_mesh_data *data);
static t_bool	parse_f(t_sub line, t_mesh_data *data);

struct
{
	t_sub			token;
	t_bool			(*f)(t_sub, t_mesh_data*);
} const			g_tokens[] = {
	{SUBC("v "), &parse_v},
	{SUBC("vn "), &parse_vn},
	{SUBC("vt "), &parse_vt},
	{SUBC("f "), &parse_f},
	{SUB(NULL, 0), NULL}
};

static t_bool	parse_vec(t_sub line, float *vec, int len)
{
	int				i;

	line.length = 0;
	i = -1;
	while (++i < len && ft_subnext(&line, IS_SPACE))
		if (ft_subfloat(line, vec + i) == 0)
		{
			ft_printf("Invalid float: %.*s\n", line.length, line.str);
			return (false);
		}
	return (true);
}

static t_bool	parse_v(t_sub line, t_mesh_data *data)
{
	return (parse_vec(line, ft_vpush_back(&(data->v), NULL, 1), 3));
}

static t_bool	parse_vn(t_sub line, t_mesh_data *data)
{
	return (parse_vec(line, ft_vpush_back(&(data->vn), NULL, 1), 3));
}

static t_bool	parse_vt(t_sub line, t_mesh_data *data)
{
	return (parse_vec(line, ft_vpush_back(&(data->vt), NULL, 1), 2));
}

static t_bool	parse_f(t_sub line, t_mesh_data *data)
{
	int				face[9];
	int				tmp;
	int				i;
	int				j;

	line.length = 0;
	i = 0;
	while (ft_subnext(&line, IS_SPACE))
	{
		j = -1;
		while (++j < 3)
		{
			tmp = ft_subint(line, face + i + j);
			face[i + j] -= 1;
			if (line.length <= tmp)
				break ;
			if (line.str[tmp] != '/')
				return (ft_printf("Invalid syntax: %.*s\n",
					line.length, line.str), false);
			tmp++;
			line.str += tmp;
			line.length -= tmp;
		}
		if ((i += 3) >= 9)
		{
			ft_vpush_back(&(data->f), face, 1);
			ft_memmove(face + 3, face + 6, S(int, 3));
			i -= 3;
		}
	}
	return (true);
}

static t_bool	load_mesh_data(int fd, t_mesh_data *data)
{
	t_sub			line;
	int				i;

	while (get_next_line(fd, &line) > 0)
	{
		i = -1;
		while (g_tokens[++i].token.str != NULL)
			if (g_tokens[i].token.length <= line.length
				&& MEM_EQU(g_tokens[i].token.str, line.str,
					g_tokens[i].token.length))
			{
				if (g_tokens[i].f != NULL && !g_tokens[i].f(ft_subsub(line,
					g_tokens[i].token.length, -1), data))
					return (false);
				break ;
			}
		if (g_tokens[i].token.str == NULL)
			ft_printf("Invalid line: %.*s\n", line.length, line.str);
	}
	return (true);
}

static t_bool	build_mesh(t_mesh_data *data, t_mesh *mesh)
{
	int					i;
	t_vec3				*vert;
	t_face				*face;
	float				color;

	i = -1;
	while (++i < data->v.length)
	{
		color = ((float)(rand() % 100)) / 100;
		vert = VECTOR_GET(&(data->v), i);
		ft_vpush_back(&(data->vbo_data), &(t_mesh_vbo_data){
			*vert,
			VEC3(color, color, color),
			VEC2(0.f, 0.f),
			VEC3(0.f, 0.f, 0.f)
		}, 1);
	}
	i = -1;
	while (++i < data->f.length)
	{
		face = VECTOR_GET(&(data->f), i);
		ft_vpush_back(&(data->ebo_data), &(t_mesh_ebo_data){
			face->v1,
			face->v2,
			face->v3
		}, 1);
	}
	glGenVertexArrays(1, &(mesh->vao));
	glGenBuffers(1, &(mesh->vbo));
	glGenBuffers(1, &(mesh->ebo));
	glBindVertexArray(mesh->vao);
	glBindBuffer(GL_ARRAY_BUFFER, mesh->vbo);
	glBufferData(GL_ARRAY_BUFFER, data->vbo_data.length * sizeof(t_mesh_vbo_data), data->vbo_data.data, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, data->ebo_data.length * sizeof(t_mesh_ebo_data), data->ebo_data.data, GL_STATIC_DRAW);
	mesh->count = data->ebo_data.length * sizeof(t_mesh_ebo_data) / sizeof(int);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(t_mesh_vbo_data), (void*)offsetof(t_mesh_vbo_data, pos));
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(t_mesh_vbo_data), (void*)offsetof(t_mesh_vbo_data, col));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(t_mesh_vbo_data), (void*)offsetof(t_mesh_vbo_data, tex));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(t_mesh_vbo_data), (void*)offsetof(t_mesh_vbo_data, nor));
	glEnableVertexAttribArray(3);
	glBindVertexArray(0);
	return (true);
}

t_bool			load_mesh(char const *file, t_mesh *dst)
{
	t_mesh_data		data;
	int				fd;
	t_bool			success;
	t_ulong			t;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (false);
	data.v = VECTOR(t_vec3);
	data.vn = VECTOR(t_vec2);
	data.vt = VECTOR(t_vec3);
	data.f = VECTOR(t_face);
	data.vbo_data = VECTOR(t_mesh_vbo_data);
	data.ebo_data = VECTOR(t_mesh_ebo_data);
	t = ft_clock(0);
	success = load_mesh_data(fd, &data);
	t = ft_clock(t);
	ft_printf("Mesh loading time: %lldus\n", t);
	t = ft_clock(0);
	if (success)
		success = build_mesh(&data, dst);
	t = ft_clock(t);
	ft_printf("Mesh loading time: %lldus\n", t);
	ft_vclear(&(data.v));
	ft_vclear(&(data.vn));
	ft_vclear(&(data.vt));
	ft_vclear(&(data.vbo_data));
	ft_vclear(&(data.ebo_data));
	close(fd);
	return (success);
}
