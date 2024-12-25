#include "scenemanager.h"

SceneManager::SceneManager()
{
	this->currentScene = 0;
	this->addChild(new GameScene());
}

SceneManager::~SceneManager()
{
}

void SceneManager::Run(float deltaTime)
{
	this->children()[currentScene]->Run(deltaTime);
}

void SceneManager::Draw(sf::RenderWindow& window)
{
	this->children()[currentScene]->Draw(window);
}