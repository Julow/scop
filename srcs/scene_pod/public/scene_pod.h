/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_pod.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:55:08 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/21 14:59:49 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_POD_H
# define SCENE_POD_H

# include "ft/ft_vector.h"
# include "ft/libft.h"
# include "ft/math_vec3.h"

# include "obj_component_class.h"

typedef struct s_scene_pod_camera		t_scene_pod_camera;
typedef struct s_scene_pod_object		t_scene_pod_object;
typedef struct s_scene_pod_component	t_scene_pod_component;
typedef struct s_scene_pod				t_scene_pod;

struct		s_scene_pod_object
{
	t_vec3		pos;
	t_vec3		rot;
	t_vec3		shear;
	t_vec3		scale;
	t_vector	components;
	t_vector	childs;
};

struct		s_scene_pod_camera
{
	t_vec3		pos;
	t_vec3		dir;
	float		fov;
	float		near;
	float		far;
};

struct		s_scene_pod_component
{
	t_sub						name;
	t_obj_component_class const	*c;
	void						*param;
};

struct		s_scene_pod
{
	t_vector			objects;
	t_scene_pod_camera	camera;
};

#endif
