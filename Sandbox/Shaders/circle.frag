#version 330 core

#include "FastNoiseLite.glsl"

out vec4 FragColor;

in vec3 ourPos;
in vec2 ourTexCoord;

uniform float timer;
uniform sampler2D ourTexture;

#define TWO_PI 6.28318530718

vec3 hsb2rgb(in vec3 c)
{
	vec3 rgb = clamp(abs(mod(c.x * 6.0f + vec3(0.0f, 4.0f, 2.0f), 6.0f) - 3.0f) - 1.0f, 0.0f, 1.0f);
	rgb = rgb * rgb * (3.0f - 2.0f * rgb);
	return c.z * mix( vec3(1.0f), rgb, c.y);
}

void main()
{
	fnl_state state = fnlCreateState(1337);
    state.noise_type = FNL_NOISE_CELLULAR;
    state.fractal_type = FNL_FRACTAL_FBM;
	state.frequency = .01f;
	state.octaves = 4;
	state.lacunarity = 2.f;
	state.gain = .5f;
    
    float noise = fnlGetNoise3D(state, gl_FragCoord.x, timer * 50.f, gl_FragCoord.y) / 2.f + 0.5f;
	
    // FragColor = mix(vec4(noise, noise, noise, 1.0f), texture(ourTexture, ourTexCoord), 0.2f);
	
	float angle = atan(ourPos.y, ourPos.x) + (timer * TWO_PI);
	float radius = length(ourPos.xy) * 2.0f;
	FragColor = mix(vec4(hsb2rgb(vec3((angle/TWO_PI) + 0.5f, radius, 1.0f)), 1.0f), texture(ourTexture, ourTexCoord), 0.5f);
}