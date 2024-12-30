#ifndef START_SCENE_H
#define START_SCENE_H

#include "Entity.h"
#include "SceneManager.h"
#include "Button.h"

// Forward declaration to avoid circular dependency
class SceneManager;
class Button;

/// @brief handles the start and pause scene.
class StartScene : public Entity
{
public:
	// --- Functions --- //

	StartScene(SceneManager& scenemanager);
	~StartScene();

	virtual void Run(float deltaTime);
	virtual void Draw(sf::RenderWindow& window);

private:
	// --- Variables --- //

	static bool _gameStarted;
	SceneManager* _sceneManager;
	Button* _startButton;
};

#endif
