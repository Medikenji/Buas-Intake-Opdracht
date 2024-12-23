#ifndef CORE_H
#define CORE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "SceneManager.h"


/// @Runs the full game loop to keep main clear. Also creates the window.
class Core
{
public:
	Core();
	~Core();
	void Run();

private:
	SceneManager* sceneManager;
	static int _maxFps;
	static float _deltaTime;
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
};

#endif