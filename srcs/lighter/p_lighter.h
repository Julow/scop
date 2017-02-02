/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_lighter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:05:39 by jaguillo          #+#    #+#             */
/*   Updated: 2017/02/02 17:11:43 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_LIGHTER_H
# define P_LIGHTER_H

# include "lighter.h"

/*
** ========================================================================== **
*/

/*
** Setup
*/
bool			setup_point_lights(t_lighter *dst);

/*
** Render
*/
void			render_point_lights(t_lighter *lighter);

/*
** Reallocate point_vbo if needed
*/
void			check_point_vbo(t_lighter *lighter);

#endif
