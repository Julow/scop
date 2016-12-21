/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_scene_loader.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:59:09 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/21 15:08:23 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_SCENE_LOADER_H
# define P_SCENE_LOADER_H

# include "ft/json.h"
# include "ft/json_t.h"

# include "scene_loader.h"

typedef struct s_scene_component	t_scene_component;

/*
** ========================================================================== **
*/

struct		s_scene_component
{
	t_sub						name;
	t_obj_component_class const	*c;
	t_json_t_value				val;
};

/*
** Parse an object component
*/
extern t_json_t_value const	g_scene_pod_component_json;

#endif
