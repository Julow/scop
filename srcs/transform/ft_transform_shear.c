/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_shear.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 10:20:58 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/23 10:22:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

void			ft_transform_shear(t_transform *t, t_vec3 shear)
{
	t->shear = shear;
	t->flags &= ~F_TRANSFORM_OK;
}
