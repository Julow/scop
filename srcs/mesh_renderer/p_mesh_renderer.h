/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_mesh_renderer.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:14:38 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/25 11:42:00 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_MESH_RENDERER_H
# define P_MESH_RENDERER_H

# include "mesh_renderer.h"

/*
** ========================================================================== **
*/

void			mesh_renderer_render(t_mesh_renderer *r, t_mat4 const *model);

#endif
