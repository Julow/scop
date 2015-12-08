/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_uniforms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 12:11:44 by juloo             #+#    #+#             */
/*   Updated: 2015/12/08 17:10:20 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "ft/ft_hmap.h"
#include "ft/gl.h"
#include "utils.h"

int				get_uniform_max_len(t_uint handle)
{
	int				max_len;

	glGetProgramiv(handle, GL_ACTIVE_UNIFORM_MAX_LENGTH, &max_len);
	return (max_len);
}

void			load_uniforms(t_uint handle, t_hmap *uniforms)
{
	const int		max_len = get_uniform_max_len(handle);
	int				count;
	char			uniform_buffer[max_len];
	t_sub			uniform_name;
	t_uniform		uniform;

	glGetProgramiv(handle, GL_ACTIVE_UNIFORMS, &count);
	uniform_name = SUB(uniform_buffer, 0);
	while (--count >= 0)
	{
		glGetActiveUniform(handle, count, max_len, &(uniform_name.length),
			&(uniform.size), &(uniform.type), uniform_buffer);
		if (ft_subends(uniform_name, SUBC("[0]")))
			uniform_name.length -= 3;
		uniform.loc = glGetUniformLocation(handle, uniform_name.str);
		ft_hmapput(uniforms, uniform_name, &uniform, sizeof(t_uniform));
	}
}
