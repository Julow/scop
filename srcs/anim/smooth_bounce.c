/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_bounce.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 00:06:17 by juloo             #+#    #+#             */
/*   Updated: 2016/11/22 12:13:33 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "anim.h"
#include <math.h>

float			smooth_bounce(float delta)
{
	float			a;
	float			b;
	float			tmp;

	delta = 1.f - delta;
	a = 0.f;
	b = 1.f;
	while (true)
	{
		if (delta >= ((7.f - (4.f * a)) / 11.f))
		{
			tmp = (11.f - (6.f * a) - (11.f * delta)) / 4.f;
			return (1.f - (b * b - (tmp * tmp)));
		}
		a += b;
		b /= 2.f;
	}
}
