/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.glsl                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:50:52 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/16 17:55:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#version 410 core

//#shader vert

layout (location = 0) in vec3	_vert_pos;
layout (location = 1) in vec2	_vert_tex;
layout (location = 2) in vec3	_vert_nor;

out vec3			_frag_pos;
out vec2			_frag_tex;
out vec3			_frag_nor;

uniform mat4		_u_model;
uniform mat4		_u_viewproj;

void		main()
{
	vec4		pos = _u_model * vec4(_vert_pos, 1.f);
	vec4		nor = _u_model * vec4(_vert_nor, 0.f);

	_frag_pos = pos.rgb;
	_frag_tex = _vert_tex;
	_frag_nor = nor.rgb;
	gl_Position = _u_viewproj * pos;
}

//#shader frag

layout (location = 0) out vec3	_buff_pos;
layout (location = 1) out vec3	_buff_nor;
layout (location = 2) out vec4	_buff_col;

in vec3				_frag_pos;
in vec2				_frag_tex;
in vec3				_frag_nor;

uniform sampler2D	_u_diffuse_map;
uniform sampler2D	_u_specular_map;

void		main()
{
	_buff_pos = _frag_pos;
	_buff_nor = normalize(_frag_nor);
	_buff_col = vec4(texture(_u_diffuse_map, _frag_tex).rgb,
			texture(_u_specular_map, _frag_tex).r);
}
