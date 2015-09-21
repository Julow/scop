/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 11:24:23 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/21 11:25:42 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "math_utils.h"

# define F_CAMERA_UPDATED	(1 << 1)

typedef struct	s_camera
{
	t_mat4			view_m;
	t_vec3			position;
	t_vec2			look;
	int				flags;
}				t_camera;

# define CAMERA(p,l)		((t_camera){MAT4_0(), p, l, (1 << 1)})

void			camera_move(t_camera *camera, t_vec3 pos);
void			camera_look(t_camera *camera, t_vec2 look);
t_mat4 const	*camera_get_view(t_camera *camera);

#endif
