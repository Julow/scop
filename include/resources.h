/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 13:07:48 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/19 18:55:39 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOURCES_H
# define RESOURCES_H

# include "libft.h"

# define SHADERS_DIR		"res/shaders/"
# define TEXTURES_DIR		"res/tga/"
# define MESHES_DIR			"res/obj/"
# define MATERIALS_DIR		"res/mtl/"

/*
** ?enum res_t length-macro(RES_T_COUNT)
** int				index;
** char const		*basedir;
** t_bool			(*const loader)();
** int				res_size;
** shader(0, SHADERS_DIR, &load_shader, sizeof(t_shader)),
** texture(1, TEXTURES_DIR, &load_texture, sizeof(t_texture)),
** mesh(2, MESHES_DIR, &load_mesh, sizeof(t_mesh)),
** mtl(3, MATERIALS_DIR, &load_mtl, sizeof(t_mtl)),
*/

struct			s_evalue_res_t
{
	int				index;
	char const		*basedir;
	t_bool			(*const loader)();
	int				res_size;

};

typedef struct s_evalue_res_t const*		t_res_t;

struct			s_enum_res_t
{
	t_res_t			shader;
	t_res_t			texture;
	t_res_t			mesh;
	t_res_t			mtl;
	int					length;
	t_res_t const	*values;
};

extern struct s_enum_res_t const		g_res_t;

# define RES_T_COUNT		4

/*
** ?end
*/

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
