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

void SceneManager::Run(float deltaTime)
{
	sceneList[currentScene]->Run(deltaTime);
}

void SceneManager::AddScene(Scene* scene)
{
	sceneList.push_back(scene);
}