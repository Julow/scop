/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 23:23:58 by juloo             #+#    #+#             */
/*   Updated: 2015/09/21 23:29:58 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H

# include "math_utils.h" // TODO: Clean up includes
# include "mesh_loader.h" // Every includes
# include "texture_loader.h"
# include "shader_loader.h"

# define F_OBJ_UPDATED		(1 << 1)

// TODO: move 'mesh' field in an other part
typedef struct	s_obj
{
	t_mesh const	*mesh;
	t_texture const	*texture;
	t_shader const	*shader;
	t_mat4			model_m[2];
	t_vec3			position;
	t_vec3			rotation;
	float			scale;
	int				flags;
}				t_obj;

# define OBJ(m,t,s)			((t_obj){(m), (t), (s), 0, 0, 0, 0})

/*
** Setters
*/
void			obj_move(t_obj *obj, t_vec3 pos);
void			obj_rotate(t_obj *obj, t_vec3 rot);
void			obj_scale(t_obj *obj, float scale);

/*
** Return the model matrix and it's inverse (t_mat4[2])
** Recompute it if needed
*/
t_mat4			*obj_get_model(t_obj *obj);

#endif
