#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Entity.h"
#include "Player.h"

/// @brief handles the game logic.
class Director : Entity
{
public:
	Director(std::vector<Entity*>* currentSceneChildren);
	~Director();
	virtual void Run(float deltaTime);
	virtual void Draw(sf::RenderWindow& window);

private:
	void initialiseLevel();

	// @brief handles the boundaries of the entities.
	// @param std::vector<Entity*> entities: the entities to check.
	// @param uint8_t type: the type of boundary to check.
	void handleBoundaries(std::vector<Entity*> entities, uint8_t type);

	std::vector<Entity*> *_currentSceneChildren;
	std::vector<Entity*> _players;
	
};

#endif