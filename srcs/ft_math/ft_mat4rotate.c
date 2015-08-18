/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 14:57:48 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/18 15:47:21 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_3dmath.h"
#include <math.h>

// t_mat4 const	a = *m_a;

// m_a->x.y = a.x.y * cosf(x) + a.x.z * sinf(x);
// m_a->x.z = a.x.y * -sinf(x) + a.x.z * cosf(x);
// m_a->y.y = a.y.y * cosf(x) + a.y.z * sinf(x);
// m_a->y.z = a.y.y * -sinf(x) + a.y.z * cosf(x);
// m_a->z.y = a.z.y * cosf(x) + a.z.z * sinf(x);
// m_a->z.z = a.z.y * -sinf(x) + a.z.z * cosf(x);
// m_a->w.y = a.w.y * cosf(x) + a.w.z * sinf(x);
// m_a->w.z = a.w.y * -sinf(x) + a.w.z * cosf(x);

static t_mat4	ft_mat4load_rotx(float x)
{
	return (MAT4(
		(1.f, 0.f, 0.f, 0.f),
		(0.f, cosf(x), -sinf(x), 0.f),
		(0.f, sinf(x), cosf(x), 0.f),
		(0.f, 0.f, 0.f, 1.f),
	));
}

static t_mat4	ft_mat4load_roty(float y)
{
	return (MAT4(
		(cosf(y), 0.f, sinf(y), 0.f),
		(0.f, 1.f, 0.f, 0.f),
		(-sinf(y), 0.f, cosf(y), 0.f),
		(0.f, 0.f, 0.f, 1.f),
	));
}

static t_mat4	ft_mat4load_rotz(float z)
{
	return (MAT4(
		(cosf(z), -sinf(z), 0.f, 0.f),
		(sinf(z), cosf(z), 0.f, 0.f),
		(0.f, 0.f, 1.f, 0.f),
		(0.f, 0.f, 0.f, 1.f),
	));
}

void			ft_mat4rotate(t_mat4 *mat, t_vec3 rotate)
{
	ft_mat4mult(mat, ft_mat4load_rotx(rotate.x));
	ft_mat4mult(mat, ft_mat4load_roty(rotate.y));
	ft_mat4mult(mat, ft_mat4load_rotz(rotate.z));
}
