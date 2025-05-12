#include "StartScene.h"

StartScene::StartScene(SceneManager &scenemanager) {
  // Set the scene manager
  this->m_gameStarted = false;
  this->m_SceneManager = &scenemanager;
}

StartScene::~StartScene() {
}

void StartScene::Run(float deltaTime) {
  Cursor::s_setCursorState(DEFAULT_CURSOR);
  float ui_scale = ProgramConfig::s_getScaler() * GUI_SIZE;

  // Draw the title
  DrawText("Kolvor!", ProgramConfig::s_getScreenWidth() * 0.5f - MeasureText("Kolvor!", ui_scale * GUI_SIZE * 1.5f) * 0.5f, ProgramConfig::s_getScreenHeight() * 0.5f - ui_scale * 0.75f, ui_scale * 0.3f, WHITE);

  // Dynamic start button
  if (GuiButton({ProgramConfig::s_getScreenWidth() * 0.5f - ui_scale * 0.5f, ProgramConfig::s_getScreenHeight() * 0.5f - ui_scale * 0.4f, ui_scale, ui_scale * 0.3f}, m_gameStarted ? "Resume Game" : "Start Game")) {
    m_gameStarted = true;
    m_SceneManager->switchScene(2);
  }

  // Draw the other buttons
  if (GuiButton({ProgramConfig::s_getScreenWidth() * 0.5f - ui_scale * 0.5f, ProgramConfig::s_getScreenHeight() * 0.5f, ui_scale, ui_scale * 0.3f}, "Help")) {
    m_SceneManager->switchScene(1);
  }
  if (GuiButton({ProgramConfig::s_getScreenWidth() * 0.5f - ui_scale * 0.5f, ProgramConfig::s_getScreenHeight() * 0.5f - ui_scale * -0.4f, ui_scale, ui_scale * 0.3f}, "Quit Game") || IsKeyPressedRepeat(KEY_ESCAPE)) {
    SceneManager::s_exitProgram();
  }

  if (GuiButton({0, ProgramConfig::s_getScreenHeight() - ui_scale * 0.3f, ui_scale * 1.3f, ui_scale * 0.3f}, "Toggle Fullscreen")) {
    ToggleFullscreen();
  }
}