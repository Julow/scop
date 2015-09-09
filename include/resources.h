/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 13:07:48 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/09 18:37:52 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOURCES_H
# define RESOURCES_H

# include "libft.h"

# define SHADERS_DIR		"res/shaders/"
# define TEXTURES_DIR		"res/tga/"
# define MESHES_DIR			"res/obj/"
# define MATERIALS_DIR		"res/mtl/"

typedef enum	e_res_t
{
	res_shader,
	res_texture,
	res_mesh,
	res_mtl,
	res_t_count
}				t_res_t;

/*
** Search for a ressource with type 'type' and name 'name'
** Ressources are cached (loaded once)
** Return NULL if not found or if an error occur
*/
void const		*get_res(t_res_t type, t_sub name);

/*
** internal
*/

typedef struct	s_res_config
{
	char const		*basedir;
	t_bool			(*const loader)();
	int				res_size;
}				t_res_config;

#endif
