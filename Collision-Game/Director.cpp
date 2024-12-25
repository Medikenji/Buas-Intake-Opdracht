#include "Director.h"

Director::Director(std::vector<Entity*>* currentSceneChildren)
{
	_currentSceneChildren = currentSceneChildren;
	initialiseLevel();
}

Director::~Director()
{
}

void Director::Run(float deltaTime)
{
	handleBoundaries(_players, 1);
}

void Director::Draw(sf::RenderWindow& window)
{

}

void Director::initialiseLevel()
{
	_players.push_back(new Player());
	_currentSceneChildren->push_back(_players[0]);
	_players.push_back(new Player());
	_currentSceneChildren->push_back(_players[1]);
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