/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blinn_phong_lightning.glsl                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:36:41 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/16 20:21:44 by jaguillo         ###   ########.fr       */
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

out vec4			_buff_col;

uniform sampler2D	_u_pos;
uniform sampler2D	_u_nor;
uniform sampler2D	_u_col;

void		main()
{
	// TODO: uniform:
		vec3		light_pos = vec3(0.f, 0.f, 0.f);
		vec3		light_color = vec3(1.f, 1.f, 1.f);
		vec3		view_pos = vec3(0.f);
		int			shininess = 32;

	vec3		frag_pos = texture(_u_pos, _frag_tex).xyz;
	vec3		frag_nor = texture(_u_nor, _frag_tex).xyz;
	float		frag_specular = texture(_u_col, _frag_tex).a;

	vec3		light_diff = light_pos - frag_pos;
	float		light_dist = length(light_diff);
	vec3		light_dir = light_diff / light_dist;

	// Difusse
	float		diff = max(dot(frag_nor, light_dir), 0.f);

	// Specular
	vec3		view_dir = normalize(view_pos - frag_pos);
	vec3		halfway_dir = normalize(light_dir + view_dir);
	float		spec = pow(max(dot(frag_nor, halfway_dir), 0.f), shininess) * frag_specular;

	// -
	_buff_col = vec4((spec + diff) * light_color / (light_dist * light_dist), 1.f);
}
