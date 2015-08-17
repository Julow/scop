#version 410 core
  
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 vColor;
layout (location = 2) in vec2 tPos;

out vec4			vertexColor;
out vec2			texturePos;

void main()
{
	gl_Position = vec4(position.x, position.y, position.z, 1.0);
	vertexColor = vec4(vColor, 1.0);
	texturePos = tPos;
}
