/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:53:11 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/22 18:00:32 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "ft/math_mat4.h"

# include "camera.h"
# include "mesh.h"

typedef struct s_render_params		t_render_params;

struct			s_render_params
{
	t_camera		*camera;
	t_mat4 const	*projection_m;
	t_mat4 const	*top_matrix;
};

void			simple_render(t_render_params const *params,
					t_mesh const *mesh);

#endif
