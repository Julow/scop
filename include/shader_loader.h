/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_loader.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 12:24:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/22 08:29:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER_LOADER_H
# define SHADER_LOADER_H

# include "scop.h"

# define LOAD_SHADER_BUFFER		256
# define ERR_SHADER_BUFFER 		1024

# define SHADER_START		(SUBC("//#shader "))

struct			s_shader
{
	t_uint			*loc;
	void			(*pre)();
	void			(*mtl)();
	t_uint			handle;
};

struct			s_shader_def
{
	char const		*file_name;
	void			(*pre)();
	void			(*mtl)();
	char const		**uniforms;
	int				uniform_count;
};

# define SHADER_DEF(f,a,b,u)	{SHADERS_DIR f, a, b, u, sizeof(u) / sizeof(u[0])}
# define SHADER_DEF_END()		{NULL, NULL, NULL, NULL, 0}

/*
** g_shader_def have to be declared by the user
*/
extern const t_shader_def	g_shader_def[];

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

/*
** ?enum shader_t
** t_uint			index;
** t_sub			name;
** t_uint			gl_name;
** all(?id?, SUBC("?name?"), 0),
** vert(?id?, SUBC("?name?"), GL_VERTEX_SHADER),
** frag(?id?, SUBC("?name?"), GL_FRAGMENT_SHADER),
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
	t_shader_t			all;
	t_shader_t			vert;
	t_shader_t			frag;
	int					length;
	t_shader_t const	*values;
};

extern struct s_enum_shader_t const		g_shader_t;

/*
** ?end
*/

t_bool			read_shader(int fd, t_list *lines, t_uint *s, t_shader_t t);

t_bool			compile_shader(t_list *lines, t_uint *dst, t_shader_t t);

#endif
