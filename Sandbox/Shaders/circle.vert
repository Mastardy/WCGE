#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec3 ourPos;
out vec2 ourTexCoord;

uniform mat4 mvp;

void main()
{
	gl_Position = mvp * vec4(aPos, 1.0f);
	ourPos = aPos;
	ourTexCoord = aTexCoord;
}