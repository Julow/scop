/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_shader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 14:20:07 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/12 16:01:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_dstr.h"
#include "ft/ft_in.h"
#include "ft/ft_list.h"
#include "ft/gl.h"

#include "internal.h"
#include "utils.h"

static bool		get_shader_type(t_sub line, t_shader_t *t)
{
	int				i;
	t_sub			word;

	word = SUB_LEN(line, MIN(SHADER_START.length, line.length));
	if (!ft_subnext_is(line, &word, IS_SPACE))
		return (false);
	i = -1;
	while (++i < g_shader_t.length)
		if (ft_subequ(g_shader_t.values[i]->name, word))
		{
			*t = g_shader_t.values[i];
			return (true);
		}
	return (false);
}

static bool		read_shader_end(t_list *lines, uint32_t *s, t_shader_t t)
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

bool			read_shader(t_in *in, t_list *lines, uint32_t *s, t_shader_t t)
{
	t_sub *const	start_line = lines->last;
	t_sub			*tmp;
	t_dstr			line;

	line = DSTR0();
	while (ft_read_line(in, &line))
		if (ft_substart(DSTR_SUB(line), SHADER_START))
		{
			if (!read_shader_end(lines, s, t))
				return (false);
			if (t != g_shader_t.all)
				ft_listremove_next(lines, start_line, -1);
			if (!get_shader_type(DSTR_SUB(line), &t))
				return (false);
			return (read_shader(in, lines, s, t));
		}
		else
		{
			tmp = ft_listadd(lines, lines->last, line.length + 2);
			tmp->str = ((void*)tmp) + sizeof(t_sub);
			tmp->length = line.length + 1;
			memcpy(((void*)tmp) + sizeof(t_sub), line.str, line.length);
			(((char*)tmp) + sizeof(t_sub))[line.length] = '\n';
			(((char*)tmp) + sizeof(t_sub))[tmp->length] = '\0';
		}
	return (read_shader_end(lines, s, t));
}
