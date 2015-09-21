/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_get_view.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 11:23:20 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/21 11:24:11 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_mat4 const	*camera_get_view(t_camera *camera)
{
	t_vec3			look_at;

	if (camera->flags & F_CAMERA_UPDATED)
	{
		look_at = ft_vec3front(camera->look);
		look_at.x += camera->position.x;
		look_at.y += camera->position.y;
		look_at.z += camera->position.z;
		camera->view_m = ft_mat4look_at(camera->position, look_at,
			VEC3(0.f, 1.f, 0.f));
		camera->flags &= ~F_CAMERA_UPDATED;
	}
	return (&(camera->view_m));
}
