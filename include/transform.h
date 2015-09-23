/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 08:34:28 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/23 10:13:10 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

# include "scop.h"
# include "math_utils.h"

/*
** Hold transformation matrix
** and it's transposed inverse
*/

struct			s_transform
{
	t_mat4			matrix[2];
	t_vec3			position;
	t_vec3			rotation;
	float			scale;
	int				flags;
};

/*
** Init a transform
** p		Position (tuple of float)
** r		Rotation (tuple of float)
** s		Scale (float)
** f		Reflect (bit field)
*/
# define TRANSFORM(p,r,s,f)	((t_transform){{MAT4_0(), MAT4_0()}, VEC3 p, VEC3 r, VEC2_0(), s, f})

/*
** This flag is unset when the matrices need to be updated
*/
# define F_TRANSFORM_OK		(1 << 14)

/*
** Set transformations
*/
void			ft_transform_move(t_transform *t, t_vec3 pos);
void			ft_transform_rotate(t_transform *t, t_vec3 rot);
void			ft_transform_scale(t_transform *t, float scale);
void			ft_transform_reflect(t_transform *t, int reflects);

/*
** Return the matrix and it's inverse
** Update it if needed
*/
t_mat4 const	*ft_transform_get(t_transform *t);

#endif
