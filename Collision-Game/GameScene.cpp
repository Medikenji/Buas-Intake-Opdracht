#include "GameScene.h"

GameScene::GameScene()
{
	this->addChild(_gameManager = new GameManager());
}

GameScene::~GameScene()
{
}

void GameScene::Run(float deltaTime)
{
	this->runChildren(deltaTime);
}

void GameScene::Draw(sf::RenderWindow& window)
{
	this->drawChildren(window);
}