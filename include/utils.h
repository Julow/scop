/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 12:07:13 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/25 17:08:21 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"

# define MEM_EQU(a,b,s)		(ft_memcmp((a), (b), (s)) == 0)

/*
** Parse an int
*/
int				ft_subint(t_sub sub, int *dst);

#endif
