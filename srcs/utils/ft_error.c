/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 18:03:21 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/07 16:39:43 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_out.h"

int				ft_error(int ret, char const *str)
{
	int				old_fd;

	old_fd = FTOUT->fd;
	ft_out(2);
	PS("Error: ");
	PS(str);
	PC('\n');
	ft_out(old_fd);
	return (ret);
}
