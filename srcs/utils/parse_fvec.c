/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fvec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 18:38:33 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/07 16:44:58 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_printf.h"

t_bool			parse_fvec(t_sub line, float *vec, int len)
{
	int				i;

	line.length = 0;
	i = -1;
	while (++i < len && ft_subnext(&line, IS_SPACE))
		if (ft_subfloat(line, vec + i) == 0)
		{
			ft_printf("Invalid float: %.*s\n", line.length, line.str);
			return (false);
		}
	return (true);
}
