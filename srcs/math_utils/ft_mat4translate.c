/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 12:56:38 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/25 12:55:29 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_utils.h"

void			ft_mat4translate(t_mat4 *m_a, t_vec3 translate)
{
	t_mat4 const	a = *m_a;

	m_a->x.w = a.x.x * translate.x + a.x.y * translate.y + a.x.z * translate.z + a.x.w;
	m_a->y.w = a.y.x * translate.x + a.y.y * translate.y + a.y.z * translate.z + a.y.w;
	m_a->z.w = a.z.x * translate.x + a.z.y * translate.y + a.z.z * translate.z + a.z.w;
	m_a->w.w = a.w.x * translate.x + a.w.y * translate.y + a.w.z * translate.z + a.w.w;
}
