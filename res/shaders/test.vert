#version 410 core
  
layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 col;
layout (location = 2) in vec2 tex;
layout (location = 3) in vec3 nor;

out			T_VSHADER_OUT
{
	vec3		pos;
	vec3		col;
	vec2		tex;
	vec3		nor;
}			vs_out;

uniform mat4		model;
uniform mat4		view;
uniform mat4		projection;

void main()
{
	vec4			pos = model * vec4(pos, 1.0);

	vs_out.pos = vec3(pos);
	vs_out.col = col;
	vs_out.tex = tex;
	vs_out.nor = mat3(transpose(inverse(model))) * nor;
	gl_Position = projection * view * pos;
}
