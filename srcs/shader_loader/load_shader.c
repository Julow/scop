/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_shader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 14:06:07 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/17 11:01:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shader_loader.h"
#include "ft_colors.h"
#include "ft_list.h"
#include <unistd.h>
#include <fcntl.h>

/*
** ?enum-def shader_t
*/

struct s_enum_shader_t const	g_shader_t = {
	&(struct s_evalue_shader_t){0, SUBC("frag"), GL_FRAGMENT_SHADER},
	&(struct s_evalue_shader_t){1, SUBC("all"), 0},
	&(struct s_evalue_shader_t){2, SUBC("vert"), GL_VERTEX_SHADER},
	3,
	(t_shader_t const*)&g_shader_t
};

/*
** ?end
*/

static char const *const g_locations[locations_count] = { // TODO generate
	"model",
	"view",
	"projection",
	"camera_pos",
	"light_pos",
	"light_count",
	"ambient_map",
	"diffuse_map",
	"specular_map",
	"ambient_color",
	"diffuse_color",
	"specular_color",
	"specular_exp",
};

#define SHADER_START		(SUBC("//#shader "))

t_bool			ft_substart(t_sub sub, t_sub start)
{
	if (sub.length < start.length)
		return (false);
	if (ft_memcmp(sub.str, start.str, start.length) == 0)
		return (true);
	return (false);
}

/*
** Remove 'n' node after 'node'
** remove all nodes until the end if 'n' is negative
*/
void			ft_listremove_next(t_list *lst, void *node, int n)
{
	while ((node = LIST_NEXT(node)))
	{
		if (n-- == 0)
			return ;
		node = ft_listremove(lst, node);
	}
}

static void		shader_error(t_uint id, t_shader_t t)
{
	char			err_buff[ERR_SHADER_BUFFER];

	glGetShaderInfoLog(id, ERR_SHADER_BUFFER, NULL, err_buff);
	ft_printf(C_RED "Shader Error (%s):" C_RESET " %s\n", t->name.str, err_buff);
}

static t_bool	compile_shader(t_list *lines, t_uint *dst, t_shader_t t)
{
	int				i;
	char const		*strings[lines->length];
	int				lengths[lines->length];
	t_sub			*tmp;

	i = 0;
	tmp = LIST_IT(lines);
	while ((tmp = LIST_NEXT(tmp)))
	{
		strings[i] = tmp->str;
		lengths[i] = tmp->length;
		i++;
	}
	if ((*dst = glCreateShader(t->gl_name)) == 0)
		return (false);
	glShaderSource(*dst, lines->length, strings, lengths);
	glCompileShader(*dst);
	glGetShaderiv(*dst, GL_COMPILE_STATUS, &i);
	if (i == 0)
	{
		shader_error(*dst, t);
		return (false);
	}
	return (true);
}

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
	if (t != g_shader_t.ALL)
	{
		if (s[t->index] > 0)
			glDeleteShader(s[t->index]);
		if (!compile_shader(lines, s + t->index, t))
			return (false);
	}
	return (true);
}

static t_bool	read_shader(int fd, t_list *lines, t_uint *s, t_shader_t t)
{
	t_sub			*const start_line = lines->last;
	t_sub			*tmp;
	t_sub			line;

	while (get_next_line(fd, &line) > 0)
		if (ft_substart(line, SHADER_START))
		{
			if (!read_shader_end(lines, s, t))
				return (false);
			if (t != g_shader_t.ALL)
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

static t_bool	link_shader(t_uint *shaders, t_shader *dst)
{
	int				i;

	if ((dst->handle = glCreateProgram()) <= 0)
		return (false);
	i = -1;
	while (++i < g_shader_t.length)
		if (shaders[i] > 0)
		{
			ft_printf("Linking %s\n", g_shader_t.values[i]->name.str);
			glAttachShader(dst->handle, shaders[i]);
		}
	glLinkProgram(dst->handle);
	glGetProgramiv(dst->handle, GL_LINK_STATUS, &i);
	if (i == 0)
	{
		glDeleteProgram(dst->handle);
		return (false);
	}
	return (true);
}

t_bool			load_shader(char const *file, t_shader *dst)
{
	t_uint			shaders[g_shader_t.length];
	int				tmp;
	t_bool			success;
	t_list			lines;

	if ((tmp = open(file, O_RDONLY)) < 0)
		return (false);
	ft_bzero(shaders, sizeof(t_uint[g_shader_t.length]));
	lines = LIST(t_sub);
	success = read_shader(tmp, &lines, shaders, g_shader_t.ALL);
	close(tmp);
	ft_listremove_next(&lines, LIST_IT(&lines), -1);
	success = success && link_shader(shaders, dst);
	tmp = -1;
	while (++tmp < g_shader_t.length)
		if (shaders[tmp] > 0)
			glDeleteShader(shaders[tmp]);
	tmp = -1;
	if (success)
		while (++tmp < locations_count)
			dst->loc[tmp] = glGetUniformLocation(dst->handle, g_locations[tmp]);
	return (success);
}
