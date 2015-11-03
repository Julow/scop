/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 10:50:57 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/03 10:51:20 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER_H
# define SHADER_H

typedef struct s_shader		t_shader;
typedef struct s_uniform	t_uniform;

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

#endif
