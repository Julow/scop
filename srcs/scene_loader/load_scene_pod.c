/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_scene_pod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:01:57 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/22 15:57:36 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "p_scene_loader.h"

#include <stddef.h>
#include <stdlib.h>

static t_json_t_value const	g_vec2_json = JSON_T_FIXED_LIST(t_vec2,
	(x, JSON_T_VALUE(FLOAT)),
	(y, JSON_T_VALUE(FLOAT))
);

static t_json_t_value const	g_vec3_json = JSON_T_FIXED_LIST(t_vec3,
	(x, JSON_T_VALUE(FLOAT)),
	(y, JSON_T_VALUE(FLOAT)),
	(z, JSON_T_VALUE(FLOAT))
);

static t_json_t_value const	g_camera_json = JSON_T_DICT(t_scene_pod_camera,
	("pos", pos, g_vec3_json),
	("dir", dir, g_vec2_json),
	("fov", fov, JSON_T_VALUE(FLOAT)),
	("near", near, JSON_T_VALUE(FLOAT)),
	("far", far, JSON_T_VALUE(FLOAT))
);

static t_json_t_value const	g_object_json = JSON_T_DICT(t_scene_pod_object,
	("position", pos, g_vec3_json),
	("rotation", rot, g_vec3_json),
	("shear", shear, g_vec3_json),
	("scale", scale, g_vec3_json),
	("mesh", mesh, JSON_T_VALUE(STRING)),
	("components", components, JSON_T_LIST(g_scene_pod_component_json)),
	("childs", childs, JSON_T_LIST(g_object_json))
);

static t_json_t_value const	g_scene_json = JSON_T_DICT(t_scene_pod,
	("objects", objects, JSON_T_LIST(g_object_json)),
	("camera", camera, g_camera_json)
);

bool		load_scene_pod(t_in *in, t_scene_pod *dst)
{
	t_dstr		err;

	err = DSTR0();
	if (!ft_json_parse(in, &g_scene_json, dst, &err))
	{
		ft_printf("Error: %ts%n", DSTR_SUB(err));
		return (false);
	}
	return (true);
}
