/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:44:23 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/28 18:15:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "ft/libft.h"
# include "ft/math_mat4.h"
# include "ft/math_vec2.h"
# include "ft/math_vec3.h"

# include "obj.h"

typedef struct s_camera			t_camera;
typedef struct s_camera_list	t_camera_list;
typedef struct s_camera_param	t_camera_param;

/*
** ========================================================================== **
*/

/*
** Camera (component)
** (list item)
*/
struct		s_camera
{
	t_obj_component	c;
	t_mat4			proj_m;
	t_mat4			viewproj_m;
	t_vec2			clip;
	float			fov;
};

/*
** Camera list
** -
** cameras		=> List of the cameras in the scene
** current		=> Current camera (default NULL)
** win_ratio	=> Ratio window height/width
*/
struct		s_camera_list
{
	t_list			cameras;
	t_camera		*current;
	float			win_ratio;
};

# define CAMERA_LIST(RATIO)		((t_camera_list){LIST(t_camera), NULL, (RATIO)})

/*
** Set the current camera
*/
void		camera_current(t_camera_list *lst, t_camera *camera);

/*
** Create camera component
*/
struct		s_camera_param
{
	float			fov;
	float			near;
	float			far;
};

t_camera	*create_camera(t_camera_param const *param,
				t_camera_list *camera_list);

#endif
