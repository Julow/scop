/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4shear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 10:23:18 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/23 10:29:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_utils.h"

static void		ft_mat4shear_x(t_mat4 *mat, float x)
{
	t_mat4 const	shear_mat = {
		{1.f, x, x, 0.f},
		{0.f, 1.f, 0.f, 0.f},
		{0.f, 0.f, 1.f, 0.f},
		{0.f, 0.f, 0.f, 1.f}
	};

	ft_mat4mult(mat, shear_mat);
}

static void		ft_mat4shear_y(t_mat4 *mat, float y)
{
	t_mat4 const	shear_mat = {
		{1.f, 0.f, 0.f, 0.f},
		{y, 1.f, y, 0.f},
		{0.f, 0.f, 1.f, 0.f},
		{0.f, 0.f, 0.f, 1.f}
	};

	ft_mat4mult(mat, shear_mat);
}

static void		ft_mat4shear_z(t_mat4 *mat, float z)
{
	t_mat4 const	shear_mat = {
		{1.f, 0.f, 0.f, 0.f},
		{0.f, 1.f, 0.f, 0.f},
		{z, z, 1.f, 0.f},
		{0.f, 0.f, 0.f, 1.f}
	};

	ft_mat4mult(mat, shear_mat);
}

void			ft_mat4shear(t_mat4 *mat, t_vec3 shear)
{
	ft_mat4shear_x(mat, shear.x);
	ft_mat4shear_y(mat, shear.y);
	ft_mat4shear_z(mat, shear.z);
}

void			ft_mat4shear_inv(t_mat4 *mat, t_vec3 shear)
{
	ft_mat4shear_z(mat, 0.f - shear.z);
	ft_mat4shear_y(mat, 0.f - shear.y);
	ft_mat4shear_x(mat, 0.f - shear.x);
}
