/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_point_light.glsl                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 11:57:51 by jaguillo          #+#    #+#             */
/*   Updated: 2017/02/02 17:18:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#version 410 core

//#shader vert

layout (location = 0) in vec3	_vert_pos;
layout (location = 1) in vec3	_point_pos;
layout (location = 2) in vec3	_point_color;

flat out vec3		_frag_point_pos;
flat out vec3		_frag_point_color;

uniform mat4		_u_view_m;
uniform mat4		_u_proj_m;

void		main()
{
	_frag_point_pos = _point_pos;
	_frag_point_color = _point_color;

	// 1 - exp(min_intensity * -exposure) = min_color
	// intensity / max_dist^2 = min_intensity
	// 	-> with min_color = 0.01
	// 		min_intensity = 0.0100503 / exposure
	// 		max_dist = 9.97494 * sqrt(exposure) * sqrt(intensity)
	// TODO: * sqrt(exposure)
	float			scale = 9.97494 * sqrt(max(_point_color.x,
								max(_point_color.y, _point_color.z)));

	gl_Position = _u_proj_m
		* (_u_view_m * vec4(_point_pos, 1.f) + vec4(_vert_pos * scale, 0.f));

	// TODO: check if behind camera
}

//#shader frag

flat in vec3		_frag_point_pos;
flat in vec3		_frag_point_color;

out vec3			_buff_light;

uniform sampler2D	_u_pos;
uniform sampler2D	_u_nor;
uniform sampler2D	_u_col;

vec3				frag_pos;
vec3				frag_nor;
float				frag_specular;
vec3				frag_view_dir;

uint				shininess = 32; // TODO: uniform
vec3				view_pos = vec3(0.f); // TODO: uniform

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
	vec2		tex = gl_FragCoord.xy / textureSize(_u_pos, 0);

	frag_pos = texture(_u_pos, tex).xyz;
	frag_nor = texture(_u_nor, tex).xyz;
	frag_specular = texture(_u_col, tex).a;
	frag_view_dir = normalize(view_pos - frag_pos);

	_buff_light = blinn_phong(_frag_point_pos) * _frag_point_color;
}
