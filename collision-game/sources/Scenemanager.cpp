#include "scenemanager.h"

SceneManager::SceneManager() {
  // Add the scenes to the scene manager
  addChild(this->_startScene = new StartScene(*this));
  addChild(this->_infoScene = new InfoScene(*this));
  addChild(this->_gameScene = new GameScene());

  // Set the current scene to the start scene
  this->_currentScene = 0;

  // Set the current scene to the game scene for testing to skip the start scene
#if TEST_ENVIROMENT == 1
  _currentScene = 1;
#endif
}

SceneManager::~SceneManager() {
}

void SceneManager::Run(float deltaTime) {
  if (IsKeyDown(KEY_ESCAPE)) {
    _currentScene = 0;
  }

  // Run the current scene
  this->children()[_currentScene]->Run(deltaTime);
}