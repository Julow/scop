/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_gbuffer.glsl                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 18:46:23 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/21 18:46:55 by jaguillo         ###   ########.fr       */
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

void		main()
{
}
