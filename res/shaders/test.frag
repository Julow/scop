#version 410 core

in			T_VSHADER_OUT
{
	vec3		pos;
	vec2		tex;
	vec3		nor;
}			fs_in;

out vec4			color;

#define MAX_LIGHT	10

uniform sampler2D	texture2d;
uniform vec3		light_pos[MAX_LIGHT];
uniform int			light_count;

float		ambient_strength = 0.25f; // mtl ?
vec3		light_color = vec3(1.f, 1.f, 1.f); // TODO: mtl

void main()
{
	vec3	light = vec3(0.f, 0.f, 0.f);
	for (int i = 0; i < light_count; i++)
	{
		// Ambient
		vec3	ambient = ambient_strength * light_color;
		// Diffuse
		vec3	light_dir = normalize(light_pos[i] - fs_in.pos);
		float	diff = max(dot(fs_in.nor, light_dir), 0.f);
		vec3	diffuse = diff * light_color;

		light = max(light, diffuse + ambient);
	}
	color = vec4(light, 1.f) * texture(texture2d, fs_in.tex);
}
