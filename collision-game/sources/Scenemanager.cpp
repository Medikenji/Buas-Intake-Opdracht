#include "SceneManager.h"

bool SceneManager::m_s_exitProgram = false;

SceneManager::SceneManager() {
  // Add the scenes to the scene manager
  addChild(this->m_StartScene = new StartScene(*this));
  addChild(this->m_InfoScene = new InfoScene(*this));
  addChild(this->m_GameScene = new GameScene());

  // Set the current scene to the start scene
  this->m_currentScene = 0;
}

SceneManager::~SceneManager() {
  // Delete the scenes
  delete this->m_StartScene;
  delete this->m_InfoScene;
  delete this->m_GameScene;
}

void SceneManager::Run(float deltaTime) {
  if (IsKeyDown(KEY_ESCAPE)) {
    this->m_currentScene = 0;
  }

  // Run the current scene
  this->children()[this->m_currentScene]->Run(deltaTime);
}