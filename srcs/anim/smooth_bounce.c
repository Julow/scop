/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_bounce.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 00:06:17 by juloo             #+#    #+#             */
/*   Updated: 2015/09/28 00:08:46 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "anim.h"
#include <math.h>

float			smooth_bounce(float delta)
{
	float			a;
	float			b;

	delta = 1.f - delta;
	a = 0.f;
	b = 1.f;
	while (true)
	{
		if (delta >= ((7.f - (4.f * a)) / 11.f))
			return (1.f - (b * b - powf((11.f - (6.f * a) - (11.f * delta))
					/ 4.f, 2.f)));
		a += b;
		b /= 2.f;
	}
}
