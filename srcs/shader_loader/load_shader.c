/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_shader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 14:06:07 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/15 20:09:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shader_loader.h"
#include "ft_colors.h"
#include "ft_list.h"
#include "gl.h"
#include <unistd.h>
#include <fcntl.h>

/*
** [enum] shader_t
** char const		*name;
** t_uint			gl_name;
** ALL("all", 0),
** VERT("vert", GL_VERTEX_SHADER),
** FRAG("frag", GL_FRAGMENT_SHADER),
*/

struct			enum_t_shader_t
{
	t_uint			index;
	t_sub			name;
	t_uint			gl_name;
};

typedef struct enum_t_shader_t const*	t_shader_t;

static struct
{
	t_shader_t		ALL;
	t_shader_t		VERT;
	t_shader_t		FRAG;
	int				length;
} const			shader_t = {
	&(struct enum_t_shader_t){0, SUBC("all"), 0},
	&(struct enum_t_shader_t){1, SUBC("vert"), GL_VERTEX_SHADER},
	&(struct enum_t_shader_t){2, SUBC("frag"), GL_FRAGMENT_SHADER},
	3
};

#define ENUM_ARRAY(e)		((t_##e const*)&e)

/*
** [end]
*/

#define SHADER_START		(SUBC("//#shader "))

t_bool			ft_substart(t_sub sub, t_sub start)
{
	if (sub.length < start.length)
		return (false);
	if (ft_memcmp(sub.str, start.str, start.length) == 0)
		return (true);
	return (false);
}

static void		shader_error(t_uint id, t_shader_t t)
{
	char			err_buff[ERR_SHADER_BUFFER];

	glGetShaderInfoLog(id, ERR_SHADER_BUFFER, NULL, err_buff);
	ft_printf(C_RED "Shader Error (%s):" C_RESET " %s\n", t->name.str, err_buff);
}

static t_bool	compile_shader(t_list *lines, t_uint *dst, t_shader_t t)
{
	int				status;
	char const		*strings[lines->length];
	int				lengths[lines->length];
	t_sub			*tmp;

	//
	status = 0;
	tmp = LIST_IT(lines);
	while ((tmp = LIST_NEXT(tmp)))
	{
		strings[status] = tmp->str;
		lengths[status] = tmp->length;
		status++;
	}
	//
	if ((*dst = glCreateShader(t->gl_name)) == 0)
		return (false);
	glShaderSource(*dst, lines->length, strings, lengths);
	glCompileShader(*dst);
	glGetShaderiv(*dst, GL_COMPILE_STATUS, &status);
	if (status == 0)
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
	while (++i < shader_t.length)
		if (ft_subequ(ENUM_ARRAY(shader_t)[i]->name, line))
		{
			*t = ENUM_ARRAY(shader_t)[i];
			return (true);
		}
	return (false);
}

static t_bool	read_shader(int fd, t_list *lines, t_uint *s, t_shader_t t)
{
	const int		start_line = lines->length;
	t_sub			*tmp;
	t_sub			line;

	while (get_next_line(fd, &line) > 0)
		if (ft_substart(line, SHADER_START))
		{
			if (t != shader_t.ALL)
			{
				if (s[t->index] > 0)
					glDeleteShader(s[t->index]);
				if (!compile_shader(lines, s + t->index, t))
					return (false);
				ft_vremove(lines, start_line, -1);
			}
			if (!get_shader_type(line, &t))
				return (false);
			return (read_shader(fd, lines, s, t));
		}
		else
		{
			tmp = ft_listadd(lines, lines->last, line.length + 2);
			tmp->str = ((void*)tmp) + sizeof(t_sub);
			tmp->length = line.length + 1;
			ft_memcpy(tmp->str, line.str, line.length);
			tmp->str[line.length] = '\n';
			tmp->str[tmp->length] = '\0';
		}
	return (true);
}

static t_bool	link_shader(t_uint *shaders, t_shader *dst)
{
	int				i;

	if ((dst->handle = glCreateProgram()) <= 0)
		return (false);
	i = -1;
	while (++i < shader_t.length)
		if (shaders[i] > 0)
			glAttachShader(dst->handle, shaders[i]);
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
	t_uint			shaders[shader_t.length];
	int				tmp;
	t_bool			success;
	t_list		lines;

	if ((tmp = open(file, O_RDONLY)) < 0)
		return (false);
	ft_bzero(shaders, sizeof(t_uint[shader_t.length]));
	lines = LIST(t_sub);
	success = read_shader(tmp, &lines, shaders, shader_t.ALL);
	close(tmp);
	// ft_vclear(&lines);
	success = success && link_shader(shaders, dst);
	tmp = -1;
	while (++tmp < shader_t.length)
		if (shaders[tmp] > 0)
			glDeleteShader(shaders[tmp]);
	return (success);
}
