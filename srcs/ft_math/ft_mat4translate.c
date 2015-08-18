/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 12:56:38 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/18 15:49:40 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_3dmath.h"

void			ft_mat4translate(t_mat4 *mat, t_vec3 translate)
{
	ft_mat4mult(mat, MAT4(
		(1.f, 0.f, 0.f, translate.x),
		(0.f, 1.f, 0.f, translate.y),
		(0.f, 0.f, 1.f, translate.z),
		(0.f, 0.f, 0.f, 1.f)
	));
}
