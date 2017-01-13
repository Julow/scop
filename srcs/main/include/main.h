/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 08:10:19 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/12 18:04:00 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "ft/ft_vector.h"
# include "ft/gl.h"

# include "camera.h"
# include "mesh_renderer.h"
# include "obj.h"
# include "scene.h"

typedef struct s_scop_fbo	t_scop_fbo;
typedef struct s_scop		t_scop;

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

# define MOVE_SPEED			0.00002f
# define CURSOR_SPEED		3.f
# define ACCELERATION		10.f

struct			s_scop_fbo
{
	GLuint			fbo;
	GLuint			buff_pos;
	GLuint			buff_nor;
	GLuint			buff_col;
};

struct			s_scop
{
	GLFWwindow		*window;
	t_scene			scene;
	t_vec2			cursor;
	int				flags;
	t_scop_fbo		fbo;
	t_mesh_renderer	mesh_renderer;
};

/*
** init
*/
bool			init_window(t_scop *scop);

/*
** update
*/
bool			handle_key_hold(t_scop *scop, float elapsed, t_vec3 *pos);
bool			handle_cursor_move(t_scop *scop, t_vec2 *look);

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

bool			handle_key_hold(t_scop *scop, float elapsed, t_vec3 *pos);
bool			handle_cursor_move(t_scop *scop, t_vec2 *look);

#endif
