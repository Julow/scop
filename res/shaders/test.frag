#version 410 core

in vec4				vertexColor;
in vec2				texturePos;

out vec4			color;

uniform sampler2D	texture2d;

void main()
{
	color = texture(texture2d, texturePos) * vertexColor;
}
