/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 23:23:58 by juloo             #+#    #+#             */
/*   Updated: 2016/11/21 17:32:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H

# include "ft/ft_list.h"
# include "ft/ft_vector.h"
# include "ft/math_mat4.h"
# include "ft/math_vec3.h"

# include "anim.h"
# include "camera.h"
# include "mesh.h"

typedef struct s_obj			t_obj;
typedef struct s_transform		t_transform;

/*
** ========================================================================== **
*/

/*
** Hold transformations
*/
struct			s_transform
{
	t_vec3			position;
	t_vec3			rotation;
	t_vec3			shear;
	t_vec3			scale;
};

/*
** Represent an object
*/
struct			s_obj
{
	t_mesh const	*mesh;
	t_anim			*anim;
	t_transform		transform; // TODO: remove this
	t_transform		world_transform;
	t_mat4			world_matrix;
	t_list			components;
	t_vector		childs;
	uint32_t		flags;
};

# define OBJ_F_MATRIX_OK	(1 << 0)
# define OBJ_F_HIDE			(1 << 1)

/*
** Return the transformation matrix
*/
t_mat4 const	*ft_obj_matrix(t_obj *obj);

/*
** Apply transform to an object
*/
void			ft_obj_translate(t_obj *obj, t_vec3 translate, bool set);
void			ft_obj_rotate(t_obj *obj, t_vec3 rotate, bool set);
void			ft_obj_shear(t_obj *obj, t_vec3 shear, bool set);
void			ft_obj_scale(t_obj *obj, t_vec3 scale, bool set);

#endif
