/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 08:34:28 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/03 23:57:47 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

typedef struct s_transform	t_transform;

# include "math_utils.h"

/*
** Hold transformation matrix
** and it's transposed inverse
** -
** bzero can be used to reset transformations
*/

struct			s_transform
{
	t_mat4			matrix[2];
	t_vec3			position;
	t_vec3			origin;
	t_vec3			rotation;
	t_vec3			shear;
	t_vec3			scale;
	int				flags;
};

/*
** This flag is unset when the matrices need to be updated
*/
# define F_TRANSFORM_OK		(1 << 14)

/*
** Set transformations
*/
void			ft_transform_move(t_transform *t, t_vec3 pos);
void			ft_transform_origin(t_transform *t, t_vec3 origin);
void			ft_transform_rotate(t_transform *t, t_vec3 rot);
void			ft_transform_scale(t_transform *t, float scale);
void			ft_transform_scale3(t_transform *t, t_vec3 scale);
void			ft_transform_reflect(t_transform *t, int reflects);
void			ft_transform_shear(t_transform *t, t_vec3 shear);

/*
** Return the matrix and it's inverse
** Update it if needed
*/
t_mat4 const	*ft_transform_get(t_transform *t);

#endif
