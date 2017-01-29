/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_component.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:51:43 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/29 17:58:32 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

static void	camera_update(t_camera *c, t_obj *obj)
{
	if (obj->moved)
	{
		ft_mat4mult(&c->proj_m, &obj->world_inv_m, &c->viewproj_m);
	}
}

t_camera	*create_camera(t_camera_param const *param,
				t_camera_list *camera_list)
{
	t_camera		*camera;

	camera = ft_listadd(&camera_list->cameras, camera_list->cameras.last, 0);
	*camera = (t_camera){
		OBJ_COMPONENT(&camera_update),
		{},
		{},
		VEC2(param->near, param->far),
		param->fov,
	};
	return (camera);
}
