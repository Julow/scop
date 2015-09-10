/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.vert                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 11:44:37 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/10 13:41:18 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#version 410 core
  
layout (location = 0) in vec3	buff_pos;
layout (location = 1) in vec2	buff_tex;
layout (location = 2) in vec3	buff_nor;

out			T_VSHADER_OUT
{
	vec3		pos;
	vec2		tex;
	vec3		nor;
}			vs_out;

uniform mat4		model[2];
uniform mat4		view;
uniform mat4		projection;

void		main()
{
	vec4		pos = model[0] * vec4(buff_pos, 1.f);

	vs_out.pos = pos.xyz;
	vs_out.tex = buff_tex;
	vs_out.nor = normalize(mat3(model[1]) * buff_nor);

	gl_Position = projection * view * pos;
}
