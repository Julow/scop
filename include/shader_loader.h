/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_loader.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 12:24:55 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/09 18:40:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER_LOADER_H
# define SHADER_LOADER_H

# include "libft.h"

# define LOAD_SHADER_BUFFER		256
# define ERR_SHADER_BUFFER 		128

typedef struct	s_shader
{
	t_uint			handle;
	t_uint			model_loc;
	t_uint			view_loc;
	t_uint			projection_loc;
	t_uint			lightpos_loc;
	t_uint			lightcount_loc;
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
