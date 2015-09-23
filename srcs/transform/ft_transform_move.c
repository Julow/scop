/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 08:40:09 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/23 08:42:18 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

void			ft_transform_move(t_transform *t, t_vec3 pos)
{
	t->position = pos;
	t->flags &= ~F_TRANSFORM_OK;
}
