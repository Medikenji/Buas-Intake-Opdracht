#include "StartScene.h"

StartScene::StartScene(SceneManager &scenemanager) {
  // Set the scene manager
  this->m_gameStarted = false;
  this->m_SceneManager = &scenemanager;
  m_uiScale = ProgramConfig::s_getScaler() * GUI_SIZE;
}

StartScene::~StartScene() {
}

void StartScene::Run(float deltaTime) {
  // Draw the title
  DrawText("Kolvor!", ProgramConfig::s_getScreenWidth() * 0.5 - MeasureText("Kolvor!", m_uiScale * GUI_SIZE * 1.5f) * 0.5f, ProgramConfig::s_getScreenHeight() * 0.5f - m_uiScale * 0.75f, m_uiScale * 0.3f, WHITE);

  // Dynamic start button
  if (GuiButton({ProgramConfig::s_getScreenWidth() * 0.5f - m_uiScale * 0.5f, ProgramConfig::s_getScreenHeight() * 0.5f - m_uiScale * 0.4f, m_uiScale, m_uiScale * 0.3f}, m_gameStarted ? "Resume Game" : "Start Game")) {
    m_gameStarted = true;
    Cursor::s_setCursorState(HIDDEN_CURSOR);
    m_SceneManager->switchScene(2);
  }

  // Draw the other buttons
  if (GuiButton({ProgramConfig::s_getScreenWidth() * 0.5f - m_uiScale * 0.5f, ProgramConfig::s_getScreenHeight() * 0.5f, m_uiScale, m_uiScale * 0.3f}, "Help")) {
    m_SceneManager->switchScene(1);
  }
  if (GuiButton({ProgramConfig::s_getScreenWidth() * 0.5f - m_uiScale * 0.5f, ProgramConfig::s_getScreenHeight() * 0.5f - m_uiScale * -0.4f, m_uiScale, m_uiScale * 0.3f}, "Quit Game") || IsKeyPressedRepeat(KEY_ESCAPE)) {
    SceneManager::s_exitProgram();
  }
}