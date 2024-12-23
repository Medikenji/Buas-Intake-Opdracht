#include "Scene.h"

Scene::Scene()
{
	seconds = 0;
	Player* player1 = new Player();
	this->addChild(player1);
	Player* player2 = new Player();
	this->addChild(player2);
}

Scene::~Scene()
{
}

void Scene::Run(float deltaTime)
{
	int s = this->getChildren().size();
	for (int i = 0; i < s; i++)
	{
		this->getChildren()[i]->Run(deltaTime);
	}
}

void Scene::Draw(sf::RenderWindow& window)
{
	int s = this->getChildren().size();
	for (int i = 0; i < s; i++)
	{
		this->getChildren()[i]->Draw(window);
	}
}