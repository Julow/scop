/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:14:01 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/25 14:58:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"

#include "mesh.h"
#include "p_mesh_renderer.h"

t_obj_renderer	*create_mesh_renderer(t_mesh_render *r, t_mesh const *mesh)
{
	t_mesh_renderer *const	renderer = NEW(t_mesh_renderer);

	*renderer = (t_mesh_renderer){
		OBJ_RENDERER(mesh_renderer_render),
		r,
		mesh
	};
	return (V(renderer));
}
