#version 410 core

in			T_VSHADER_OUT
{
	// vec3		pos;
	vec2		tex;
	// vec3		nor;
	vec3		light;
}			fs_in;

out vec4			color;

uniform sampler2D	texture2d;

void main()
{
	color = vec4(fs_in.light, 1.f) * texture(texture2d, fs_in.tex);
}
