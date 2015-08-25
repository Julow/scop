/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 18:02:44 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/25 12:08:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int				ft_subint(t_sub sub, int *dst)
{
	int			tmp;
	int			i;

	tmp = 0;
	i = -1;
	while (++i < sub.length && IS(sub.str[i], IS_DIGIT))
		tmp = tmp * 10 + sub.str[i] - '0';
	*dst = tmp;
	return (i);
}
