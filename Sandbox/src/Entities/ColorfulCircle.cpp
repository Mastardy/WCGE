#include "ColorfulCircle.hpp"
#include "../Mesh/CircleMesh.hpp"
#include "../Material/CircleMaterial.hpp"

#include <iostream>

ColorfulCircle::ColorfulCircle() : Entity()
{
	className = "ColorfulCircle";
	AddComponent<Transform>(static_cast<Entity*>(this));
}

void ColorfulCircle::Create()
{
	circleMesh = CircleMesh(64);

	circleMaterial = CircleMaterial(ResourceManager::LoadShader("CircleShader", "./Shaders/circle.vert", "./shaders/circle.frag"),
		ResourceManager::LoadTexture("CircleTexture", "./Textures/happy.png"));

	AddComponent<MeshRenderer>(static_cast<Entity*>(this), &circleMesh, &circleMaterial);
}

void ColorfulCircle::Update()
{
	timer += Time::GetDeltaTime() / 2;
	if(timer > 2.0f) timer = 0.0f;

	circleMaterial.timer = timer;

	Entity::Update();
}