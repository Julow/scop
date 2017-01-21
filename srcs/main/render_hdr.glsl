/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hdr.glsl                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 18:46:23 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/21 19:15:36 by jaguillo         ###   ########.fr       */
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

out vec3			_buff_color;

uniform sampler2D	_u_col;
uniform sampler2D	_u_light;
uniform float		_u_exposure;

#define GAMMA			2.2f

void		main()
{
	vec3		color = texture(_u_col, _frag_tex).xyz
					* texture(_u_light, _frag_tex).xyz;

	color = vec3(1.f) - exp(color * -_u_exposure);
	// color = color / (color + vec3(1.f));
	// _buff_color = pow(color, vec3(1.f / GAMMA));
	_buff_color = color;
}
