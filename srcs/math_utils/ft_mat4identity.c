/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4identity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 18:11:04 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/25 12:59:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_utils.h"
#include "libft.h"

void			ft_mat4identity(t_mat4 *m)
{
	ft_bzero(m, sizeof(t_mat4));
	m->x.x = 1.f;
	m->y.y = 1.f;
	m->z.z = 1.f;
	m->w.w = 1.f;
}
