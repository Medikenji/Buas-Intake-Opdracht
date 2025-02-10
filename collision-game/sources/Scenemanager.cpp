#include "scenemanager.h"

SceneManager::SceneManager() {
  // Add the scenes to the scene manager
  addChild(this->_startScene = new StartScene(*this));
  addChild(this->_gameScene = new GameScene());

  // Set the current scene to the start scene
  this->_currentScene = 0;
}

SceneManager::~SceneManager() {
}

void SceneManager::Run(float deltaTime) {
  this->children()[_currentScene]->Run(deltaTime);
}