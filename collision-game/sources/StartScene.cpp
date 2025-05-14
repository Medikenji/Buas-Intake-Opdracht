#include "StartScene.h"

StartScene::StartScene(SceneManager &scenemanager) {
  // Set the scene manager
  this->m_gameStarted = false;
  this->m_SceneManager = &scenemanager;
}

StartScene::~StartScene() {
}

void StartScene::Run(float deltaTime) {
  // constants to make this functions more managable and readable, made by copilot
  const float screen_width = ProgramConfig::s_getScreenWidth();
  const float screen_height = ProgramConfig::s_getScreenHeight();
  const float scaler = ProgramConfig::s_getScaler();
  const float gui_size = GUI_SIZE * scaler;
  const float halfs_screen_width = screen_width * 0.5f;
  const float half_screen_height = screen_height * 0.5f;

  // Draw the title
  const char *title = "Kolvor!";
  float titleFontSize = gui_size * GUI_SIZE * 1.5f;
  float titleWidth = MeasureText(title, titleFontSize);
  DrawText(title, halfs_screen_width - titleWidth * 0.5f, half_screen_height - gui_size * 0.75f, titleFontSize, WHITE);

  // Dynamic start button
  Rectangle startButton = {halfs_screen_width - gui_size * 0.5f, half_screen_height - gui_size * 0.4f, gui_size, gui_size * 0.3f};
  if (GuiButton(startButton, m_gameStarted ? "Resume Game" : "Start Game")) {
    m_gameStarted = true;
    m_SceneManager->switchScene(2, HIDDEN_CURSOR);
  }

  // Help button
  Rectangle helpButton = {halfs_screen_width - gui_size * 0.5f, half_screen_height, gui_size, gui_size * 0.3f};
  if (GuiButton(helpButton, "Help")) {
    m_SceneManager->switchScene(1, DEFAULT_CURSOR);
  }

  // Quit button
  Rectangle quitButton = {halfs_screen_width - gui_size * 0.5f, half_screen_height + gui_size * 0.4f, gui_size, gui_size * 0.3f};
  if (GuiButton(quitButton, "Quit Game") || IsKeyPressedRepeat(KEY_ESCAPE)) {
    SceneManager::s_exitProgram();
  }

  // Toggle fullscreen button
  Rectangle fullscreenButton = {0, screen_height - gui_size * 0.3f, gui_size * 1.3f, gui_size * 0.3f};
  if (GuiButton(fullscreenButton, IsWindowFullscreen() ? "Enable Borderless" : "Enable Fulscreen")) {
    if (IsWindowFullscreen()) {
      ToggleBorderlessWindowed();
    } else {
      ToggleFullscreen();
    }
  }
}