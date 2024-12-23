#include "Core.h"

int Core::_maxFps = 60;
float Core::_deltaTime = 1.0f / _maxFps;

Core::Core()
{
	sceneManager = new SceneManager();
}

Core::~Core()
{
}

void Core::Run()
{
	// Create the window
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Collide!", sf::Style::Titlebar | sf::Style::Close);
	bool isFocussed = true;
	sf::Event event;

	// Set the max frames per second a set deltatime for easy of physics use
	window.setFramerateLimit(_maxFps);

	// Run the game loop
	while (window.isOpen())
	{
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			// Render the game in slow motion when focus is lost
			if (event.type == sf::Event::LostFocus)
				isFocussed = false;
			if (event.type == sf::Event::GainedFocus)
				isFocussed = true;
		}

			window.clear(sf::Color::Black);
			if (isFocussed)
			{
				_deltaTime = 1.0f / _maxFps;
			}
			else
			{
				_deltaTime = (1.0f / _maxFps) * 0.1f;
			}
            sceneManager->Run(_deltaTime, window);
			window.display();
	}
}