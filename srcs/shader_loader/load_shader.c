/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_shader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 14:43:43 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/14 13:21:02 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shader_loader.h"
#include "gl.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static char const *const g_locations[] = { // TODO generate
	"model",
	"view",
	"projection",
	"camera_pos",
	"light_pos",
	"light_count",
	"ambient_color",
	"diffuse_color",
	"specular_color",
	"specular_exp",
};

static t_bool	create_shader_end(t_shader_c *chunks, int count, t_uint id)
{
	char const		*strings[count];
	int				lengths[count];
	char			err_buff[ERR_SHADER_BUFFER];
	int				i;

	i = count;
	while (--i >= 0)
	{
		strings[i] = chunks->str;
		lengths[i] = chunks->length;
		chunks = chunks->prev;
	}
	glShaderSource(id, count, strings, lengths);
	glCompileShader(id);
	glGetShaderiv(id, GL_COMPILE_STATUS, &i);
	if (i == 0)
	{
		glGetShaderInfoLog(id, ERR_SHADER_BUFFER, NULL, err_buff);
		ft_printf("Error: %s\n", err_buff);
		return (false);
	}
	return (true);
}

static t_bool	read_shader(int fd, t_shader_c *prev, int count, t_uint id)
{
	t_shader_c		chunk;
	t_bool			ret;

	chunk.str = MAL(char, LOAD_SHADER_BUFFER + 1);
	if ((chunk.length = read(fd, chunk.str, LOAD_SHADER_BUFFER)) < 0)
		return (ft_printf("Error: Cannot read shader file\n"), false);
	if (chunk.length == 0)
		return (free(chunk.str), create_shader_end(prev, count, id));
	chunk.str[chunk.length] = '\0';
	chunk.prev = prev;
	ret = read_shader(fd, &chunk, count + 1, id);
	free(chunk.str);
	return (ret);
}

static t_bool	create_shader_file(char const *file, GLenum type, t_uint *id)
{
	int				fd;

	if ((*id = glCreateShader(type)) == 0)
		return (ft_printf("Error: Cannot create shader\n"), false);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (ft_printf("Error: %s: Cannot open\n", file), false);
	if (!read_shader(fd, NULL, 0, *id))
		return (glDeleteShader(*id), false);
	return (true);
}

static t_bool	load_program(char const *vert, char const *frag, t_shader *p)
{
	t_uint			vert_shader;
	t_uint			frag_shader;
	int				tmp;

	if (!create_shader_file(vert, GL_VERTEX_SHADER, &vert_shader))
		return (false);
	if (!create_shader_file(frag, GL_FRAGMENT_SHADER, &frag_shader))
		return (glDeleteShader(vert_shader), false);
	if ((p->handle = glCreateProgram()) > 0)
	{
		glAttachShader(p->handle, vert_shader);
		glAttachShader(p->handle, frag_shader);
		glLinkProgram(p->handle);
		glGetProgramiv(p->handle, GL_LINK_STATUS, &tmp);
		if (tmp == 0 && !(p->handle = 0))
			glDeleteProgram(p->handle);
	}
	glDeleteShader(vert_shader);
	glDeleteShader(frag_shader);
	return ((p->handle == 0) ? false : true);
}

t_bool			load_shader(char const *file, t_shader *p)
{
	t_sub const		base_name = ft_sub(file, 0, -1);
	char			file_names[2][base_name.length + 6 + 1];
	int				i;

	ft_memcpy(file_names[0], base_name.str, base_name.length);
	ft_memcpy(file_names[0] + base_name.length, ".vert", 6);
	ft_memcpy(file_names[1], base_name.str, base_name.length);
	ft_memcpy(file_names[1] + base_name.length, ".frag", 6);
	if (!load_program(file_names[0], file_names[1], p))
		return (false);
	i = -1;
	while (++i < locations_count)
		p->loc[i] = glGetUniformLocation(p->handle, g_locations[i]);
	return (true);
}
