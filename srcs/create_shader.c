/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 14:43:43 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/15 15:23:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define LOAD_SHADER_BUFFER		256
#define ERR_SHADER_BUFFER 		128

/*
** Compile a shader program
** vert and frag are file names
** store result in p
*/
typedef struct	s_shader_c
{
	char				*str;
	int					length;
	struct s_shader_c	*prev;
}				t_shader_c;

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
		ft_printf("Error: %s\n", id, err_buff);
		return (false);
	}
	return (true);
}

static t_bool	create_shader_loop(int fd, t_shader_c *prev, int count, t_uint id)
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
	ret = create_shader_loop(fd, &chunk, count + 1, id);
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
	if (!create_shader_loop(fd, NULL, 0, *id))
	{
		glDeleteShader(*id);
		return (false);
	}
	return (true);
}

t_bool			create_shader(char const *vert, char const *frag, t_uint *p)
{
	t_uint			vert_shader;
	t_uint			frag_shader;
	int				tmp;

	if (!create_shader_file(vert, GL_VERTEX_SHADER, &vert_shader))
		return (false);
	if (!create_shader_file(frag, GL_FRAGMENT_SHADER, &frag_shader))
		return (glDeleteShader(vert_shader), false);
	if ((*p = glCreateProgram()) > 0)
	{
		glAttachShader(*p, vert_shader);
		glAttachShader(*p, frag_shader);
		glLinkProgram(*p);
		glGetProgramiv(*p, GL_LINK_STATUS, &tmp);
		if (tmp == 0)
		{
			glDeleteProgram(*p);
			*p = 0;
		}
	}
	glDeleteShader(vert_shader);
	glDeleteShader(frag_shader);
	return ((*p == 0) ? false : true);
}
