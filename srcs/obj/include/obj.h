/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 23:23:58 by juloo             #+#    #+#             */
/*   Updated: 2017/01/11 17:55:41 by jaguillo         ###   ########.fr       */
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
** Represent an object
** -
** local		=> Local transformations (relative to parent's)
** world_m		=> World space matrix
** components	=> Components array (t_obj_component*)
** childs		=> Child objs array (t_obj)
** moving		=> If the object localy moved during the current frame
** 					(world_m is not up to date)
** moved		=> If the object moved (in world space) during the last frame
*/
struct			s_obj
{
	t_transform		local;
	t_mat4			world_m;
	t_vector		components;
	t_vector		childs;
	bool			moving:1;
	bool			moved:1;
};

# define OBJ()	((t_obj){{},{},VECTOR(t_obj_component*),VECTOR(t_obj),1,0})

/*
** Recursively update object's components
*/
void			obj_update(t_vector *objs);

/*
** Apply transform to an object
*/
void			obj_translate(t_obj *obj, t_vec3 translate);
void			obj_rotate(t_obj *obj, t_vec3 rotate);
void			obj_shear(t_obj *obj, t_vec3 shear);
void			obj_scale(t_obj *obj, t_vec3 scale);

#endif
