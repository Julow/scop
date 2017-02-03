/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_scene_pod.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:55:08 by jaguillo          #+#    #+#             */
/*   Updated: 2017/02/03 13:49:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_SCENE_POD_H
# define P_SCENE_POD_H

# include "ft/ft_vector.h"
# include "ft/libft.h"
# include "ft/math_vec3.h"

# include "scene_loader.h"

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

struct		s_scene_pod_component
{
	t_scene_component const	*c;
	void					*param;
};

struct		s_scene_pod
{
	t_vector			objects;
};

#endif
