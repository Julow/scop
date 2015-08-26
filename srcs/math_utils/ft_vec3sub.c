/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 15:12:42 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/26 15:17:40 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_utils.h"

t_vec3			ft_vec3sub(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){
		a.x - b.x,
		a.y - b.y,
		a.z - b.z
	});
}
