/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_loader.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 12:24:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/17 11:04:14 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER_LOADER_H
# define SHADER_LOADER_H

# include "libft.h"
# include "gl.h"

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

/*
** ?enum shader_t
** t_uint			index;
** t_sub			name;
** t_uint			gl_name;
** ALL(1, SUBC("all"), 0),
** VERT(2, SUBC("vert"), GL_VERTEX_SHADER),
** FRAG(0, SUBC("frag"), GL_FRAGMENT_SHADER),
*/

struct			s_evalue_shader_t
{
	t_uint			index;
	t_sub			name;
	t_uint			gl_name;

};

typedef struct s_evalue_shader_t const*		t_shader_t;

struct			s_enum_shader_t
{
	t_shader_t			FRAG;
	t_shader_t			ALL;
	t_shader_t			VERT;
	int					length;
	t_shader_t const	*values;
};

extern struct s_enum_shader_t const		g_shader_t;

/*
** ?end
*/

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
