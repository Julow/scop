/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_back_out.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 00:06:17 by juloo             #+#    #+#             */
/*   Updated: 2015/09/28 00:06:58 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "anim.h"

float			smooth_back_out(float delta)
{
	return (1.f - smooth_back_in(1.f - delta));
}
