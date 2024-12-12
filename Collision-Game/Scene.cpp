#include "Scene.h"

Scene::Scene()
{
	seconds = 0;
}

Scene::~Scene()
{
}

void Scene::Run(float deltaTime)
{
	seconds += deltaTime;
	std::cout << "Scene " << this->getEID() << " running for "<< (int)seconds <<" seconds" << std::endl;
}