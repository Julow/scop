/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_reflect.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 10:11:23 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/23 10:12:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

void			ft_transform_reflect(t_transform *t, int reflects)
{
	t->flags |= reflects & (REFLECT_X | REFLECT_Y | REFLECT_Z);
	t->flags &= ~F_TRANSFORM_OK;
}
