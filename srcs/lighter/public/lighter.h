/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighter.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:10:40 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/29 19:56:00 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTER_H
# define LIGHTER_H

# include "ft/ft_list.h"
# include "ft/math_vec3.h"

# include "gbuffer.h"
# include "obj.h"
# include "shader.h"

typedef struct s_lighter				t_lighter;
typedef struct s_point_light_component	t_point_light_component;
typedef struct s_spot_light_component	t_spot_light_component;
typedef t_vec3							t_point_light_param;
typedef struct s_spot_light_param		t_spot_light_param;

/*
** ========================================================================== **
** Lighter
*/

/*
** Lighter object
*/
struct			s_lighter
{
	t_list			point_lights;
	t_list			spot_lights;
	t_shader		render_shader;
	t_uniform_loc	u_point_lights;
	t_uniform_loc	u_point_light_count;
	t_uniform_loc	u_spot_lights;
	t_uniform_loc	u_spot_light_count;
};

bool			lighter_init(t_lighter *dst);

/*
** Render to 'gbuffer'
*/
void			render_lights(t_lighter const *lighter, t_gbuffer *gbuffer);

/*
** Point light (component)
** (list item)
*/
struct			s_point_light_component
{
	t_obj_component	c;
	t_vec3			pos;
	t_vec3			intensity;
};

t_point_light_component	*create_point_light_component(
							t_point_light_param const *param,
							t_lighter *lighter);

/*
** Spot light
** (list item)
*/
struct			s_spot_light_component
{
	t_obj_component	c;
	t_vec3			pos;
	t_vec3			dir;
	t_vec3			intensity;
	t_vec2			cutoff;
};

struct			s_spot_light_param
{
	t_vec3			intensity;
	float			cutoff;
	float			cutoff_border;
};

t_spot_light_component	*create_spot_light_component(
							t_spot_light_param const *param,
							t_lighter *lighter);

#endif
