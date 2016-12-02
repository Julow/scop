/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_get_uniform.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 23:42:44 by juloo             #+#    #+#             */
/*   Updated: 2016/12/01 17:18:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_hmap.h"
#include "shader.h"

t_uniform_loc		shader_get_uniform(t_shader const *shader, t_sub name)
{
	t_uniform const *const	uniform = ft_hmapget(shader->uniforms, name).value;

	return ((uniform == NULL) ? 0 : uniform->loc);
}
