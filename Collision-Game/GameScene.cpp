#include "GameScene.h"

GameScene::GameScene()
{
	_gameManager = new GameManager();
}

GameScene::~GameScene()
{
}

void GameScene::Run(float deltaTime)
{
	_gameManager->Run(deltaTime);
}

void GameScene::Draw(sf::RenderWindow& window)
{
	_gameManager->Draw(window);
}