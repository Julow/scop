/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_loader.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:54:41 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/28 20:07:00 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_LOADER_H
# define SCENE_LOADER_H

# include "ft/ft_in.h"
# include "ft/json_t.h"
# include "ft/libft.h"

# include "scene.h"

typedef struct s_scene_component	t_scene_component;

/*
** ========================================================================== **
** Scene loader
*/

struct		s_scene_component
{
	t_sub					name;
	t_obj_component			*(*create)(void const *data, void *param);
	void					*create_param;
	t_json_t_value const	*val;
};

/*
** Load a scene from a json file
** Return true on success, false on error
*/
bool		load_scene(t_in *in, t_scene *dst, t_vector const *components);

#endif
