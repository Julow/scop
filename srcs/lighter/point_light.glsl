/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_light.glsl                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:27:26 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/21 18:36:17 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#version 410 core

//#shader vert

layout (location = 0) in vec3	_vert_pos;
layout (location = 1) in vec2	_vert_tex;

out vec2			_frag_tex;

void		main()
{
	_frag_tex = _vert_tex;
	gl_Position = vec4(_vert_pos, 1.f);
}

//#shader frag

in vec2				_frag_tex;

out vec3			_buff_light;

// Light pos, light intensity, ...
uniform vec3		_u_point_lights[64];
// Size of _u_point_lights
uniform uint		_u_point_light_count;

uniform sampler2D	_u_light_back;

uniform sampler2D	_u_pos;
uniform sampler2D	_u_nor;
uniform sampler2D	_u_col;

void		main()
{
	// TODO: uniform:
		vec3		view_pos = vec3(0.f);
		uint		shininess = 32;

	vec3		frag_pos = texture(_u_pos, _frag_tex).xyz;
	vec3		frag_nor = texture(_u_nor, _frag_tex).xyz;
	float		frag_specular = texture(_u_col, _frag_tex).a;

	uint		i;
	vec3		light;

	if (length(frag_nor) < 0.9f)
		discard ;

	// light = texture(_u_light_back, _frag_tex).xyz;
	light = vec3(0.f);
	i = 0;
	while (i < _u_point_light_count)
	{
		vec3		light_pos = _u_point_lights[i++];
		vec3		light_color = _u_point_lights[i++];

		vec3		light_diff = light_pos - frag_pos;
		float		light_dist = length(light_diff);
		vec3		light_dir = light_diff / light_dist;

		// Difusse
		float		diff = max(dot(frag_nor, light_dir), 0.f);

		// Specular
		vec3		view_dir = normalize(view_pos - frag_pos);
		vec3		halfway_dir = normalize(light_dir + view_dir);
		float		spec = pow(max(dot(frag_nor, halfway_dir), 0.f), shininess) * frag_specular;

		light += (spec + diff) * light_color / (light_dist * light_dist);
	}

	_buff_light = light;
}
