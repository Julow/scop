/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_loader.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 12:24:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/14 13:21:04 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER_LOADER_H
# define SHADER_LOADER_H

# include "libft.h"

# define LOAD_SHADER_BUFFER		256
# define ERR_SHADER_BUFFER 		128

typedef enum	e_locations
{
	model,
	view,
	projection,
	camera_pos,
	light_pos,
	light_count,
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
** Load a shader program
** Requesting "test" will try to compile "test.vert" and "test.frag"
*/
t_bool			load_shader(char const *file, t_shader *p);

#endif
