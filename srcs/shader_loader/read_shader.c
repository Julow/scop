/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_shader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 14:20:07 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/28 00:13:05 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "utils.h"
#include "gl.h"
#include "ft/ft_sub.h"
#include "ft/ft_list.h"
#include "ft/get_next_line.h"

static t_bool	get_shader_type(t_sub line, t_shader_t *t)
{
	int				i;

	line.length = MIN(SHADER_START.length, line.length);
	if (!ft_subnext(&line, IS_SPACE))
		return (false);
	i = -1;
	while (++i < g_shader_t.length)
		if (ft_subequ(g_shader_t.values[i]->name, line))
		{
			*t = g_shader_t.values[i];
			return (true);
		}
	return (false);
}

static t_bool	read_shader_end(t_list *lines, t_uint *s, t_shader_t t)
{
	if (t != g_shader_t.all)
	{
		if (s[t->index] > 0)
			glDeleteShader(s[t->index]);
		if (!compile_shader(lines, s + t->index, t))
			return (false);
	}
	return (true);
}

t_bool			read_shader(int fd, t_list *lines, t_uint *s, t_shader_t t)
{
	t_sub *const	start_line = lines->last;
	t_sub			*tmp;
	t_sub			line;

	while (get_next_line(fd, &line) > 0)
		if (ft_substart(line, SHADER_START))
		{
			if (!read_shader_end(lines, s, t))
				return (false);
			if (t != g_shader_t.all)
				ft_listremove_next(lines, start_line, -1);
			if (!get_shader_type(line, &t))
				return (false);
			return (read_shader(fd, lines, s, t));
		}
		else
		{
			tmp = ft_listadd(lines, lines->last, line.length + 2);
			tmp->str = ((void*)tmp) + sizeof(t_sub);
			tmp->length = line.length + 1;
			ft_memcpy(((void*)tmp) + sizeof(t_sub), line.str, line.length);
			(((char*)tmp) + sizeof(t_sub))[line.length] = '\n';
			(((char*)tmp) + sizeof(t_sub))[tmp->length] = '\0';
		}
	return (read_shader_end(lines, s, t));
}
