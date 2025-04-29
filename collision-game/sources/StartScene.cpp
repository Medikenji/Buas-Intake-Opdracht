#include "StartScene.h"

StartScene::StartScene(SceneManager &scenemanager) {
  // Set the scene manager
  this->m_gameStarted = false;
  this->m_SceneManager = &scenemanager;
  m_uiScale = ProgramConfig::getScaler() * GUI_SIZE;
}

StartScene::~StartScene() {
}

void StartScene::Run(float deltaTime) {
  // Draw the title
  DrawText("Kolvor!", ProgramConfig::getScreenWidth() * 0.5 - MeasureText("Kolvor!", m_uiScale * GUI_SIZE * 1.5f) * 0.5f, ProgramConfig::getScreenHeight() * 0.5f - m_uiScale * 0.75f, m_uiScale * 0.3f, WHITE);

  // Dynamic start button
  if (GuiButton({ProgramConfig::getScreenWidth() * 0.5f - m_uiScale * 0.5f, ProgramConfig::getScreenHeight() * 0.5f - m_uiScale * 0.4f, m_uiScale, m_uiScale * 0.3f}, m_gameStarted ? "Resume Game" : "Start Game")) {
    m_gameStarted = true;
    Cursor::SetCursorState(HIDDEN_CURSOR);
    m_SceneManager->SwitchScene(2);
  }

  // Draw the other buttons
  if (GuiButton({ProgramConfig::getScreenWidth() * 0.5f - m_uiScale * 0.5f, ProgramConfig::getScreenHeight() * 0.5f, m_uiScale, m_uiScale * 0.3f}, "Help")) {
    m_SceneManager->SwitchScene(1);
  }
  if (GuiButton({ProgramConfig::getScreenWidth() * 0.5f - m_uiScale * 0.5f, ProgramConfig::getScreenHeight() * 0.5f - m_uiScale * -0.4f, m_uiScale, m_uiScale * 0.3f}, "Quit Game") || IsKeyPressedRepeat(KEY_ESCAPE)) {
    SceneManager::s_exitProgram = true;
  }

   if (GuiButton({0, ProgramConfig::getScreenHeight() - m_uiScale*0.3f, m_uiScale*1.3f, m_uiScale * 0.3f }, "Toggle Fullscreen")) {
     ToggleFullscreen();
   }
}