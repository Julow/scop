/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadmesh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 16:46:02 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/23 18:28:53 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_loadmesh.h"
#include "ft_evalexpr.h"
#include <fcntl.h>

static t_bool	parse_v(t_sub line, t_mesh_data *data);
static t_bool	parse_f(t_sub line, t_mesh_data *data);

struct
{
	t_sub			token;
	t_bool			(*f)(t_sub, t_mesh_data*);
} const			g_tokens[] = {
	{SUBC("#"), NULL},
	{SUBC("v "), &parse_v},
	{SUBC("f "), &parse_f},
	{SUB(NULL, 0), NULL}
};

#include <stdio.h> // debug

static t_bool	parse_v(t_sub line, t_mesh_data *data)
{
	float			*vec;
	int				i;

	vec = ft_vpush_back(&(data->v), NULL, 1);
	line.length = 0;
	i = 0;
	while (i < 3 && ft_subnext(&line, IS_SPACE))
	{
		if (ft_subfloat(line, vec + i) == 0)
		{
			ft_printf("Invalid float: %.*s\n", line.length, line.str);
			return (false);
		}
		i++;
	}
	return (true);
}

static t_bool	parse_f(t_sub line, t_mesh_data *data)
{
	int				*face;
	int				tmp;
	int				i;
	int				j;

	face = ft_vpush_back(&(data->f), NULL, 1);
	line.length = 0;
	i = -3;
	while ((i += 3) < 9 && ft_subnext(&line, IS_SPACE))
	{
		j = -1;
		while (++j < 3)
		{
			tmp = ft_subint(line, face + i + j);
			if (line.length <= tmp)
				break ;
			if (line.str[tmp] != '/')
				return (ft_printf("Invalid syntax: %.*s\n", line.length,
					line.str), false);
			tmp++;
			line.str += tmp;
			line.length -= tmp;
		}
	}
	return (true);
}

static t_bool	load_mesh(int fd, t_mesh_data *data)
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
					return (ft_printf("LOL\n"), false);
				break ;
			}
		if (g_tokens[i].token.str == NULL)
			ft_printf("Invalid line: %.*s\n", line.length, line.str);
	}
	return (true);
}

t_bool			ft_loadmesh(char const *file, t_mesh *dst)
{
	int				fd;
	t_mesh_data		data;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (false);
	data.v = VECTOR(t_vec3);
	data.vn = VECTOR(t_vec2);
	data.vt = VECTOR(t_vec3);
	data.f = VECTOR(t_face);
	if (!load_mesh(fd, &data))
		return (false); // TODO free
	(void)dst;
	return (true);
}
