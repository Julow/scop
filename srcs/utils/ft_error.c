/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 18:03:21 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/15 21:23:46 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_out.h"
#include "ft_colors.h"
#include "ft_printf.h"
#include "ft_vprintf.h"

int				ft_error(int ret, char const *format, ...)
{
	int				old_fd;
	va_list			ap;

	old_fd = g_ftout.fd;
	ft_out(2);
	ft_putsub(FTOUT, SUBC(C_RED "Error:" C_RESET " "));
	va_start(ap, format);
	ft_putf(FTOUT, format, &ap);
	va_end(ap);
	ft_putendl(FTOUT);
	ft_out(old_fd);
	return (ret);
}
