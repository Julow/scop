/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_scene_loader.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:59:09 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/11 17:55:08 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_SCENE_LOADER_H
# define P_SCENE_LOADER_H

# include "ft/json.h"
# include "ft/json_t.h"
# include "ft/libft.h"

# include "p_scene_pod.h"
# include "scene_loader.h"

/*
** ========================================================================== **
*/

void			load_scene_objs(t_vector const *pods, t_vector *dst);

bool			scene_pod_parse_component(t_json_parser *p,
					t_scene_pod_component *dst, t_vector const *components);

void			scene_pod_free_component(t_scene_pod_component *data,
					t_vector const *components);

#endif
