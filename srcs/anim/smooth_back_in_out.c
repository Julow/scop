/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_back_in_out.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 00:06:17 by juloo             #+#    #+#             */
/*   Updated: 2015/09/28 00:06:53 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "anim.h"

float			smooth_back_in_out(float delta)
{
	if (delta <= 0.5f)
		return (smooth_back_in(delta * 2.f) / 2.f);
	return ((1.f - smooth_back_in(1.f - (2.f * delta - 1.f))) / 2.f + 0.5f);
}
