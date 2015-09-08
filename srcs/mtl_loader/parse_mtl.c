/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mtl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 19:13:37 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/08 15:47:12 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtl_loader.h"
#include "utils.h"

static t_mtl_token const	g_mtl_tokens[] = {
	{SUBC("Ka"), &ambient_color_token},
	{SUBC("Kd"), &diffuse_color_token},
	{SUBC("Ks"), &specular_color_token},
	{SUBC("Ns"), &specular_exp_token},
	{SUBC("map_Kd"), &map_kd_token}
};

t_bool			parse_mtl(int fd, t_hmap *mtl)
{
	t_mtl			*curr_mtl;
	t_sub			line;
	int				i;

	curr_mtl = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		line.length = 0;
		if (!ft_subnextc(&line, ' '))
			continue ;
		if (ft_subequ(line, SUBC("newmtl")))
			curr_mtl = ft_subnextc(&line, ' ') ? // newmtl need an argument
				ft_hmapput(mtl, line, NULL, sizeof(t_mtl)) : NULL;
		if (curr_mtl == NULL)
			continue ; // No mtl declared
		i = -1;
		while (++i < G_ARRAY_LEN(g_mtl_tokens))
			if (ft_subequ(g_mtl_tokens[i].name, line)
				&& !g_mtl_tokens[i].f(SUB(line.str + line.length, 0), curr_mtl)
				&& !IGNORE_ERROR)
				return (false);
	}
	return (true);
}
