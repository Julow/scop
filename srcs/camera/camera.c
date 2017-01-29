/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 17:52:59 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/29 17:58:05 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void		camera_current(t_camera_list *lst, t_camera *camera)
{
	lst->current = camera;
	camera->proj_m = ft_mat4perspective(camera->fov, lst->win_ratio,
			camera->clip.x, camera->clip.y);
}
