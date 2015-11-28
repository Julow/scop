/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh_loader.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 12:11:38 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/27 23:39:58 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_LOADER_H
# define MESH_LOADER_H

# include "ft/ft_vector.h"
# include "mesh.h"

/*
** Load a mesh from a file (.obj)
** -
** Return NULL on error
*/
t_mesh const	*load_mesh(t_sub file_name);

#endif
