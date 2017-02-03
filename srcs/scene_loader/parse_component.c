/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_component.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:00:13 by jaguillo          #+#    #+#             */
/*   Updated: 2017/02/03 13:51:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_scene_loader.h"

#include <stddef.h>
#include <stdlib.h>

/*
** TODO: improve
*/
static t_scene_component const*
				get_component(t_vector const *components, t_sub name)
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

bool			scene_pod_parse_component(t_json_parser *p,
					t_scene_pod_component *dst, t_vector const *components)
{
	t_scene_component const	*c;

	if (p->token != JSON_BEGIN_LIST)
		return (ft_json_fail(p, SUBC("Expecting list")));
	if (!ft_json_except_value(p, JSON_VALUE_STRING))
		return (false);
	if ((c = get_component(components, JSON_VAL_STRING(p))) == NULL)
		return (ft_json_fail(p, SUBC("Unknown component")));
	dst->c = c;
	dst->param = MALLOC(ft_json_t_sizeof(c->val));
	if (ft_json_next(p))
	{
		if (ft_json_t_next(p, c->val, dst->param))
		{
			if (ft_json_except(p, JSON_END))
				return (true);
		}
		ft_json_t_free(c->val, dst->param);
	}
	free(dst->param);
	return (false);
}

void			scene_pod_free_component(t_scene_pod_component *data,
					t_vector const *components)
{
	ft_json_t_free(data->c->val, data->param);
	free(data->param);
	(void)components;
}
