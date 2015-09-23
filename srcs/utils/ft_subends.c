/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subends.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 17:05:20 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/23 17:08:42 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_bool			ft_subends(t_sub sub, t_sub with)
{
	if (sub.length >= with.length
		&& ft_memcmp(sub.str + sub.length - with.length,
			with.str, with.length) == 0)
		return (true);
	return (false);
}
