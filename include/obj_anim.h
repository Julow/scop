/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_anim.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 20:08:09 by juloo             #+#    #+#             */
/*   Updated: 2015/09/27 20:51:39 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_ANIM_H
# define OBJ_ANIM_H

# include "scop.h"
# include "math_utils.h"
# include "anim.h"

struct			s_anim_obj
{
	t_anim			anim;
	t_vec3			from;
	t_vec3			to;
};

void			anim_c_move(t_obj *obj, float delta);
void			anim_c_rot(t_obj *obj, float delta);
void			anim_c_shear(t_obj *obj, float delta);
void			anim_c_scale(t_obj *obj, float delta);

/*
** Create an obj anim
** -
** d		duration
** l		flags
** f		from (x, y, z)
** t		to (x, y, z)
*/
# define ANIM_MOVE(d,l,f,t)		_OBJ_ANIM(ANIM(d,l,&anim_c_move),VEC3 f,VEC3 t)
# define ANIM_ROT(d,l,f,t)		_OBJ_ANIM(ANIM(d,l,&anim_c_rot),VEC3 f,VEC3 t)
# define ANIM_SHEAR(d,l,f,t)	_OBJ_ANIM(ANIM(d,l,&anim_c_shear),VEC3 f,VEC3 t)
# define ANIM_SCALE(d,l,f,t)	_OBJ_ANIM(ANIM(d,l,&anim_c_scale),VEC3(f, 0.f, 0.f),VEC3(t, 0.f, 0.f))

# define _OBJ_ANIM(a,f,t)		((t_anim*)(&(struct s_anim_obj){a,f,t}))

#endif
