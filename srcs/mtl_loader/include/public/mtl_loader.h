/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtl_loader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 15:08:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/27 23:39:24 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTL_LOADER_H
# define MTL_LOADER_H

# include "ft/libft.h"
# include "ft/ft_hmap.h"

/*
** newmtl <name>				Create a mtl
** Ka <float> <float> <float>	ambient
** Kd <float> <float> <float>	diffuse
** Ks <float> <float> <float>	specular
** Ns <float>					specular exponent
** map_Ka <file>				ambient map
** map_Kd <file>				diffuse map
** map_Ks <file>				specular map
*/

/*
** Load mtls from a file
** -
** Return NULL on error
*/
t_hmap const	*load_mtl(t_sub file_name);

#endif
