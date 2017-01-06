/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_component_class.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:56:32 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/06 13:32:49 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_COMPONENT_CLASS_H
# define OBJ_COMPONENT_CLASS_H

# include "obj.h"

typedef struct s_obj_component_class		t_obj_component_class;

/*
** ========================================================================== **
*/

struct		s_obj_component_class
{
	t_obj_component	*(*create)(void const *data, void *param);
	void			*param;
};

#endif
