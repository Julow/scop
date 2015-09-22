/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_shader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 14:06:07 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/22 08:21:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shader_loader.h"
#include "utils.h"
#include "gl.h"
#include "ft_list.h"
#include <unistd.h>
#include <fcntl.h>

/*
** ?enum-def shader_t
*/

struct s_enum_shader_t const	g_shader_t = {
	&(struct s_evalue_shader_t){0, SUBC("all"), 0},
	&(struct s_evalue_shader_t){1, SUBC("vert"), GL_VERTEX_SHADER},
	&(struct s_evalue_shader_t){2, SUBC("frag"), GL_FRAGMENT_SHADER},
	3,
	(t_shader_t const*)&g_shader_t
};

/*
** ?end
*/

static t_bool	link_shader(t_uint *shaders, t_shader *dst)
{
	int				i;

	if ((dst->handle = glCreateProgram()) <= 0)
		return (false);
	i = -1;
	while (++i < g_shader_t.length)
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

static t_bool	load_shaders_file(char const *file, t_shader *dst)
{
	t_uint			shaders[g_shader_t.length];
	int				tmp;
	t_bool			success;
	t_list			lines;

	if ((tmp = open(file, O_RDONLY)) < 0)
		return (false);
	ft_bzero(shaders, sizeof(t_uint[g_shader_t.length]));
	lines = LIST(t_sub);
	success = read_shader(tmp, &lines, shaders, g_shader_t.all);
	close(tmp);
	ft_listremove_next(&lines, LIST_IT(&lines), -1);
	success = success && link_shader(shaders, dst);
	tmp = -1;
	while (++tmp < g_shader_t.length)
		if (shaders[tmp] > 0)
			glDeleteShader(shaders[tmp]);
	return (success);
}

t_bool			load_shader(char const *file, t_shader *dst)
{
	int				i;
	int				j;

	i = -1;
	while (g_shader_def[++i].file_name != NULL)
		if (ft_strequ(file, g_shader_def[i].file_name))
		{
			if (!load_shaders_file(file, dst))
				return (false);
			dst->loc = MAL(t_uint, g_shader_def[i].uniform_count);
			dst->pre = g_shader_def[i].pre;
			dst->mtl = g_shader_def[i].mtl;
			j = -1;
			while (++j < g_shader_def[i].uniform_count)
				dst->loc[j] = glGetUniformLocation(dst->handle,
					g_shader_def[i].uniforms[j]);
			return (true);
		}
	return (ft_error(false, "Unknown shader %s", file));
}
