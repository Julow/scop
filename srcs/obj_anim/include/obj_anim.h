/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_anim.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 20:08:09 by juloo             #+#    #+#             */
/*   Updated: 2016/11/21 17:32:32 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_ANIM_H
# define OBJ_ANIM_H

# include "ft/math_vec3.h"

# include "anim.h"
# include "obj.h"

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
void			anim_c_scale3(t_obj *obj, float delta);

/*
** Create an obj anim
** -
** d		duration
** l		flags
** f		from (x, y, z)
** t		to (x, y, z)
*/
# define ANIM_MOVE(d,l,f,t,s)	_OBJ_ANIM((d,l,&anim_c_move,s),f,VEC3 t)
# define ANIM_ROT(d,l,f,t,s)	_OBJ_ANIM((d,l,&anim_c_rot,s),f,VEC3 t)
# define ANIM_SHEAR(d,l,f,t,s)	_OBJ_ANIM((d,l,&anim_c_shear,s),f,VEC3 t)
# define ANIM_SCALE(d,l,f,t,s)	_OBJ_ANIM((d,l,&anim_c_scale,s),f,VEC3(t,0,0))
# define ANIM_SCALE3(d,l,f,t,s)	_OBJ_ANIM((d,l,&anim_c_scale3,s),f,VEC3 t)

# define _OBJ_ANIM(a,f,t)		((t_anim*)&(struct s_anim_obj){ANIM a,VEC3 f,t})

#endif
