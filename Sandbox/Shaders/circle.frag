#version 330 core
out vec4 FragColor;

in vec3 ourPos;

uniform float time;

#define TWO_PI 6.28318530718

vec3 hsb2rgb(in vec3 c)
{
	vec3 rgb = clamp(abs(mod(c.x * 6.0f + vec3(0.0f, 4.0f, 2.0f), 6.0f) - 3.0f) - 1.0f, 0.0f, 1.0f);
	rgb = rgb * rgb * (3.0f - 2.0f * rgb);
	return c.z * mix( vec3(1.0f), rgb, c.y);
}

void main()
{
	float angle = atan(ourPos.y, ourPos.x) + (time * TWO_PI);
	float radius = length(ourPos.xy) * 2.0f;
	FragColor = vec4(hsb2rgb(vec3((angle/TWO_PI) + 0.5f, radius, 1.0f)), 1.0f);
}