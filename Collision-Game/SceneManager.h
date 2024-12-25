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
	SceneManager();
	~SceneManager();

	virtual void Run(float deltaTime);
	virtual void Draw(sf::RenderWindow& window);

private:

	int currentScene;
};

#endif