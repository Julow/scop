/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_loader.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 12:24:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/17 16:02:14 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER_LOADER_H
# define SHADER_LOADER_H

# include "libft.h"
# include "ft_list.h"
# include "gl.h"

# define LOAD_SHADER_BUFFER		256
# define ERR_SHADER_BUFFER 		1024

# define SHADER_START		(SUBC("//#shader "))

/*
** ?enum loc length-macro(G_LOC_LENGTH)
** t_uint			index;
** char const		*name;
** model(0, "model"),
** view(1, "view"),
** projection(2, "projection"),
** camera_pos(3, "camera_pos"),
** light_pos(4, "light_pos"),
** light_count(5, "light_count"),
** ambient_map(6, "ambient_map"),
** diffuse_map(7, "diffuse_map"),
** specular_map(8, "specular_map"),
** ambient_color(9, "ambient_color"),
** diffuse_color(10, "diffuse_color"),
** specular_color(11, "specular_color"),
** specular_exp(12, "specular_exp"),
*/

struct			s_evalue_loc
{
	t_uint			index;
	char const		*name;

};

typedef struct s_evalue_loc const*		t_loc;

struct			s_enum_loc
{
	t_loc			model;
	t_loc			view;
	t_loc			projection;
	t_loc			camera_pos;
	t_loc			light_pos;
	t_loc			light_count;
	t_loc			ambient_map;
	t_loc			diffuse_map;
	t_loc			specular_map;
	t_loc			ambient_color;
	t_loc			diffuse_color;
	t_loc			specular_color;
	t_loc			specular_exp;
	int					length;
	t_loc const	*values;
};

extern struct s_enum_loc const		g_loc;

# define G_LOC_LENGTH		13

/*
** ?end
*/

typedef struct	s_shader
{
	t_uint			handle;
	t_uint			loc[G_LOC_LENGTH];
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
** ALL(0, SUBC("all"), 0),
** VERT(1, SUBC("vert"), GL_VERTEX_SHADER),
** FRAG(2, SUBC("frag"), GL_FRAGMENT_SHADER),
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
	t_shader_t			ALL;
	t_shader_t			VERT;
	t_shader_t			FRAG;
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

/*
** internal
*/

t_bool			read_shader(int fd, t_list *lines, t_uint *s, t_shader_t t);

t_bool			compile_shader(t_list *lines, t_uint *dst, t_shader_t t);

#endif
