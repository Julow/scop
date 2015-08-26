/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nanotime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 12:18:47 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/26 12:58:51 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#ifdef __APPLE__
# include <mach/mach_time.h>
# include <mach/mach.h>
#else
# include <time.h>
#endif
#ifdef __APPLE__

t_ulong			ft_clock_ns(t_ulong prev)
{
	static mach_timebase_info_data_t	timebase = {0, 0};

	if (timebase.denom == 0)
		mach_timebase_info(&timebase);
	return (mach_absolute_time() * timebase.numer / timebase.denom - prev);
}

#else

t_ulong			ft_clock_ns(t_ulong prev)
{
	struct timespec	spec;

	clock_gettime(CLOCK_MONOTONIC, &spec);
	return (spec.tv_sec * NANO_SEC + spec.tv_nsec - prev);
}

#endif
