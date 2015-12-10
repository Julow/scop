/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 10:29:58 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:58:33 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "shader_loader.h"
# include "ft/ft_list.h"

/*
** ?enum shader_t
** uint32_t			index;
** t_sub			name;
** uint32_t			gl_name;
** all(?id?, SUBC("?name?"), 0),
** vert(?id?, SUBC("?name?"), GL_VERTEX_SHADER),
** frag(?id?, SUBC("?name?"), GL_FRAGMENT_SHADER),
*/

struct			s_evalue_shader_t
{
	uint32_t		index;
	t_sub			name;
	uint32_t		gl_name;
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

bool			read_shader(int fd, t_list *lines, uint32_t *s, t_shader_t t);

bool			compile_shader(t_list *lines, uint32_t *dst, t_shader_t t);

void			load_uniforms(uint32_t handle, t_hmap *uniforms);

#endif
