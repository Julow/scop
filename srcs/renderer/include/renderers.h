/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderers.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 20:15:13 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/04 20:17:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERERS_H
# define RENDERERS_H

# include "renderer.h"
# include "obj.h"

t_obj			*simple_renderer_init(void);
t_obj			*depth_renderer_init(void);

#endif
