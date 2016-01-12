/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_uniforms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 12:11:44 by juloo             #+#    #+#             */
/*   Updated: 2016/01/13 00:38:37 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_hmap.h"
#include "ft/gl.h"

#include "internal.h"
#include "utils.h"

int				get_uniform_max_len(uint32_t handle)
{
	int				max_len;

	glGetProgramiv(handle, GL_ACTIVE_UNIFORM_MAX_LENGTH, &max_len);
	return (max_len);
}

void			load_uniforms(uint32_t handle, t_hmap *uniforms)
{
	const int		max_len = get_uniform_max_len(handle) + 1;
	int				count;
	char			uniform_name[max_len];
	int				length;
	t_uniform		uniform;

	glGetProgramiv(handle, GL_ACTIVE_UNIFORMS, &count);
	while (--count >= 0)
	{
		glGetActiveUniform(handle, count, max_len, &length,
			&(uniform.size), &(uniform.type), uniform_name);
		if (ft_subends(SUB(uniform_name, length), SUBC("[0]")))
			length -= 3;
		uniform.loc = glGetUniformLocation(handle, uniform_name);
		ft_hmapput(uniforms, SUB(uniform_name, length),
			&uniform, sizeof(t_uniform));
	}
}
