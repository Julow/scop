/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_shader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 14:06:07 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/17 15:36:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shader_loader.h"
#include "utils.h"
#include "ft_list.h"
#include <unistd.h>
#include <fcntl.h>

/*
** ?enum-def loc
*/

struct s_enum_loc const	g_loc = {
	&(struct s_evalue_loc){0, "model"},
	&(struct s_evalue_loc){1, "view"},
	&(struct s_evalue_loc){2, "projection"},
	&(struct s_evalue_loc){3, "camera_pos"},
	&(struct s_evalue_loc){4, "light_pos"},
	&(struct s_evalue_loc){5, "light_count"},
	&(struct s_evalue_loc){6, "ambient_map"},
	&(struct s_evalue_loc){7, "diffuse_map"},
	&(struct s_evalue_loc){8, "specular_map"},
	&(struct s_evalue_loc){9, "ambient_color"},
	&(struct s_evalue_loc){10, "diffuse_color"},
	&(struct s_evalue_loc){11, "specular_color"},
	&(struct s_evalue_loc){12, "specular_exp"},
	13,
	(t_loc const*)&g_loc
};

/*
** ?end
*/

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
		while (++tmp < g_loc.length)
			dst->loc[g_loc.values[tmp]->index] = glGetUniformLocation(dst->handle, g_loc.values[tmp]->name);
	return (success);
}
