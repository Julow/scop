/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 23:23:58 by juloo             #+#    #+#             */
/*   Updated: 2016/11/25 11:42:18 by jaguillo         ###   ########.fr       */
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
typedef struct s_obj_component	t_obj_component;
typedef struct s_obj_renderer	t_obj_renderer;

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
** obj's component base class
** 'update' is called at each update step, one at a time, parent first
*/
struct			s_obj_component
{
	void			(*update)(t_obj_component *component, t_obj *obj);
};

# define OBJ_COMPONENT(UPDATE)	((t_obj_component){V(UPDATE)})

/*
** obj's renderer base class
** 'render' is called at the render step, parent first
*/
struct			s_obj_renderer
{
	void			(*render)(t_obj_renderer *renderer, t_mat4 const *model);
};

# define OBJ_RENDERER(RENDER)	((t_obj_renderer){V(RENDER)})

/*
** Represent an object
*/
struct			s_obj
{
	t_obj_renderer	*renderer;
	t_transform		transform;
	t_mat4			transform_m;
	t_vector		components;
	t_vector		childs;
	uint32_t		flags;
};

# define OBJ()	((t_obj){NULL,{},{},VECTOR(t_obj_component*),VECTOR(t_obj),0})

# define OBJ_F_MATRIX_OK	(1 << 0)
# define OBJ_F_HIDE			(1 << 1)

/*
** Return the transformation matrix
*/
t_mat4 const	*obj_matrix(t_obj *obj);

/*
** Apply transform to an object
*/
void			obj_translate(t_obj *obj, t_vec3 translate);
void			obj_rotate(t_obj *obj, t_vec3 rotate);
void			obj_shear(t_obj *obj, t_vec3 shear);
void			obj_scale(t_obj *obj, t_vec3 scale);

#endif
