/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_shader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 14:06:07 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/27 23:39:30 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "utils.h"
#include "gl.h"
#include "ft/ft_list.h"
#include "ft/ft_hmap.h"
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

static t_bool	link_shader(t_uint *shaders, t_uint *dst)
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

static t_bool	load_shaders_file(char const *file, t_uint *dst)
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

t_shader const	*load_shader(t_sub file_name)
{
	static t_hmap	*cache = NULL;
	t_hmap			*uniforms;
	t_hpair			tmp;
	t_uint			handle;

	if (cache == NULL)
		cache = ft_hmapnew(SHADER_CACHE_SIZE, &ft_djb2);
	if ((tmp = ft_hmapget(cache, file_name)).value != NULL)
		return (tmp.value);
	tmp = ft_hmapput(cache, file_name, NULL, sizeof(t_shader));
	if (!load_shaders_file(tmp.key, &handle))
	{
		ft_hmaprem(cache, file_name, NULL);
		return (NULL);
	}
	uniforms = ft_hmapnew(SHADER_LOC_SIZE, &ft_djb2);
	load_uniforms(handle, uniforms);
	ft_memcpy(tmp.value, &(t_shader){uniforms, handle}, sizeof(t_shader));
	return (tmp.value);
}
