/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile_shader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 14:21:09 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/11 18:28:18 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_colors.h"
#include "ft/ft_list.h"
#include "ft/ft_printf.h"
#include "ft/gl.h"

#include "internal.h"

static void		shader_error(uint32_t id, t_shader_t t)
{
	char			err_buff[ERR_SHADER_BUFFER];

	glGetShaderInfoLog(id, ERR_SHADER_BUFFER, NULL, err_buff);
	ft_printf(C_RED "Shader Error (%s):" C_RESET " %s%n",
			t->name.str, err_buff);
}

bool			compile_shader(t_list *lines, uint32_t *dst, t_shader_t t)
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
