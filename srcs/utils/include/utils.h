/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 12:07:13 by jaguillo          #+#    #+#             */
/*   Updated: 2015/12/10 19:45:00 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "ft/libft.h"
# include "ft/ft_list.h"

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
bool			parse_fvec(t_sub line, float *vec, int len);

/*
** Remove 'n' node after 'node'
** remove all nodes until the end if 'n' is negative
*/
void			ft_listremove_next(t_list *lst, void *node, int n);

/*
** sub utils
*/
bool			ft_substart(t_sub sub, t_sub start);
bool			ft_subends(t_sub sub, t_sub with);

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
	uint64_t			last_update;
	uint64_t			last_frame;
	uint64_t			frame_start;
	uint64_t			frames_time;
	uint32_t			update_interval;
	uint32_t			frames;
	uint32_t			elapsed;
	uint32_t			average_time;
	uint32_t			average_fps;
}				t_fps;

t_fps			fps_init(uint32_t update_interval);
void			fps_start(t_fps *fps);
bool			fps_end(t_fps *fps);

#endif
