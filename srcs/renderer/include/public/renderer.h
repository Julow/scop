/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 17:38:51 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/04 20:17:08 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "obj.h"

enum	u_renderer
{
	SIMPLE_RENDERER,
	DEPTH_RENDERER
};

# define RENDERER(NAME)		(g_renderers[(NAME #_RENDERER)])

extern t_obj	*(*g_renderers[])(void);

#endif
