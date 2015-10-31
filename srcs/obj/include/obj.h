/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 23:23:58 by juloo             #+#    #+#             */
/*   Updated: 2015/10/31 12:40:51 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H

typedef struct s_obj		t_obj;

// module: obj
// public require math_utils
// public require transform
// public require mesh_loader
// public require anim

# include "math_utils.h"
# include "mesh_loader.h"
# include "transform.h"
# include "anim.h"

/*
** Represent an object
*/
struct			s_obj
{
	t_mesh const	*mesh;
	t_anim			*anim;
	t_transform		transform;
};

#endif
