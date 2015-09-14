/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.frag                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 11:44:32 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/14 11:25:16 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#version 410 core

#define MAX_LIGHT	10

in			T_VSHADER_OUT
{
	vec3		pos;
	vec2		tex;
	vec3		nor;
}			fs_in;

out vec4			color;

uniform sampler2D	texture2d;
uniform vec3		camera_pos;
uniform vec3		light_pos[MAX_LIGHT];
uniform int			light_count;

int			specular_exp = 256; // TODO: mtl
vec3		ambient_color = vec3(0.25f, 0.25f, 0.25f);
vec3		diffuse_color = vec3(1.f, 1.f, 1.f);
vec3		specular_color = vec3(0.6f, 0.6f, 0.6f);

void		main()
{
	vec3		light = vec3(0.f, 0.f, 0.f);

	for (int i = 0; i < light_count; i++)
	{
		// Ambient
		vec3	ambient = ambient_color;
		// Diffuse
		vec3	light_dir = normalize(light_pos[i] - fs_in.pos);
		float	diff = max(dot(fs_in.nor, light_dir), 0.f);
		vec3	diffuse = diff * diffuse_color;
		// Specular
		vec3	camera_dir = normalize(camera_pos - fs_in.pos);
		vec3	reflect_dir = reflect(-light_dir, fs_in.nor);
		float	spec = pow(max(dot(camera_dir, reflect_dir), 0.f), specular_exp);
		vec3	specular = spec * specular_color;

		light = max(light, diffuse + ambient + specular);
	}

	color = vec4(light, 1.f) * texture(texture2d, fs_in.tex);
}
