#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "GameScene.h"
#include <vector>
#include <SFML/Window.hpp>

/// @brief handles the running of scenes.
class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	/// @brief runs the current scene.
	/// @param deltaTime:the time between frames to pass through.
	/// @return void
	void Run(float deltaTime, sf::RenderWindow &window);

private:
	int currentScene;
	std::vector<BaseScene*> sceneList;
	void AddScene(BaseScene*);
};

#endif