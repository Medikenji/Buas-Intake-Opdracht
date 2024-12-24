#include "GameScene.h"

GameScene::GameScene()
{
	this->addChild(new Player());
	this->addChild(new Player());
	static_cast<void>(children().size()); // Discarding return value
}

GameScene::~GameScene()
{
}

void GameScene::Run(float deltaTime)
{
	size_t s = this->children().size();
	for (size_t i = 0; i < s; i++)
	{
		this->children()[i]->Run(deltaTime);
		this->HandleCollisions(this->children()[i]);
	}
}

void GameScene::Draw(sf::RenderWindow& window)
{
	size_t s = this->children().size();
	for (size_t i = 0; i < s; i++)
	{
		this->children()[i]->Draw(window);
	}
}

void GameScene::HandleCollisions(Entity* entity)
{
	if (entity->inBounds)
	{
		if (entity->position.x < 0)
		{
			entity->position.x = 0;
			entity->inverseXVelocity(0.5);
		}
		if (entity->position.x > SCREEN_WIDTH)
		{
			entity->position.x = SCREEN_WIDTH;
			entity->inverseXVelocity(0.5);
		}
		if (entity->position.y < 0)
		{
			entity->position.y = 0;
			entity->inverseYVelocity(0.5);
		}
		if (entity->position.y > SCREEN_HEIGHT)
		{
			entity->position.y = SCREEN_HEIGHT;
			entity->inverseYVelocity(0.5);
		}
	}
}