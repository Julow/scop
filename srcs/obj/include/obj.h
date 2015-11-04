/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 23:23:58 by juloo             #+#    #+#             */
/*   Updated: 2015/11/04 23:54:50 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H

typedef struct s_obj			t_obj;
typedef struct s_render_params	t_render_params;

# include "math_utils.h"
# include "mesh.h"
# include "transform.h"
# include "anim.h"
# include "camera.h"

struct			s_render_params
{
	t_camera		*camera;
	t_mat4			*projection_m;
};

/*
** Represent an object
*/
struct			s_obj
{
	t_mesh const	*mesh;
	t_anim			*anim;
	t_transform		transform;
	void			(*render)(t_render_params const*, t_obj*);
};

#endif
