/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 12:49:02 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/21 23:13:52 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include "libft.h"
# include "ft_list.h"
# include "ft_hmap.h"
# include "gl.h"
# include "camera.h"
# include "shader_loader.h"
# include "mesh_loader.h"
# include "texture_loader.h"

# define WIN_RATIO			(1.f)
# define WIN_HEIGHT			900
# define WIN_WIDTH			((int)(WIN_HEIGHT * WIN_RATIO))

# define WIN_TITLE			"Scop"

# define PERSPECTIVE_FOV	42.f
# define PERSPECTIVE_NEAR	0.01f
# define PERSPECTIVE_FAR	10000.f

# define MOVE_SPEED			0.00002f
# define CURSOR_SPEED		3.f
# define ACCELERATION		10.f

# define F_OBJ_UPDATED		(1 << 1)

typedef struct	s_obj
{
	t_mesh const	*mesh;
	t_texture const	*texture;
	t_shader const	*shader;
	t_mat4			model_m[2];
	t_vec3			position;
	t_vec3			rotation;
	float			scale;
	int				flags;
}				t_obj;

# define OBJ(m,t,s)			((t_obj){(m), (t), (s), 0, 0, 0, 0})

# define FLAG_MOVE_FRONT	(1 << 1)
# define FLAG_MOVE_LEFT		(1 << 2)
# define FLAG_MOVE_BACK		(1 << 3)
# define FLAG_MOVE_RIGHT	(1 << 4)
# define FLAG_ACCELERATE	(1 << 9)
# define FLAG_MOVE_DOWN		(1 << 10)
# define FLAG_MOVE_UP		(1 << 11)
# define FLAG_CURSOR_MOVE	(1 << 12)

typedef struct	s_scop
{
	GLFWwindow		*window;
	t_vector		objects;
	t_camera		camera;
	t_mat4			projection_m;
	int				flags;
}				t_scop;

// TODO
// typedef struct	s_simple_renderer
// {
// 	t_renderer		t;
// 	t_shader const	*shader;
// }				t_simple_renderer;

// typedef struct	s_shadow_renderer
// {
// 	t_renderer		t;
// 	t_shader const	*depth;
// 	t_shader const	*light;
// 	t_shader const	*render;
// }				t_shadow_renderer;
// -

/*
** init
*/
t_bool			init_window(t_scop *scop);

void			init_key_events(t_scop *scop);
void			init_mouse_events(t_scop *scop);

/*
** renderer
*/
void			simple_renderer(t_scop *scop, t_obj *obj);

/*
** update
*/
t_bool			handle_key_hold(t_scop *scop, float elapsed, t_vec3 *pos);
t_bool			handle_cursor_move(t_scop *scop, t_vec2 *look);

#endif
