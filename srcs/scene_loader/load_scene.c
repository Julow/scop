/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:21:48 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/23 19:32:18 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ft_printf.h"
#include "ft/math_vec2.h"
#include "ft/math_vec3.h"

#include "p_scene_loader.h"

static t_json_t_value const	g_vec2_json = JSON_T_TUPLE(t_vec2,
	(x, JSON_T_VALUE(FLOAT)),
	(y, JSON_T_VALUE(FLOAT))
);

static t_json_t_value const	g_vec3_json = JSON_T_TUPLE(t_vec3,
	(x, JSON_T_VALUE(FLOAT)),
	(y, JSON_T_VALUE(FLOAT)),
	(z, JSON_T_VALUE(FLOAT))
);

static t_json_t_value const	g_camera_json = JSON_T_DICT(t_scene_pod_camera,
	("pos", pos, g_vec3_json),
	("dir", dir, g_vec2_json),
	("fov", fov, JSON_T_VALUE(FLOAT)),
	("near", near, JSON_T_VALUE(FLOAT), &(float){0.01f}),
	("far", far, JSON_T_VALUE(FLOAT), &(float){10000.f})
);

static void		load_camera(t_scene_pod_camera const *pod, t_scene *dst,
					float win_ratio)
{
	dst->camera = CAMERA(pod->pos, pod->dir);
	dst->projection_m = ft_mat4perspective(pod->fov, win_ratio,
			pod->near, pod->far);
}

bool		load_scene(t_in *in, t_scene *dst,
				t_vector const *components, float win_ratio)
{
	t_json_t_value const	object_json = JSON_T_DICT(t_scene_pod_object,
		("pos", pos, g_vec3_json),
		("rot", rot, g_vec3_json, &VEC3_0()),
		("shear", shear, g_vec3_json, &VEC3_0()),
		("scale", scale, g_vec3_json, &VEC3_1(1.f)),
		("components", components, JSON_T_LIST(JSON_T_CALLBACK(
			V(scene_pod_parse_component),
			V(scene_pod_free_component),
			components,
			sizeof(t_scene_pod_component)
		)), &VECTOR(0)),
		("childs", childs, JSON_T_LIST(object_json), &VECTOR(0))
	);
	t_json_t_value const	scene_json = JSON_T_DICT(t_scene_pod,
		("objects", objects, JSON_T_LIST(object_json)),
		("camera", camera, g_camera_json)
	);

	t_dstr					err;
	t_scene_pod				scene_pod;

	err = DSTR0();
	if (!ft_json_parse(in, &scene_json, &scene_pod, &err))
	{
		ft_printf("Error: %ts%n", DSTR_SUB(err));
		ft_dstrclear(&err);
		return (false);
	}
	load_camera(&scene_pod.camera, dst, win_ratio);
	load_scene_objs(&scene_pod.objects, &dst->objects);
	ft_json_t_free(&scene_json, &scene_pod);
	return (true);
}
