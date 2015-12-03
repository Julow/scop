/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:53:11 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/03 17:01:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "obj.h"
# include "math_utils.h"
# include "camera.h"

typedef struct s_render_params		t_render_params;

struct s_render_params
{
	t_camera		*camera;
	t_mat4			*projection_m;
};

void			simple_render(t_render_params const *params, t_obj *obj);
void			depth_render(t_render_params const *params, t_obj *obj);

#endif
