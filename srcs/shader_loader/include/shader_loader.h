/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_loader.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 12:24:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/10/14 15:15:06 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER_LOADER_H
# define SHADER_LOADER_H

typedef struct s_shader		t_shader;
typedef struct s_uniform	t_uniform;

// module: shader_loader
// public require libft
// public require libft::hmap
// private require gl
// private require utils
// private require libft::list
// private extern require unistd
// private extern require fcntl

# include "libft.h"

# define SHADER_CACHE_SIZE		10
# define SHADER_LOC_SIZE		25

# define LOAD_SHADER_BUFFER		512
# define LOAD_UNIFORM_BUFFER	128
# define ERR_SHADER_BUFFER 		1024

# define SHADER_START			(SUBC("//#shader "))

/*
** Represent a shader program
*/
struct			s_shader
{
	t_hmap const	*uniforms;
	t_uint			handle;
};

/*
** Represent an uniform
*/
struct			s_uniform
{
	t_uint			loc;
	int				size;
	t_uint			type;
};

/*
** Set an uniform
** t		glUniform* suffix
** s		shader
** n		uniform name
** ...		corresponding glUniform* arguments
*/
# define UNIFORM(t,s,n,...)	(glUniform##t(_UNIFORM(s,n), ##__VA_ARGS__))

// # define _UNIFORM(s,n)		(glGetUniformLocation((s)->handle, n))
// # define _UNIFORM(s,n)		(((t_uniform const*)ft_hmapget((s)->uniforms, SUBC(n)))->loc)
# define _UNIFORM(s,n)		(shader_get_uniform(s,SUBC(n)))

t_uint			shader_get_uniform(t_shader const *shader, t_sub name);

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
** -
** Return NULL on error
*/
t_shader const	*load_shader(t_sub file_name);

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

void			load_uniforms(t_uint handle, t_hmap *uniforms);

#endif
