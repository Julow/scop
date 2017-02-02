/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighter.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:10:40 by jaguillo          #+#    #+#             */
/*   Updated: 2017/02/02 17:14:33 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTER_H
# define LIGHTER_H

# include "ft/ft_list.h"
# include "ft/math_mat4.h"
# include "ft/math_vec3.h"

# include "gbuffer.h"
# include "obj.h"
# include "shader.h"

typedef struct s_lighter				t_lighter;
typedef struct s_point_light_component	t_point_light_component;
typedef struct s_point_light_data		t_point_light_data;
typedef struct s_spot_light_component	t_spot_light_component;
typedef t_vec3							t_point_light_param;
typedef struct s_spot_light_param		t_spot_light_param;

/*
** ========================================================================== **
** Lighter
*/

/*
** Lighter object
** point_lights		=> list of point_light_component
** point_shader		=> point light renderer
** point_vao		=> input to point_shader
** point_vbo		=> point light buffer (:vec3 strides=2; pos, intensity)
** viewproj_m		=> World to screen space matrix
*/
struct			s_lighter
{
	t_list			point_lights;
	t_shader		point_shader;
	GLuint			point_vao;
	GLuint			point_vbo;
	uint32_t		point_circle_length; // TODO: constant
	t_uniform_loc	point_u_view_m;
	t_uniform_loc	point_u_proj_m;
	t_mat4			view_m;
	t_mat4			proj_m;
	uint32_t		flags;
};

# define LIGHTER_F_POINT_VBO_INVALID	(1 << 0)

bool			lighter_init(t_lighter *dst);

/*
** Render to 'gbuffer'
*/
void			render_lights(t_lighter *lighter, t_gbuffer *gbuffer);

/*
** Point light (component)
** (list item)
** -
** index			=> Index in point_vbo
*/
struct			s_point_light_data
{
	t_vec3			pos;
	t_vec3			intensity;
};

struct			s_point_light_component
{
	t_obj_component		c;
	t_lighter			*l;
	uint32_t			index;
	t_point_light_data	data;
};

t_point_light_component	*create_point_light_component(
							t_point_light_param const *param,
							t_lighter *lighter);

// /*
// ** Spot light
// ** (list item)
// ** TODO: reimplement spot lights
// */
// struct			s_spot_light_component
// {
// 	t_obj_component	c;
// 	t_vec3			pos;
// 	t_vec3			dir;
// 	t_vec3			intensity;
// 	t_vec2			cutoff;
// };

// struct			s_spot_light_param
// {
// 	t_vec3			intensity;
// 	float			cutoff;
// 	float			cutoff_border;
// };

// t_spot_light_component	*create_spot_light_component(
// 							t_spot_light_param const *param,
// 							t_lighter *lighter);

#endif
