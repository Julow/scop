/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_loader.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:54:41 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/11 13:41:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_LOADER_H
# define SCENE_LOADER_H

# include "ft/ft_in.h"
# include "ft/json_t.h"
# include "ft/libft.h"

# include "mesh_renderer.h" // TODO: remove
# include "obj_component_class.h"
# include "scene.h"

typedef struct s_scene_component	t_scene_component;

/*
** ========================================================================== **
** Scene loader
*/

struct		s_scene_component
{
	t_sub						name;
	t_obj_component_class const	*c;
	t_json_t_value const		*val;
};

/*
** Load a scene from a json file
** Return true on success, false on error
*/
bool		load_scene(t_in *in, t_scene *dst,
				t_vector const *components,
				t_mesh_render *mesh_render, // TODO: remove
				float win_ratio);

#endif
