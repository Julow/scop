/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_get_model.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 23:27:31 by juloo             #+#    #+#             */
/*   Updated: 2015/09/21 23:27:43 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj.h"

t_mat4			*obj_get_model(t_obj *obj)
{
	if (obj->flags & F_OBJ_UPDATED)
	{
		obj->model_m[0] = MAT4_I();
		ft_mat4translate(obj->model_m, obj->position);
		ft_mat4scale(obj->model_m, obj->scale);
		ft_mat4rotate(obj->model_m, obj->rotation);
		obj->model_m[1] = MAT4_I();
		ft_mat4rotate_inv(obj->model_m + 1,
			ft_vec3sub(VEC3_0(), obj->rotation));
		ft_mat4scale(obj->model_m + 1, 1.f / obj->scale);
		ft_mat4translate(obj->model_m + 1, ft_vec3sub(VEC3_0(), obj->position));
		ft_mat4transpose(obj->model_m + 1);
		obj->flags &= ~F_OBJ_UPDATED;
	}
	return (obj->model_m);
}
