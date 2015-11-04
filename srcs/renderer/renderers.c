/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 20:13:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/04 20:15:52 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderers.h"

t_obj		*(*g_renderers[])(void) = {
	[SIMPLE_RENDERER] = &simple_renderer_init,
	[DEPTH_RENDERER] = &depth_renderer_init
};
