#include "StartScene.h"

StartScene::StartScene(SceneManager &scenemanager) {
  // Set the scene manager
  this->m_gameStarted = false;
  this->m_SceneManager = &scenemanager;
}

StartScene::~StartScene() {
}

void StartScene::Run(float deltaTime) {
  // Draw the title
  DrawText("Kolvor!", ProgramConfig::getScreenWidth() / 2 - MeasureText("Kolvor!", 50) / 2, ProgramConfig::getScreenHeight() / 2 - 150, 50, WHITE);

  // Dynamic start button
  if (GuiButton({(float)ProgramConfig::getScreenWidth() / 2 - 75, (float)ProgramConfig::getScreenHeight() / 2 - 90, 150, 50}, m_gameStarted ? "Resume Game" : "Start Game")) {
    m_gameStarted = true;
    Cursor::SetCursorState(HIDDEN_CURSOR);
    m_SceneManager->SwitchScene(2);
  }

  // Draw the other buttons
  if (GuiButton({(float)ProgramConfig::getScreenWidth() / 2 - 75, (float)ProgramConfig::getScreenHeight() / 2 - 25, 150, 50}, "Help")) {
    m_SceneManager->SwitchScene(1);
  }
  if (GuiButton({(float)ProgramConfig::getScreenWidth() / 2 - 75, (float)ProgramConfig::getScreenHeight() / 2 + 40, 150, 50}, "Quit Game") || IsKeyPressedRepeat(KEY_ESCAPE)) {
    SceneManager::s_exitProgram = true;
  }

  if (GuiButton({0, (float)ProgramConfig::getScreenHeight() - 50, 100, 50}, "Toggle Fullscreen")) {
    ToggleFullscreen();
  }
}