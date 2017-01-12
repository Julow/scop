/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtl_loader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 15:08:52 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/12 15:29:54 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTL_LOADER_H
# define MTL_LOADER_H

# include "ft/libft.h"
# include "ft/set.h"

typedef struct s_mtllib_mtl		t_mtllib_mtl;
typedef struct s_mtllib			t_mtllib;

/*
** ========================================================================== **
*/

struct			s_mtllib_mtl
{
	t_set_h			set_head;
	t_sub			name;
	t_mtl			mtl;
};

struct			s_mtllib
{
	t_set			mtls;
};

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
t_mtllib const	*load_mtl(t_sub file_name);

/*
** Retrieve a mtl by it's name
** Return NULL if not found
*/
t_mtl const		*mtllib_get(t_mtllib const *lib, t_sub name);

#endif
