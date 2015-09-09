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
uniform vec3	camera_pos;
uniform vec3	light_pos[MAX_LIGHT];
uniform int		light_count;

float		ambient_strength = 0.25f; // mtl ?
float		specular_strength = 0.6f; // mtl ?
int			specular_exp = 256; // TODO: mtl
vec3		light_color = vec3(1.f, 1.f, 1.f); // TODO: mtl

void		main()
{
	vec4		pos = model[0] * vec4(buff_pos, 1.f);
	vec3		nor = normalize(mat3(model[1]) * buff_nor);
	vec3		light = vec3(0.f, 0.f, 0.f);

	for (int i = 0; i < light_count; i++)
	{
		// Ambient
		vec3	ambient = ambient_strength * light_color;
		// Diffuse
		vec3	light_dir = normalize(light_pos[i] - pos.xyz);
		float	diff = max(dot(nor, light_dir), 0.f);
		vec3	diffuse = diff * light_color;
		// Specular
		vec3	camera_dir = normalize(camera_pos - pos.xyz);
		vec3	reflect_dir = reflect(-light_dir, nor);
		float	spec = pow(max(dot(camera_dir, reflect_dir), 0.f), specular_exp);
		vec3	specular = specular_strength * spec * light_color;

		light = max(light, diffuse + ambient + specular);
	}

	// vs_out.pos = pos.xyz;
	vs_out.tex = buff_tex;
	// vs_out.nor = nor;
	vs_out.light = light;

	gl_Position = projection * view * pos;
}
