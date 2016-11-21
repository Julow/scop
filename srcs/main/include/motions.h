/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 18:52:01 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/21 17:33:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOTIONS_H
# define MOTIONS_H

/*
** TODO: improve this shit
*/

# include "ft/math_vec2.h"

/*
** TODO: Allow main to implement motion defs
*/

typedef struct s_motion_def		t_motion_def;

struct			s_motion_def
{
	int				flag;
	void			(*f)(t_vec2 dir, t_vec3 *move, float inv);
	float			inv;
};

bool			handle_key_hold(t_scop *scop, float elapsed, t_vec3 *pos);
bool			handle_cursor_move(t_scop *scop, t_vec2 *look);

#endif
