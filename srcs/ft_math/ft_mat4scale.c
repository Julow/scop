/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 14:57:53 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/18 17:03:28 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_3dmath.h"

void			ft_mat4scale(t_mat4 *m_a, t_vec3 scale)
{
	t_mat4 const	a = *m_a;

	m_a->x.x = a.x.x * scale.x;
	m_a->x.y = a.x.y * scale.y;
	m_a->x.z = a.x.z * scale.z;
	m_a->y.x = a.y.x * scale.x;
	m_a->y.y = a.y.y * scale.y;
	m_a->y.z = a.y.z * scale.z;
	m_a->z.x = a.z.x * scale.x;
	m_a->z.y = a.z.y * scale.y;
	m_a->z.z = a.z.z * scale.z;
	m_a->w.x = a.w.x * scale.x;
	m_a->w.y = a.w.y * scale.y;
	m_a->w.z = a.w.z * scale.z;
}
