/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 08:34:28 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:59:30 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

# include "ft/math.h"

typedef struct s_transform	t_transform;

/*
** Hold transformation matrix
** -
** bzero can be used to reset transformations
*/

struct			s_transform
{
	t_mat4			_matrix;
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
** Return the matrix
** Update it if needed
*/
t_mat4 const	*ft_transform_get(t_transform *t);

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

#endif
