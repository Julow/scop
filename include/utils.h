/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 12:07:13 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/22 08:23:49 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"

# define MEM_EQU(a,b,s)		(ft_memcmp((a), (b), (s)) == 0)

/*
** Call ft_memcpy and increment 'd'
*/
# define MEM_WRITE(d,s,t,n)	((d) = ft_memcpy(d, s, S(t, n)) + S(t, n))

/*
** Ignore parse error
*/
# define IGNORE_ERROR		true

/*
** Parse a float vector (separated by space)
*/
t_bool			parse_fvec(t_sub line, float *vec, int len);

/*
** Remove 'n' node after 'node'
** remove all nodes until the end if 'n' is negative
*/
void			ft_listremove_next(t_list *lst, void *node, int n);

/*
** Return true if 'sub' starts with 'start'
** false otherwise
*/
t_bool			ft_substart(t_sub sub, t_sub start);

/*
** Print an error
** Return ret
*/
int				ft_error(int ret, char const *format, ...);

/*
** Fps monitor
** -
** Compute average time between call to fps_start and fps_end
** Compute average frame per sec
** elapsed is the time since the last frame
*/

typedef struct	s_fps
{
	t_ulong			last_update;
	t_ulong			last_frame;
	t_ulong			frame_start;
	t_ulong			frames_time;
	t_uint			update_interval;
	t_uint			frames;
	t_uint			elapsed;
	t_uint			average_time;
	t_uint			average_fps;
}				t_fps;

t_fps			fps_init(t_uint update_interval);
void			fps_start(t_fps *fps);
t_bool			fps_end(t_fps *fps);

#endif
