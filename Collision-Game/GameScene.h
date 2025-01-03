#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "Entity.h"
#include "GameManager.h"
#include "SceneManager.h"

// Forward declaration to avoid circular dependency
class SceneManager;
class GameManager;

/// @brief handles the gameplay scene.
class GameScene : public Entity
{
public:
	// --- Functions --- //

	GameScene();
	~GameScene();

	virtual void Run(float deltaTime);
	virtual void Draw(sf::RenderWindow& window);

private:
	// --- Variables --- //

	GameManager* _gameManager;
};

#endif