#include "GameScene.h"

GameScene::GameScene()
{
	_gameDirector = new Director(&this->children());
}

GameScene::~GameScene()
{
}

void GameScene::Run(float deltaTime)
{
	_gameDirector->Run(deltaTime);
	for (int i = 0; i < this->children().size(); i++)
	{
		this->children()[i]->Run(deltaTime);
	}

}

void GameScene::Draw(sf::RenderWindow& window)
{
	_gameDirector->Draw(window);
	for (int i = 0; i < this->children().size(); i++)
	{
		this->children()[i]->Draw(window);
	}
}