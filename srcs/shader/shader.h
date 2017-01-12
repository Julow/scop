/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 10:50:57 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/12 15:45:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER_H
# define SHADER_H

# include "ft/gl.h"
# include "ft/libft.h"

typedef struct s_shader		t_shader;
typedef GLint				t_uniform_loc;

/*
** Represent a shader program
*/
struct			s_shader
{
	GLuint			handle;
};

#endif
