/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 12:49:02 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/23 18:42:29 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include "libft.h"

/*
** TODO:
** mesh_loader options (as string)
** scene loading from file
** renderer
*/

# define WIN_RATIO			(1.f)
# define WIN_HEIGHT			900
# define WIN_WIDTH			((int)(WIN_HEIGHT * WIN_RATIO))

typedef struct s_scop		t_scop;

typedef struct s_obj		t_obj;
typedef void				(*t_renderer)(t_scop*, t_obj*);

typedef struct s_mtl		t_mtl;

typedef struct s_texture	t_texture;

typedef struct s_mesh		t_mesh;
typedef struct s_mesh_mtl	t_mesh_mtl;

typedef struct s_vec2		t_vec2;
typedef struct s_vec3		t_vec3;
typedef struct s_vec4		t_vec4;
typedef struct s_mat4		t_mat4;

typedef struct s_transform	t_transform;
typedef struct s_camera		t_camera;

typedef struct s_shader		t_shader;
typedef struct s_uniform	t_uniform;

typedef struct s_key_event	t_key_event;

#endif
