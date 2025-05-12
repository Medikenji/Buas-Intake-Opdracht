#include "GameOverScene.h"

GameOverScene::GameOverScene(SceneManager &scenemanager) {
  this->m_SceneManager = &scenemanager;
}

GameOverScene::~GameOverScene() {
}

void GameOverScene::Run(float deltaTime) {
  Cursor::s_setCursorState(DEFAULT_CURSOR);
  this->runChildren(deltaTime);
  float ui_scale = ProgramConfig::s_getScaler() * GUI_SIZE;

  DrawText(std::to_string(Player::s_getPlayerPoints()).c_str(), ProgramConfig::s_getScreenWidth() * 0.5f, ProgramConfig::s_getScreenHeight() * 0.5f, 30, WHITE);

  if (GuiButton({0, ProgramConfig::s_getScreenHeight() - ui_scale * 0.3f, ui_scale * 1.3f, ui_scale * 0.3f}, "Quit Game") || IsKeyPressedRepeat(KEY_ESCAPE)) {
    SceneManager::s_exitProgram();
  }
}