/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 10:29:58 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/11 19:53:03 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "shader_loader.h"
# include "ft_list.h"

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
