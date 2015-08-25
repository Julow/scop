#version 410 core
  
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 vColor;
layout (location = 2) in vec2 tPos;
layout (location = 3) in vec3 nor;

out vec4			vertexColor;
out vec2			texturePos;

uniform mat4		model;
uniform mat4		view;
uniform mat4		projection;

void main()
{
	gl_Position = projection * view * model * vec4(position, 1.0);
	vertexColor = vec4(vColor, 1.0);
	texturePos = tPos;
}
