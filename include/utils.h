/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 12:07:13 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/26 02:13:43 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"

# define MEM_EQU(a,b,s)		(ft_memcmp((a), (b), (s)) == 0)

# define G_ARRAY_LEN(g)		((int)(sizeof(g) / sizeof(*(g))))

/*
** Parse an int
*/
int				ft_subint(t_sub sub, int *dst);

/*
** Hash
*/
int				ft_djb2(t_sub sub);

#endif
