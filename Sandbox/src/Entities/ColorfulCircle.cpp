#include "ColorfulCircle.hpp"

float timer;

ColorfulCircle::ColorfulCircle() : Entity()
{
	className = "ColorfulCircle";
}

void ColorfulCircle::Create()
{
	circle.Create(64);
	shader.Create("./Shaders/circle.vert", "./Shaders/circle.frag");
	texture.Create("./Textures/happy.png");
}

void ColorfulCircle::Update()
{
	timer += Time::GetDeltaTime() / 2;
	if(timer > 2.0f) timer = 0.0f;

	shader.Use();
	shader.SetFloat("time", timer);
	texture.Bind();
	circle.Draw();
}