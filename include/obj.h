/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 23:23:58 by juloo             #+#    #+#             */
/*   Updated: 2015/10/14 15:14:45 by jaguillo         ###   ########.fr       */
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
// public require renderer

# include "math_utils.h"
# include "mesh_loader.h"
# include "transform.h"
# include "anim.h"
# include "scop.h" // TODO renderer

/*
** Represent an object
*/
struct			s_obj
{
	t_mesh const	*mesh;
	t_renderer		renderer;
	t_anim			*anim;
	t_transform		transform;
};

#endif
