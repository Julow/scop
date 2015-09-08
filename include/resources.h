/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 13:07:48 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/08 19:01:58 by jaguillo         ###   ########.fr       */
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
# define RES(t,n,...)		((t_res*)&(t_res_##t){{res_##t,n},##__VA_ARGS__})

# define RES_SHADER(n,v,f)	RES(shader, SUBC(n), SHADERS_DIR v, SHADERS_DIR f)
# define RES_TEXTURE(n,f)	RES(texture, SUBC(n), TEXTURES_DIR f)
# define RES_MESH(n,f)		RES(mesh, SUBC(n), MESHES_DIR f)
# define RES_MTL(f)			RES(mtl, SUBC(f), MATERIALS_DIR f)

typedef struct	s_res
{
	t_res_t			type;
	t_sub			name;
}				t_res;

typedef struct	s_res_shader
{
	t_res			res;
	char const		*vert_file;
	char const		*frag_file;
}				t_res_shader;

typedef struct	s_res_texture
{
	t_res			res;
	char const		*file;
}				t_res_texture;

typedef struct	s_res_mesh
{
	t_res			res;
	char const		*file;
}				t_res_mesh;

typedef struct	s_res_mtl
{
	t_res			res;
	char const		*file;
}				t_res_mtl;

typedef struct	s_res_config
{
	char const		*basedir;
	t_bool			(*const loader)();
	int				res_size;
}				t_res_config;

t_bool			shader_res_loader(void *dst, t_res_shader const *res);
t_bool			texture_res_loader(void *dst, t_res_texture const *res);
t_bool			mesh_res_loader(void *dst, t_res_mesh const *res);
t_bool			mtl_res_loader(void *dst, t_res_mtl const *res);

#endif
