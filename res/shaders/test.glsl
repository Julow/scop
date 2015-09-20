/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.glsl                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 11:44:32 by jaguillo          #+#    #+#             */
/*   Updated: 2015/09/20 18:53:30 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#version 410 core

#define GAMMA			2.2
#define FIX_GAMMA(COL)	pow((COL), vec3(GAMMA))
#define SET_GAMMA(COL)	pow((COL), vec3(1.f / GAMMA))

#define LIGHT_BUFF_SIZE	30

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

in T_VSHADER_OUT	fs_in;

out vec4			color;

// Lights
uniform vec3		camera_pos;

// point light	{0.f, att_dist, 0.f}, {x, y, z}
// spot light	{1.f, cuttof, out}, {x, y, z}, {dx, dy, dz}
uniform vec3		lights[LIGHT_BUFF_SIZE];
uniform int			light_count;

int					att_exp = 4;

// Materials
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
	vec3		nor = normalize(fs_in.nor);
	vec3		ambient_col = FIX_GAMMA(ambient_color) * FIX_GAMMA(vec3(texture(ambient_map, fs_in.tex)));
	vec3		diffuse_col = FIX_GAMMA(diffuse_color) * FIX_GAMMA(vec3(texture(diffuse_map, fs_in.tex)));
	vec3		specular_col = FIX_GAMMA(specular_color) * FIX_GAMMA(vec3(texture(specular_map, fs_in.tex)));
	vec3		ambient;
	vec3		diffuse;
	vec3		specular;

	for (int i = 0; i < light_count; i++)
	{
		if (lights[i].x == 0.f)
		{
			float	att_dist	= lights[i].y;
			i++;
			vec3	light_pos	= lights[i];
			// point light
			// Ambient
			ambient = ambient_col;
			// Attenuation
			float	light_dist	= length(light_pos - fs_in.pos);
			float	att			= pow(max(1.f - light_dist / att_dist, 0.f), att_exp);
			// Diffuse
			vec3	light_dir	= (light_pos - fs_in.pos) / light_dist;
			float	diff		= max(dot(nor, light_dir), 0.f);
			diffuse = diff * att * diffuse_col;
			// Specular
			vec3	camera_dir	= normalize(camera_pos - fs_in.pos);
			vec3	spec_dir	= normalize(light_dir + camera_dir);
			float	spec		= max(pow(dot(nor, spec_dir), specular_exp), 0.f);
			specular = spec * specular_col;
		}
		else if (lights[i].x == 1.f)
		{
			float	att_dist	= 1000.f; // TMP
			float	cutoff		= lights[i].y;
			float	out_cutoff	= lights[i].z;
			i++;
			vec3	light_pos	= lights[i];
			i++;
			vec3	spot_dir	= lights[i];
			// spot light
			// Ambient
			ambient = ambient_col;
			// Attenuation
			float	light_dist	= length(light_pos - fs_in.pos);
			float	att			= pow(max(1.f - light_dist / att_dist, 0.f), att_exp);
			// Diffuse
			vec3	light_dir	= (light_pos - fs_in.pos) / light_dist;
			float	diff		= max(dot(nor, light_dir), 0.f);
			diffuse = diff * att * diffuse_col;
			// Specular
			specular = vec3(0.f); // TODO
			// Spot
			float	theta		= dot(light_dir, normalize(-spot_dir));
			float	epsilon		= cutoff - out_cutoff;
			float	intensity	= 1.f - clamp((theta - out_cutoff) / epsilon, 0.f, 1.f);
			diffuse *= intensity;
		}
		light = max(light, ambient + diffuse + specular);
	}
	color = vec4(SET_GAMMA(light), 1.f);
}
