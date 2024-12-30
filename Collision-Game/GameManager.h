#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Entity.h"
#include "Player.h"

// Forward declaration to avoid circular dependency
class Player;

/// @brief handles the game logic.
class GameManager : Entity
{
public:
	// --- Functions --- //

	GameManager();
	~GameManager();

	virtual void Run(float deltaTime);
	virtual void Draw(sf::RenderWindow& window);

private:
	// --- Functions --- //

	// @brief initialises the level (A wrapper around the constructor).
	void initialiseLevel();

	// @brief handles the collision between players.
	// @param std::vector<Entity*> players: the player entities to check.
	void handlePlayerToPLayerCollision(std::vector<Entity*> players);

	// @brief handles the boundaries of the entities.
	// @param std::vector<Entity*> entities: the entities to check.
	// @param uint8_t type: the type of boundary to check.
	void handleBoundaries(std::vector<Entity*> entities, uint8_t type);

	// --- Variables --- //

	// @brief the players in the game.
	std::vector<Entity*> _players;

	// @brief a seperate deltaTime for the game physics.
	float _gameDeltaTime;

};

#endif