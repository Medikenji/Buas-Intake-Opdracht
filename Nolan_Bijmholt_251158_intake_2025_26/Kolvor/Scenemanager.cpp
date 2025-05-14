#include "SceneManager.h"

bool SceneManager::m_s_exitProgram = false;

SceneManager::SceneManager() {
  // add the scenes to the scene manager
  addChild(this->m_StartScene = new StartScene(*this));
  addChild(this->m_InfoScene = new InfoScene(*this));
  addChild(this->m_GameScene = new GameScene(*this));
  addChild(this->m_GameOverScene = new GameOverScene(*this));
  m_GameTimer = new Timer();
  m_GameTimer->Start();
  m_GameTimer->Pause();

  // set the current scene to the start scene
  this->m_currentScene = 0;
}

SceneManager::~SceneManager() {
  delete this->m_StartScene;
  delete this->m_InfoScene;
  delete this->m_GameScene;
  delete this->m_GameOverScene;
}

void SceneManager::Run(float deltaTime) {
  // run the current scene
  this->children()[this->m_currentScene]->Run(deltaTime);

  // run the timer when in game
  if (this->m_currentScene == 2) {
    if (m_GameTimer->isPaused()) {
      m_GameTimer->Unpause();
    }
  } else {
    if (!m_GameTimer->isPaused()) {
      m_GameTimer->Pause();
    }
  }
}

void SceneManager::switchSceneKeybind(KeyboardKey key, int scene, int cursorState) {
  if (IsKeyDown(key)) {
    this->m_currentScene = scene;
    Cursor::s_setCursorState(cursorState);
  }
}