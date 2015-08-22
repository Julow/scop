/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadmesh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 16:46:02 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/22 18:54:51 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_loadmesh.h"
#include <fcntl.h>

struct
{
	t_sub		token;
	t_bool		(*f)(t_sub, t_mesh_data*);
} const		g_tokens[] = {
	{SUBC("#"), &token_ignore},
	{SUBC("v ")},
	{SUBC("f ")},
	{SUB(NULL, 0), NULL}
};

static t_bool	load_mesh(int fd, t_mesh_data *data)
{
	t_sub			line;
	int				i;

	while (get_next_line(fd, &line) > 0)
	{
		i = -1;
		while (g_tokens[++i].str != NULL)
			if (g_tokens[i].length <= line.length
				&& ft_memcmp(g_tokens[i].str, line.str, g_tokens[i].length) == 0)
			{
				ft_printf("Cool: '%.*s'\n", line.length, line.str);
				break ;
			}
		if (g_tokens[i].str == NULL)
			ft_printf("Invalid: '%.*s'\n", line.length, line.str);
	}
	(void)data;
	return (false);
}

t_bool			ft_loadmesh(char const *file, t_mesh *dst)
{
	int				fd;
	t_mesh_data		data;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (false);
	ft_tabini(&(data.v), sizeof(t_vec3));
	ft_tabini(&(data.vn), sizeof(t_vec2));
	ft_tabini(&(data.vt), sizeof(t_vec3));
	ft_tabini(&(data.f), sizeof(t_face));
	if (!load_mesh(fd, &data))
		return (false); // TODO free
	(void)dst;
	return (true);
}
