/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:49:04 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/12 15:49:27 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool			ft_read_line(t_in *in, t_dstr *dst)
{
	dst->length = 0;
	if (!ft_readto_char(in, '\n', dst))
		return (dst->length > 0);
	in->buff_i++;
	return (true);
}
