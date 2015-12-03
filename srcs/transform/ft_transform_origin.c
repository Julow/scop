/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_origin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 23:57:02 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/03 23:57:32 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

void			ft_transform_origin(t_transform *t, t_vec3 origin)
{
	t->origin = origin;
	t->flags &= ~F_TRANSFORM_OK;
}
