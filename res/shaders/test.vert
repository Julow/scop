#version 410 core
  
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 vColor;
layout (location = 2) in vec2 tPos;

out vec4			vertexColor;
out vec2			texturePos;

uniform mat4		test_mat;

void main()
{
	gl_Position = test_mat * vec4(position, 1.0);
	vertexColor = vec4(vColor, 1.0);
	texturePos = tPos;
}
