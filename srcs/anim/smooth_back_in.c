/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_back_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 00:06:17 by juloo             #+#    #+#             */
/*   Updated: 2015/09/28 00:08:57 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "anim.h"
#include <math.h>

float			smooth_back_in(float delta)
{
	return ((delta * delta * delta) - (delta * sinf(delta * M_PI)));
}
