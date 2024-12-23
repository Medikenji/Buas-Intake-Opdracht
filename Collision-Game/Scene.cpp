#include "Scene.h"

Scene::Scene()
{
	seconds = 0;
}

Scene::~Scene()
{
}

void Scene::Run(float deltaTime)
{
	position.x += 100 * deltaTime;
	position.y += 100 * deltaTime;
}

void Scene::Draw(sf::RenderWindow& window)
{
	circle.setRadius(50);
	circle.setFillColor(sf::Color(100, 250, 50));
	circle.setPosition(this->position.x, this->position.y);
	window.draw(circle);
}