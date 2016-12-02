/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 10:50:57 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/25 14:40:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER_H
# define SHADER_H

# include "ft/ft_hmap.h"
# include "ft/libft.h"

typedef struct s_shader		t_shader;
typedef struct s_uniform	t_uniform;
typedef int					t_uniform_loc;

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
	uint32_t		handle;
};

/*
** Represent an uniform
*/
struct			s_uniform
{
	t_uniform_loc	loc;
	int				size;
	uint32_t		type;
};

/*
** Set an uniform
** t		glUniform* suffix
** s		shader
** n		uniform name
** ...		corresponding glUniform* arguments
*/
# define UNIFORM(t,s,n,...)	(glUniform##t(_UNIFORM(s,n), ##__VA_ARGS__))

# define _UNIFORM(s,n)		(shader_get_uniform(s,SUBC(n)))

t_uniform_loc	shader_get_uniform(t_shader const *shader, t_sub name);

#endif
