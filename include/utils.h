/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 12:07:13 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/06 02:51:39 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"

# define MEM_EQU(a,b,s)                (ft_memcmp((a), (b), (s)) == 0)

/*
** Ignore parse error
*/
# define IGNORE_ERROR		true

/*
** Parse a float vector (separated by space)
*/
t_bool			parse_fvec(t_sub line, float *vec, int len);

#endif
