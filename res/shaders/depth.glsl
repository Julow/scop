/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depth.glsl                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 08:21:57 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/21 11:15:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#version 410 core

#define T_VSHADER_OUT t_vshader_out \
{ \
	vec3		pos; \
	vec2		tex; \
	vec3		nor; \
}

//#shader vert

layout (location = 0) in vec3	buff_pos;
layout (location = 1) in vec2	buff_tex;
layout (location = 2) in vec3	buff_nor;

out T_VSHADER_OUT	vs_out;

uniform mat4		model;
uniform mat4		view;
uniform mat4		projection;

void		main()
{
	vec4		pos = model * vec4(buff_pos, 1.f);

	vs_out.pos = pos.xyz;

	gl_Position = projection * view * pos;
}

//#shader frag

in T_VSHADER_OUT	fs_in;

out vec4			color;

uniform vec3		camera_pos;

void		main()
{
	float		camera_dist = length(camera_pos - fs_in.pos);

	camera_dist = 1 - (camera_dist / 1000.f);
	color = vec4(camera_dist, camera_dist, camera_dist, 1.f);
}
