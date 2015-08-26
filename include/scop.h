/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 12:49:02 by jaguillo          #+#    #+#             */
/*   Updated: 2015/08/26 23:18:33 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include "libft.h"
# include "ft_list.h"
# include "ft_hmap.h"
# include "gl.h"
# include "shader_loader.h"
# include "mesh_loader.h"
# include "texture_loader.h"

# define WIN_RATIO			1.f
# define WIN_HEIGHT			800
# define WIN_WIDTH			((int)(WIN_HEIGHT * WIN_RATIO))

# define WIN_TITLE			"Scop"

# define PERSPECTIVE_FOV	42.f
# define PERSPECTIVE_NEAR	0.01f
# define PERSPECTIVE_FAR	1000.f

# define F_OBJ_UPDATED		(1 << 1)

typedef struct	s_obj
{
	t_mesh const	*mesh;
	t_texture const	*texture;
	t_shader const	*shader;
	t_mat4			_model_m;
	t_vec3			position;
	t_vec3			rotation;
	float			scale;
	int				flags;
}				t_obj;

# define OBJ(m,t,s)			((t_obj){(m), (t), (s), 0, 0, 0, 0})

# define F_CAMERA_UPDATED	(1 << 1)

typedef struct	s_camera
{
	t_mat4			_view_m;
	t_vec3			position;
	t_vec3			look_at;
	int				flags;
}				t_camera;

# define CAMERA(p,l)		((t_camera){MAT4_ZERO(), VEC3 p, VEC3 l, (1 << 1)})

typedef struct	s_scop
{
	GLFWwindow		*window;
	t_vector		objects;
	t_camera		camera;
	t_mat4			projection_m;
}				t_scop;

t_bool			init_window(t_scop *scop);

void			init_key_events(t_scop *scop);

#endif
