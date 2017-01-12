/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_shader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 14:06:07 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/12 16:01:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/file_in.h"
#include "ft/ft_in.h"
#include "ft/ft_list.h"
#include "ft/gl.h"

#include "internal.h"
#include "utils.h"

#include <fcntl.h>
#include <unistd.h>

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

static bool		link_shader(uint32_t *shaders, uint32_t *dst)
{
	int				i;

	if ((*dst = glCreateProgram()) <= 0)
		return (false);
	i = -1;
	while (++i < g_shader_t.length)
		if (shaders[i] > 0)
			glAttachShader(*dst, shaders[i]);
	glLinkProgram(*dst);
	glGetProgramiv(*dst, GL_LINK_STATUS, &i);
	if (i == 0)
	{
		glDeleteProgram(*dst);
		return (false);
	}
	return (true);
}

bool			load_shader(t_sub file_name, t_shader *dst)
{
	uint32_t		shaders[g_shader_t.length];
	int				i;
	t_file_in		*in;
	bool			success;
	t_list			lines;

	if ((in = ft_in_open(file_name)) == NULL)
		return (false);
	memset(shaders, 0, sizeof(shaders));
	lines = LIST(t_sub);
	success = read_shader(V(in), &lines, shaders, g_shader_t.all);
	ft_in_close(in);
	ft_listremove_next(&lines, LIST_IT(&lines), -1);
	success = success && link_shader(shaders, &dst->handle);
	i = 0;
	while (i < g_shader_t.length)
	{
		if (shaders[i] > 0)
			glDeleteShader(shaders[i]);
		i++;
	}
	return (success);
}
