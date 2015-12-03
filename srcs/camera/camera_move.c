/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 11:23:26 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/03 15:00:27 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void			camera_move(t_camera *camera, t_vec3 pos)
{
	camera->position = pos;
	camera->flags |= F_CAMERA_UPDATED;
}
