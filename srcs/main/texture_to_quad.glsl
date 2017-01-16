/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_to_quad.glsl                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 19:17:51 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/16 15:45:24 by jaguillo         ###   ########.fr       */
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

uniform sampler2D	_u_texture;

void		main()
{
	_buff_col = texture(_u_texture, _frag_tex);
}
