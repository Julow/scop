#version 410 core
  
layout (location = 0) in vec3 buff_pos;
layout (location = 1) in vec2 buff_tex;
layout (location = 2) in vec3 buff_nor;

#define MAX_LIGHT	10

out			T_VSHADER_OUT
{
	// vec3		pos;
	vec2		tex;
	// vec3		nor;
	vec3		light;
}			vs_out;

uniform mat4	model[2];
uniform mat4	view;
uniform mat4	projection;
uniform vec3	light_pos[MAX_LIGHT];
uniform int		light_count;

float		ambient_strength = 0.25f; // mtl ?
vec3		light_color = vec3(1.f, 1.f, 1.f); // TODO: mtl

void		main()
{
	vec4		pos = model[0] * vec4(buff_pos, 1.f);
	vec3		nor = normalize(mat3(transpose(model[1])) * buff_nor);
	vec3		light = vec3(0.f, 0.f, 0.f);

	for (int i = 0; i < light_count; i++)
	{
		// Ambient
		vec3	ambient = ambient_strength * light_color;
		// Diffuse
		vec3	light_dir = normalize(light_pos[i] - pos.xyz);

		float	diff = max(dot(nor, light_dir), 0.f);
		vec3	diffuse = diff * light_color;

		light = max(light, diffuse + ambient);
	}

	// vs_out.pos = pos.xyz;
	vs_out.tex = buff_tex;
	// vs_out.nor = nor;
	vs_out.light = light;

	gl_Position = projection * view * pos;
}
