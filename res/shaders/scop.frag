#version 410 core

in T_VSHADER_OUT
{
	vec3    world_pos;
	vec3    col;
	vec2    tex;
	vec3    nor;
}	fs_in;

out vec4			color;

uniform sampler2D	ourTexture;
uniform vec3		lightPos;
uniform vec3		viewPos;
uniform vec3		lightColor;

void main()
{
	// color = vec4(fs_in.col, 1.f);
	// color = mix(vec4(fs_in.col, 1.f), texture(ourTexture, fs_in.tex), 0.45);
	// color = vec4(0.7, 0.7, 0.7, 1.);
	color = texture(ourTexture, fs_in.tex);
	// Ambient
	float ambientStrength = 0.25f;
	vec3 ambient = ambientStrength * lightcol;

	// Diffuse
	vec3 norm = normalize(fs_in.nor);
	vec3 lightDir = normalize(lightPos - fs_in.world_pos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * lightcol;

	// Specular
	float specularStrength = 0.6f;
	vec3 viewDir = normalize(viewPos - fs_in.world_pos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 256);
	vec3 specular = specularStrength * spec * lightcol;
	
	vec3 result = (ambient + diffuse + specular) * color.xyz;
	color = vec4(result, color.w);
} 
