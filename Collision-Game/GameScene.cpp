#include "GameScene.h"

GameScene::GameScene()
{
	_gameDirector = new Director();
}

GameScene::~GameScene()
{
}

void GameScene::Run(float deltaTime)
{
	_gameDirector->Run(deltaTime);
}

void GameScene::Draw(sf::RenderWindow& window)
{
	_gameDirector->Draw(window);
}