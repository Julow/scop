/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_scale.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 08:40:04 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/03 19:49:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

void			ft_transform_scale(t_transform *t, float scale)
{
	t->scale = VEC3(scale, scale, scale);
	t->flags &= ~F_TRANSFORM_OK;
}

void			ft_transform_scale3(t_transform *t, t_vec3 scale)
{
	t->scale = scale;
	t->flags &= ~F_TRANSFORM_OK;
}
