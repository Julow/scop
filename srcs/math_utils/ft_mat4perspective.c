/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4perspective.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 14:56:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/25 15:39:57 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_utils.h"
#include <math.h>

t_mat4			ft_mat4perspective(float fov, float ratio, float f, float n)
{
	fov = atanf(fov / 2.f);
	f = f / (n - f);
	return ((t_mat4){
		{fov, 0.f, 0.f, 0.f},
		{0.f, fov / ratio, 0.f, 0.f},
		{0.f, 0.f, f, n * f},
		{0.f, 0.f, -1.f, 0.f}
	});
}
