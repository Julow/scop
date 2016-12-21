/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_component.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:00:13 by jaguillo          #+#    #+#             */
/*   Updated: 2016/12/21 17:26:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_scene_loader.h"

#include <stddef.h>
#include <stdlib.h>

/*
** ========================================================================== **
** dummy_component // TODO: remove
*/

typedef struct s_dummy_component_param	t_dummy_component_param;

struct		s_dummy_component_param
{
	float		intensity;
};

t_obj_component	*dummy_component_create(t_dummy_component_param const *param)
{
	return (NULL);
	(void)param;
}

t_obj_component_class const	g_dummy_component_class = {
	V(&dummy_component_create)
};

/*
** ========================================================================== **
*/

static t_scene_component const	scene_components[] = {
	{ SUBC("dummy"), &g_dummy_component_class, JSON_T_DICT(t_dummy_component_param,
		("lol", intensity, JSON_T_VALUE(FLOAT))
	) },
};

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
