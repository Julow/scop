/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile_shader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 14:21:09 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/22 08:21:44 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shader_loader.h"
#include "gl.h"
#include "ft_colors.h"
#include "ft_list.h"

static void		shader_error(t_uint id, t_shader_t t)
{
	char			err_buff[ERR_SHADER_BUFFER];

	glGetShaderInfoLog(id, ERR_SHADER_BUFFER, NULL, err_buff);
	ft_printf(C_RED "Shader Error (%s):" C_RESET " %s\n", t->name.str, err_buff);
}


t_bool			compile_shader(t_list *lines, t_uint *dst, t_shader_t t)
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
