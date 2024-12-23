#include "scenemanager.h"

SceneManager::SceneManager()
{
	currentScene = 0;
	AddScene(new Scene());
	AddScene(new Scene());
}

SceneManager::~SceneManager()
{
}

void SceneManager::Run(float deltaTime, sf::RenderWindow &window)
{
	sceneList[currentScene]->Run(deltaTime);
	sceneList[currentScene]->Draw(window);
}

void SceneManager::AddScene(Scene* scene)
{
	sceneList.push_back(scene);
}