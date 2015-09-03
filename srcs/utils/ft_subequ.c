/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 19:05:03 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/03 19:05:44 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_bool			ft_subequ(t_sub a, t_sub b)
{
	if (a.length == b.length && ft_memcpy(a.str, b.str, a.length) == 0)
		return (true);
	return (false);
}