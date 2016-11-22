/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mesh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 16:49:19 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/22 12:26:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/get_next_line.h"

#include "internal.h"
#include "utils.h"

#include <fcntl.h>
#include <unistd.h>

static t_mesh_token const	g_tokens[] = {
	{SUBC("v "), &parse_v},
	{SUBC("vn "), &parse_vn},
	{SUBC("vt "), &parse_vt},
	{SUBC("f "), &parse_f},
	{SUBC("mtllib "), &parse_mtllib},
	{SUBC("usemtl "), &parse_usemtl},
	{SUB(NULL, 0), NULL}
};

static bool		parse_line(t_sub line, t_mesh_data *data)
{
	uint32_t		i;

	i = 0;
	while (g_tokens[i].token.str != NULL)
	{
		if (g_tokens[i].token.length <= line.length
			&& MEM_EQU(g_tokens[i].token.str, line.str,
				g_tokens[i].token.length))
		{
			if (g_tokens[i].f != NULL && !g_tokens[i].f(ft_subsub(line,
				g_tokens[i].token.length, -1), data) && !IGNORE_ERROR)
				return (false);
			break ;
		}
		i++;
	}
	return (true);
}

bool			parse_mesh(char const *file, t_mesh_data *data)
{
	t_sub			line;
	int				fd;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (false);
	while (get_next_line(fd, &line) > 0)
		if (!parse_line(line, data))
		{
			close(fd);
			return (false);
		}
	close(fd);
	return (true);
}
