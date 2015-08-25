/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 12:48:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/25 15:23:07 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_UTILS_H
# define MATH_UTILS_H

typedef struct	s_vec2
{
	float			x;
	float			y;
}				t_vec2;

typedef struct	s_vec3
{
	float			x;
	float			y;
	float			z;
}				t_vec3;

typedef struct	s_vec4
{
	float			x;
	float			y;
	float			z;
	float			w;
}				t_vec4;

typedef struct	s_mat4
{
	t_vec4			x;
	t_vec4			y;
	t_vec4			z;
	t_vec4			w;
}				t_mat4;

# define VEC2(x,y)			((t_vec2){(x), (y)})
# define VEC3(x,y,z)		((t_vec3){(x), (y), (z)})
# define VEC4(x,y,z,w)		((t_vec4){(x), (y), (z), (w)})

# define MAT4(x,y,z,w)		((t_mat4){VEC4 x, VEC4 y, VEC4 z, VEC4 w})

/*
** mat4 init
*/
t_mat4			ft_mat4identity(void);
t_mat4			ft_mat4perspective(float fov, float ratio, float f, float n);

/*
** mat4 transformations
*/
void			ft_mat4scale(t_mat4 *m, t_vec3 scale);
void			ft_mat4rotate(t_mat4 *m, t_vec3 rotate);
void			ft_mat4translate(t_mat4 *m, t_vec3 translate);

/*
** mat4 operations
*/
void			ft_mat4mult(t_mat4 *a, t_mat4 b);

#endif