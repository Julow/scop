/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 11:24:23 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:49:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "ft/math.h"

typedef struct s_camera		t_camera;

# define F_CAMERA_UPDATED	(1 << 1)

struct			s_camera
{
	t_mat4			view_m;
	t_vec3			position;
	t_vec2			look;
	int				flags;
};

# define CAMERA(p,l)		((t_camera){MAT4_0(), p, l, (1 << 1)})

void			camera_move(t_camera *camera, t_vec3 pos);
void			camera_look(t_camera *camera, t_vec2 look);
t_mat4 const	*camera_get_view(t_camera *camera);

#endif
