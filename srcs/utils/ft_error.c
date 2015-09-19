/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 18:03:21 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/19 19:06:44 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_internal.h"

int				ft_error(int ret, char const *format, ...)
{
	t_printf		pf;
	va_list			ap;
	int				old_fd;

	old_fd = FTOUT->fd;
	ft_out(2);
	PS("Error: ");
	va_start(ap, format);
	pf = (t_printf){FTOUT, 0, &ap};
	writef(&pf, format);
	va_end(ap);
	PC('\n');
	ft_flush(pf.out);
	ft_out(old_fd);
	return (ret);
}
