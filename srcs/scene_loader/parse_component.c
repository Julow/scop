/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_component.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:00:13 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/22 17:02:08 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_scene_loader.h"

#include <stddef.h>
#include <stdlib.h>

static t_json_t_value const	g_vec3_json = JSON_T_FIXED_LIST(t_vec3,
	(x, JSON_T_VALUE(FLOAT)),
	(y, JSON_T_VALUE(FLOAT)),
	(z, JSON_T_VALUE(FLOAT))
);

/*
** ========================================================================== **
** TODO: move
*/

#include "anim_component.h"

static t_json_t_value const		g_anim_component_type_json = JSON_T_ENUM(t_obj_anim_t,
	("translate", OBJ_ANIM_TRANSLATE),
	("rotate", OBJ_ANIM_ROTATE),
	("shear", OBJ_ANIM_SHEAR),
	("scale", OBJ_ANIM_SCALE)
);

static t_json_t_value const		g_anim_smooth_json = JSON_T_ENUM(float (*)(float),
	("linear", &smooth_linear),
	("in", &smooth_in),
	("out", &smooth_out),
	("in_out", &smooth_in_out),
	("elastic", &smooth_elastic),
	("bounce", &smooth_bounce),
	("back_in", &smooth_back_in),
	("back_out", &smooth_back_out),
	("back_in_out", &smooth_back_in_out)
);

static t_json_t_value const		g_anim_flags_json = JSON_T_ENUM(uint32_t,
	("none", 0),
	("restart", F_ANIM_RESTART),
	("repeat", F_ANIM_REPEAT),
	("reverse", F_ANIM_REVERSE)
);

static t_scene_component const	scene_components[] = {
	{ SUBC("anim"), &g_anim_component_class, JSON_T_DICT(t_anim_component_param,
		("from", from, g_vec3_json),
		("to", to, g_vec3_json),
		("duration", duration, JSON_T_VALUE(FLOAT)),
		("type", type, g_anim_component_type_json),
		("smooth", smooth, g_anim_smooth_json),
		("repeat", flags, g_anim_flags_json)
	) },
};

/*
** ========================================================================== **
*/

static t_scene_component const	*get_component(t_vector const *components, t_sub name) // TODO: improve
{
	t_scene_component const	*c;

	c = VECTOR_IT(*components);
	while (VECTOR_NEXT(*components, c))
	{
		if (SUB_EQU(c->name, name))
			return (c);
	}
	return (NULL);
}

static bool			scene_pod_parse_component(t_json_parser *p,
						t_scene_pod_component *dst, t_vector const *components)
{
	t_scene_component const	*c;

	if (p->token != JSON_BEGIN_LIST)
		return (ft_json_fail(p, SUBC("Expecting list")));
	if (!ft_json_except_value(p, JSON_VALUE_STRING))
		return (false);
	if ((c = get_component(components, JSON_VAL_STRING(p))) == NULL)
		return (ft_json_fail(p, SUBC("Unknown component")));
	dst->name = c->name;
	dst->c = c->c;
	dst->param = MALLOC(ft_json_t_sizeof(&c->val));
	if (!ft_json_next(p)
		|| !ft_json_t_next(p, &c->val, dst->param)
		|| !ft_json_except(p, JSON_END))
	{
		free(dst->param);
		return (false);
	}
	return (true);
}

static void			scene_pod_free_component(t_scene_pod_component *data,
						t_vector const *components)
{
	t_scene_component const *const	c = get_component(components, data->name);

	HARD_ASSERT(c != NULL);
	ft_json_t_free(&c->val, data->param);
	free(data->param);
}

t_json_t_value const	g_scene_pod_component_json = JSON_T_CALLBACK(
	V(scene_pod_parse_component),
	V(scene_pod_free_component),
	&VECTORC(scene_components),
	sizeof(t_scene_pod_component)
);
