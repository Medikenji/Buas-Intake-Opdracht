#include "StartScene.h"

bool StartScene::_gameStarted = false;

StartScene::StartScene(SceneManager& scenemanager)
{
	// Set the scene manager
	this->_sceneManager = &scenemanager;

	// Create the start button
	this->addChild(_startButton = new Button(sf::Vector2f((SCREEN_WIDTH / 2)-100, SCREEN_HEIGHT / 4), sf::Color::Red, sf::Vector2f(200, 50), "Start"));
}

StartScene::~StartScene()
{
}

void StartScene::Run(float deltaTime)
{
	_sceneManager->SwitchScene(1);
	for (int i = 0; i < this->children().size(); i++)
	{
		this->children()[i]->Run(deltaTime);
	}
}

void StartScene::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < this->children().size(); i++)
	{
		this->children()[i]->Draw(window);
	}
}

