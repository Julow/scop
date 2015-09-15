/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_loader.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 12:24:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/15 19:03:22 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER_LOADER_H
# define SHADER_LOADER_H

# include "libft.h"

# define LOAD_SHADER_BUFFER		256
# define ERR_SHADER_BUFFER 		1024

typedef enum	e_locations
{
	model,
	view,
	projection,
	camera_pos,
	light_pos,
	light_count,
	ambient_map,
	diffuse_map,
	specular_map,
	ambient_color,
	diffuse_color,
	specular_color,
	specular_exp,
	locations_count
}				t_locations;

typedef struct	s_shader
{
	t_uint			handle;
	t_uint			loc[locations_count];
}				t_shader;

typedef struct	s_shader_c
{
	char				*str;
	int					length;
	struct s_shader_c	*prev;
}				t_shader_c;

// enum	ShaderType
// {
// 	char const		*str;
// 	t_uint			gl_name;

// 	ALL("lol", GL_VERTEX_SHADER),
// 	VERT("lol", GL_VERTEX_SHADER),
// 	FRAG("lol", GL_VERTEX_SHADER)
// };

/*
** [enum] shader_type
** char const		*name;
** t_uint			gl_name;
** ALL("all", 0),
** VERT("vert", GL_VERTEX_SHADER),
** FRAG("frag", GL_FRAGMENT_SHADER),
*/

// struct			s_ShaderType
// {
// 	char const		*str;
// 	t_uint			gl_name;;
// };

// static struct
// {
// 	struct s_ShaderType	ALL;
// 	struct s_ShaderType	VERT;
// 	struct s_ShaderType	FRAG;
// } const ShaderType = {
// 	{"all", 0},
// 	{"vert", GL_VERTEX_SHADER},
// 	{"frag", GL_FRAGMENT_SHADER},
// }

/*
** Load a shader program
** -
**  // code for all shaders
** //#shader vert
**  // code for vert shader
** //#shader all
**  // code for frag and geom shader
** //#shader frag
**  // code for frag shader
** //#shader geom
**  // code for geom shader
** -
** a //#shader cannot be repeated (except 'all')
*/
t_bool			load_shader(char const *file, t_shader *p);

#endif
