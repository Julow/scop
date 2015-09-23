/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_get_uniform.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 23:42:44 by juloo             #+#    #+#             */
/*   Updated: 2015/09/23 23:44:12 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shader_loader.h"

t_uint			shader_get_uniform(t_shader const *shader, t_sub name)
{
	t_uniform const *const	uniform = ft_hmapget(&(shader->uniforms), name);

	return ((uniform == NULL) ? 0 : uniform->loc);
}
