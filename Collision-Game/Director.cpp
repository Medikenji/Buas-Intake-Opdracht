#include "Director.h"
#include <iostream>

Director::Director()
{
	initialiseLevel();
}

Director::~Director()
{
}

void Director::Run(float deltaTime)
{
	this->_gameDeltaTime = deltaTime;
	handleBoundaries(_players, 1);
	handlePlayerToPLayerCollision(_players, deltaTime);
	std::cout << this->_gameDeltaTime << std::endl;
	for (int i = 0; i < this->children().size(); i++)
	{
		this->children()[i]->Run(this->_gameDeltaTime);
	}
}

void Director::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < this->children().size(); i++)
	{
		this->children()[i]->Draw(window);
	}
}

void Director::initialiseLevel()
{
	this->_players.push_back(new Player());
	this->addChild(_players[0]);
	this->_players.push_back(new Player());
	this->addChild(_players[1]);
}

void Director::handlePlayerToPLayerCollision(std::vector<Entity*> players, float deltaTime)
{
	// Made with help from: https://www.jeffreythompson.org/collision-detection/circle-circle.php

	// Cast the entities to players for easier readability.
	Player* a = dynamic_cast<Player*>(players[0]);
	Player* b = dynamic_cast<Player*>(players[1]);

	// Calculate the distance between the players.
	float x = a->position.x - b->position.x;
	float y = a->position.y - b->position.y;
	float distance = sqrt(x * x + y * y);
	
	// Handle slow motion
	if (distance <= (a->scale.x + b->scale.x)*4)
	{
		this->_gameDeltaTime *= distance*0.01;
	}
	if (this->_gameDeltaTime > deltaTime)
	{
		this->_gameDeltaTime = deltaTime;
	}

	// If the players are colliding
	if (distance <= a->scale.x + b->scale.x)
	{
		a->inverseVelocity(2);
		b->inverseVelocity(2);
	}

}

void Director::handleBoundaries(std::vector<Entity*> entities, uint8_t type)
{
	switch (type)
	{
		// If the entities are players
	case 1:
		for (int i = 0; i < entities.size(); i++)
		{
			Entity* entity = entities[i];
			if (entity->inBounds)
			{
				if (entity->position.x < 0 + entity->scale.x)
				{
					entity->position.x = 0 + entity->scale.x;
					entity->inverseXVelocity(0.5);
				}
				if (entity->position.x > SCREEN_WIDTH - entity->scale.x)
				{
					entity->position.x = SCREEN_WIDTH - entity->scale.x;
					entity->inverseXVelocity(0.5);
				}
				if (entity->position.y < 0 + entity->scale.x)
				{
					entity->position.y = 0 + entity->scale.x;
					entity->inverseYVelocity(0.5);
				}
				if (entity->position.y > SCREEN_HEIGHT - entity->scale.x)
				{
					entity->position.y = SCREEN_HEIGHT - entity->scale.x;
					entity->inverseYVelocity(0.5);
				}
			}
		}
		break;
	}
}