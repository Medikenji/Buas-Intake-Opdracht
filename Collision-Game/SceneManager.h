#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <vector>
#include <SFML/Window.hpp>

#include "Entity.h"
#include "GameScene.h"

/// @brief handles the switching of scenes.
class SceneManager : public Entity
{
public:
	// --- Functions --- //

	SceneManager();
	~SceneManager();

	virtual void Run(float deltaTime);
	virtual void Draw(sf::RenderWindow& window);

private:
	// --- Variables --- //
	int currentScene;
};

#endif