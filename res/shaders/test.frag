#version 410 core

in			T_VSHADER_OUT
{
	vec3		pos;
	vec3		col;
	vec2		tex;
	vec3		nor;
}			fs_in;

out vec4			color;

uniform sampler2D	texture2d;

void main()
{
	color = texture(texture2d, fs_in.tex) * vec4(fs_in.col, 1.f);
}
