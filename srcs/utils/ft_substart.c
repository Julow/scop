/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 15:26:03 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/17 15:26:08 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_bool			ft_substart(t_sub sub, t_sub start)
{
	if (sub.length < start.length)
		return (false);
	if (ft_memcmp(sub.str, start.str, start.length) == 0)
		return (true);
	return (false);
}
