/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 20:13:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/04 23:32:53 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderers.h"

t_renderer		g_renderers[] = {
	[SIMPLE_RENDERER] = &simple_renderer_init,
	[DEPTH_RENDERER] = &depth_renderer_init
};
