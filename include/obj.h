/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 23:23:58 by juloo             #+#    #+#             */
/*   Updated: 2015/09/27 16:12:06 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H

# include "scop.h"
# include "math_utils.h"
# include "transform.h"

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
