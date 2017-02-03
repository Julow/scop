/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_component.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 22:09:02 by jaguillo          #+#    #+#             */
/*   Updated: 2017/02/03 13:41:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIM_COMPONENT_H
# define ANIM_COMPONENT_H

# include "ft/libft.h"
# include "ft/math_vec3.h"

# include "anim.h"
# include "obj.h"

typedef struct s_anim_component			t_anim_component;
typedef struct s_anim_component_param	t_anim_component_param;
typedef enum e_obj_anim_t				t_obj_anim_t;

/*
** ========================================================================== **
** Animation Component
*/

enum			e_obj_anim_t
{
	OBJ_ANIM_TRANSLATE,
	OBJ_ANIM_ROTATE,
	OBJ_ANIM_SHEAR,
	OBJ_ANIM_SCALE,
};

struct			s_anim_component
{
	t_obj_component	c;
	t_anim			anim;
	t_vec3			from;
	t_vec3			offset;
	t_obj_anim_t	type;
};

struct			s_anim_component_param
{
	t_vec3			from;
	t_vec3			to;
	float			duration;
	float			(*smooth)(float);
	t_obj_anim_t	type;
	uint32_t		flags;
};

/*
** Create an anim_component object
** 'flags' is any combination of anim's flags
*/
t_obj_component	*create_anim_component(t_anim_component_param const *param);

#endif
