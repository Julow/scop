/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_look.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 11:23:23 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/21 11:33:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include <math.h>

void			camera_look(t_camera *camera, t_vec2 look)
{
	float const		pi2 = (float)M_PI / 2.f - 0.0001f;

	camera->look.x = look.x;
	camera->look.y = look.y;
	if (camera->look.y > pi2)
		camera->look.y = pi2;
	else if (camera->look.y < -pi2)
		camera->look.y = -pi2;
	camera->flags |= F_CAMERA_UPDATED;
}
