/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 23:23:58 by juloo             #+#    #+#             */
/*   Updated: 2015/12/08 17:04:04 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H

typedef struct s_obj			t_obj;

# include "ft/ft_vector.h"
# include "ft/math.h"
# include "mesh.h"
# include "transform.h"
# include "anim.h"
# include "camera.h"

/*
** Represent an object
*/
struct			s_obj
{
	t_mesh const	*mesh;
	t_anim			*anim; // TODO: remove
	t_transform		transform;
	t_vector		childs;
	uint32_t		flags;
};

#endif
