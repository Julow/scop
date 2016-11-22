/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_shader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 14:06:07 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/22 13:38:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_hmap.h"
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

static bool		load_shaders_file(char const *file, uint32_t *dst)
{
	uint32_t		shaders[g_shader_t.length];
	int				tmp;
	bool			success;
	t_list			lines;

	if ((tmp = open(file, O_RDONLY)) < 0)
		return (false);
	ft_bzero(shaders, sizeof(uint32_t[g_shader_t.length]));
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
	uint32_t		handle;

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
