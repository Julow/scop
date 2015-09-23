/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 08:40:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/23 08:42:14 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

void			ft_transform_rotate(t_transform *t, t_vec3 rot)
{
	t->rotation = rot;
	t->flags &= ~F_TRANSFORM_OK;
}
