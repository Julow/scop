/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:20:22 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/11 13:36:52 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "ft/libft.h"
# include "ft/math_mat4.h"

# include "camera.h"
# include "obj.h"

typedef struct s_scene			t_scene;

/*
** ========================================================================== **
** Scene
*/

struct			s_scene
{
	t_vector		objects;
	t_camera		camera;
	t_mat4			projection_m;
};

#endif
