/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_component_class.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:56:32 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/22 17:53:51 by juloo            ###   ########.fr       */
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
	t_obj_component	*(*create)(void const *data);
};

#endif
