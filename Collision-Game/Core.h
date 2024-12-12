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
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;

private:
	SceneManager* sceneManager;
};

#endif