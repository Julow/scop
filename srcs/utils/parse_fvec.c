/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fvec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 18:38:33 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/16 15:25:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "utils.h"

bool			parse_fvec(t_sub line, float *vec, int len)
{
	int				i;
	t_sub			word;

	word = SUB_START(line);
	i = -1;
	while (++i < len && ft_subnext_is(line, &word, IS_WHITESPACE))
		if (ft_subto_float(word, vec + i) == 0)
		{
			ft_printf("Invalid float: %ts\n", word);
			return (false);
		}
	return (true);
}
