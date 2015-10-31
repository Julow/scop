/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 17:38:51 by jaguillo          #+#    #+#             */
/*   Updated: 2015/10/31 22:50:05 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

// module: renderer

# include "obj.h"
# include "camera.h"
# include "math_utils.h"

typedef struct s_renderer_params	t_renderer_params;
typedef void						(*t_renderer)(t_renderer_params*, t_obj*);

struct	s_renderer_params
{
	t_camera		*camera;
	t_mat4			*projection_m;
};

void			simple_renderer(t_renderer_params *scop, t_obj *obj);

#endif
