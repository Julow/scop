/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.glsl                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 11:44:32 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/18 17:43:22 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#version 410 core

//#shader vert

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

//#shader frag

#define GAMMA			2.2
#define FIX_GAMMA(COL)	pow((COL), vec3(GAMMA))
#define SET_GAMMA(COL)	pow((COL), vec3(1.f / GAMMA))

#define MAX_LIGHT		10

in			T_VSHADER_OUT
{
	vec3		pos;
	vec2		tex;
	vec3		nor;
}			fs_in;

out vec4			color;

uniform vec3		camera_pos;
uniform vec3		light_pos[MAX_LIGHT];
uniform int			light_count;

uniform sampler2D	ambient_map;
uniform sampler2D	diffuse_map;
uniform sampler2D	specular_map;
uniform vec3		ambient_color;
uniform vec3		diffuse_color;
uniform vec3		specular_color;
uniform int			specular_exp;

void		main()
{
	vec3		light = vec3(0.f);

	for (int i = 0; i < light_count; i++)
	{
		// Ambient
		vec3	ambient = FIX_GAMMA(ambient_color) * FIX_GAMMA(vec3(texture(ambient_map, fs_in.tex)));
		// Diffuse
		float	camera_dist = length(light_pos[i] - fs_in.pos);
		vec3	light_dir = normalize(light_pos[i] - fs_in.pos);
		float	diff = max(dot(fs_in.nor, light_dir), 0.f);
		float	att = 1.f - camera_dist / 800.f;
		vec3	diffuse = diff * att * (FIX_GAMMA(diffuse_color) * FIX_GAMMA(vec3(texture(diffuse_map, fs_in.tex))));
		// Specular
		vec3	camera_dir = normalize(camera_pos - fs_in.pos);
		vec3	reflect_dir = reflect(-light_dir, fs_in.nor);
		float	spec = max(pow(dot(camera_dir, reflect_dir), specular_exp), 0.f);
		vec3	specular = spec * att * (FIX_GAMMA(specular_color) * FIX_GAMMA(vec3(texture(specular_map, fs_in.tex))));

		light = max(light, diffuse + ambient + specular);
	}

	color = vec4(SET_GAMMA(light), 1.f);
}
