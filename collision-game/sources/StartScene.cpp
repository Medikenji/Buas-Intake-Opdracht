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
  DrawText("Collide!", SCREEN_WIDTH / 2 - MeasureText("Collide!", 50) / 2, SCREEN_HEIGHT / 2 - 150, 50, WHITE);

  // Dynamic start button
  if (GuiButton({SCREEN_WIDTH / 2 - 75, SCREEN_HEIGHT / 2 - 90, 150, 50}, m_gameStarted ? "Resume Game" : "Start Game")) {
    m_gameStarted = true;
    Cursor::SetCursorState(HIDDEN_CURSOR);
    m_SceneManager->SwitchScene(2);
  }

  // Draw the other buttons
  if (GuiButton({SCREEN_WIDTH / 2 - 75, SCREEN_HEIGHT / 2 - 25, 150, 50}, "Help")) {
    m_SceneManager->SwitchScene(1);
  }
  if (GuiButton({SCREEN_WIDTH / 2 - 75, SCREEN_HEIGHT / 2 + 40, 150, 50}, "Quit Game") || IsKeyPressedRepeat(KEY_ESCAPE)) {
    SceneManager::s_exitProgram = true;
  }

  if (GuiButton({0, SCREEN_HEIGHT - 50, 100, 50}, "Toggle Fullscreen")) {
    ToggleFullscreen();
  }
}