/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mesh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 16:49:19 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/12 13:49:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/file_in.h"
#include "ft/ft_in.h"

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

bool			parse_mesh(t_sub file, t_mesh_data *data)
{
	t_dstr			line;
	t_file_in		*in;
	bool			r;

	if ((in = ft_in_open(file)) == NULL)
		return (false);
	line = DSTR0();
	r = true;
	while (r && (ft_readto_char(V(in), '\n', &line) || line.length > 0))
	{
		r = parse_line(DSTR_SUB(line), data);
		in->in.buff_i++;
		line.length = 0;
	}
	ft_in_close(in);
	return (r);
}
