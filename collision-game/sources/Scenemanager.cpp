#include "SceneManager.h"

SceneManager::SceneManager() {
  // Add the scenes to the scene manager
  addChild(this->m_StartScene = new StartScene(*this));
  addChild(this->m_InfoScene = new InfoScene(*this));
  addChild(this->m_GameScene = new GameScene());

  // Set the current scene to the start scene
  this->m_currentScene = 0;

  // Set the current scene to the game scene for testing to skip the start scene
#if TEST_ENVIROMENT == 1
  m_currentScene = 2;
#endif
}

SceneManager::~SceneManager() {
  // Delete the scenes
  delete this->m_StartScene;
  delete this->m_InfoScene;
  delete this->m_GameScene;
}

void SceneManager::Run(float deltaTime) {
  if (IsKeyDown(KEY_ESCAPE)) {
    Cursor::SetCursorState(DEFAULT_CURSOR);
    m_currentScene = 0;
  }

  // Run the current scene
  this->children()[m_currentScene]->Run(deltaTime);
}