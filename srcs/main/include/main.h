/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 08:10:19 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/04 23:51:27 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

typedef struct s_scop		t_scop;

# include "ft_vector.h"
# include "gl.h"
# include "renderer.h"
# include "obj.h"
# include "camera.h"

# define WIN_RATIO			(1.f)
# define WIN_HEIGHT			900
# define WIN_WIDTH			((int)(WIN_HEIGHT * WIN_RATIO))

# define FLAG_MOVE_FRONT	(1 << 1)
# define FLAG_MOVE_LEFT		(1 << 2)
# define FLAG_MOVE_BACK		(1 << 3)
# define FLAG_MOVE_RIGHT	(1 << 4)
# define FLAG_ACCELERATE	(1 << 9)
# define FLAG_MOVE_DOWN		(1 << 10)
# define FLAG_MOVE_UP		(1 << 11)
# define FLAG_CURSOR_MOVE	(1 << 12)

# define WIN_TITLE			"Scop"

# define PERSPECTIVE_FOV	42.f
# define PERSPECTIVE_NEAR	0.01f
# define PERSPECTIVE_FAR	10000.f

# define MOVE_SPEED			0.00002f
# define CURSOR_SPEED		3.f
# define ACCELERATION		10.f

struct			s_scop
{
	GLFWwindow		*window;
	t_vector		objects;
	t_camera		camera;
	t_mat4			projection_m;
	int				flags;
};

/*
** init
*/
t_bool			init_window(t_scop *scop);

/*
** update
*/
t_bool			handle_key_hold(t_scop *scop, float elapsed, t_vec3 *pos);
t_bool			handle_cursor_move(t_scop *scop, t_vec2 *look);

/*
** callbacks
*/
void			on_mouse_move(t_scop *scop, double x, double y);
void			on_esc(t_scop *scop, int key_code);

/*
** motions
** TODO: maybe a 'motions' module
*/
void			move_front(t_vec2 dir, t_vec3 *move, float inv);
void			move_lateral(t_vec2 dir, t_vec3 *move, float inv);
void			move_vertical(t_vec2 dir, t_vec3 *move, float inv);

t_bool			handle_key_hold(t_scop *scop, float elapsed, t_vec3 *pos);
t_bool			handle_cursor_move(t_scop *scop, t_vec2 *look);

#endif
