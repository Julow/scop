/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.glsl                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:50:52 by jaguillo          #+#    #+#             */
/*   Updated: 2017/01/11 19:41:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#version 410 core

// #define T_VSHADER_OUT t_vshader_out \
// { \
// 	vec3		pos; \
// 	vec3		nor; \
// 	vec2		tex; \
// }

//#shader vert

layout (location = 0) in vec3	buff_pos;
layout (location = 1) in vec2	buff_tex;
layout (location = 2) in vec3	buff_nor;

// out T_VSHADER_OUT	vs_out;

uniform mat4		model;
uniform mat4		viewproj;

void		main()
{
	vec4		pos = model * vec4(buff_pos, 1.f);

	// vs_out.pos = pos;
	// vs_out.nor = buff_nor;
	// vs_out.tex = buff_tex;
	gl_Position = viewproj * pos;
}

//#shader frag

// in T_VSHADER_OUT	fs_in;

out vec4			color;

// uniform sampler2D	diffuse_map;

void		main()
{
	// color = texture(diffuse_map, fs_in.tex);
	color = vec4(0.f, 0.f, 0.f, 1.f);
}
