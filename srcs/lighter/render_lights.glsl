/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_lights.glsl                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:27:26 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/30 17:13:59 by jaguillo         ###   ########.fr       */
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

// Point lights (strides=2; pos, intensity)
uniform vec3		_u_point_lights[64];
uniform uint		_u_point_light_size;

// Spot lights (strides=4; pos, dir, intensity, {cutoff, border, _})
uniform vec3		_u_spot_lights[64];
uniform uint		_u_spot_light_size;

uniform sampler2D	_u_light_back;

uniform sampler2D	_u_pos;
uniform sampler2D	_u_nor;
uniform sampler2D	_u_col;

vec3				frag_pos;
vec3				frag_nor;
float				frag_specular;
vec3				frag_view_dir;

uint				shininess = 32; // TODO: uniform
vec3				view_pos = vec3(0.f); // TODO: uniform

#define ATT_A			1.f
#define ATT_B			0.7f
#define ATT_C			1.8f

float		blinn_phong(vec3 pos)
{
	float			dist = length(pos - frag_pos);
	vec3			dir = (pos - frag_pos) / dist;

	float			diffuse = max(dot(frag_nor, dir), 0.f);

	vec3			halfway_dir = normalize(dir + frag_view_dir);
	float			specular = pow(max(dot(frag_nor, halfway_dir), 0.f), shininess) * frag_specular;

	return ((diffuse + specular) / (dist * dist));
}

void		main()
{
	frag_pos = texture(_u_pos, _frag_tex).xyz;
	frag_nor = texture(_u_nor, _frag_tex).xyz;
	frag_specular = texture(_u_col, _frag_tex).a;
	frag_view_dir = normalize(view_pos - frag_pos);

	uint		i;
	vec3		light_sum;

	if (length(frag_nor) < 0.9f)
		discard ;

	light_sum = texture(_u_light_back, _frag_tex).xyz;
	i = 0;
	while (i < _u_point_light_size)
	{
		vec3		point_pos = _u_point_lights[i++];
		vec3		point_color = _u_point_lights[i++];

		light_sum += blinn_phong(point_pos) * point_color;
	}

	i = 0;
	while (i < _u_spot_light_size)
	{
		vec3		spot_pos = _u_spot_lights[i++];
		vec3		spot_dir = _u_spot_lights[i++];
		vec3		spot_color = _u_spot_lights[i++];
		vec2		spot_cutoff = _u_spot_lights[i++].xy;

		vec3		dir = normalize(spot_pos - frag_pos);

		float		theta = dot(dir, -spot_dir);
		float		epsilon = spot_cutoff.x - spot_cutoff.y;

		float		cut = clamp((theta - spot_cutoff.y) / epsilon, 0.f, 1.f);

		light_sum += (blinn_phong(spot_pos) * cut) * spot_color;
	}

	_buff_light = light_sum;
}
