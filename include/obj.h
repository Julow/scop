/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 23:23:58 by juloo             #+#    #+#             */
/*   Updated: 2015/09/23 09:02:19 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H

# include "scop.h"
# include "math_utils.h"
# include "transform.h"

struct			s_obj
{
	t_mesh const	*mesh;
	t_texture const	*texture;
	t_shader const	*shader;
	t_transform		transform;
};

#endif
