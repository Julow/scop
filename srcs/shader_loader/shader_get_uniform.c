/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_get_uniform.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 23:42:44 by juloo             #+#    #+#             */
/*   Updated: 2015/10/11 20:45:28 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shader_loader.h"
#include "ft_hmap.h"

t_uint			shader_get_uniform(t_shader const *shader, t_sub name)
{
	t_uniform const *const	uniform = ft_hmapget(shader->uniforms, name).value;

	return ((uniform == NULL) ? 0 : uniform->loc);
}
