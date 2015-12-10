/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:53:11 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:57:04 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "mesh.h"
# include "ft/math.h"
# include "camera.h"

typedef struct s_render_params		t_render_params;

struct			s_render_params
{
	t_camera		*camera;
	t_mat4 const	*projection_m;
	t_mat4 const	*top_matrix;
};

void			simple_render(t_render_params const *params, t_mesh const *mesh);

#endif
