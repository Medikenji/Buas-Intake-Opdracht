#include "GameOverScene.h"

GameOverScene::GameOverScene(SceneManager &scenemanager) {
  this->m_SceneManager = &scenemanager;
}

GameOverScene::~GameOverScene() {
}

void GameOverScene::Run(float deltaTime) {
  Cursor::s_setCursorState(DEFAULT_CURSOR);

  // constants to make this functions more managable and readable, made by copilot
  const float scaler = ProgramConfig::s_getScaler();
  const float gui_font_size = scaler * GUI_SIZE * 0.2f;
  const float gui_offset_y = scaler * 0.04f;
  const float screen_width = ProgramConfig::s_getScreenWidth();
  const float screen_height = ProgramConfig::s_getScreenHeight();

  // draw "GAME OVER" text
  const char *game_over_text = "GAME OVER";
  const float game_over_text_width = MeasureText(game_over_text, gui_font_size * 1.5f);
  DrawText(game_over_text, screen_width * 0.5f - game_over_text_width * 0.5f, screen_height * 0.5f - gui_offset_y, gui_font_size * 1.5f, RED);

  // draw score text
  const std::string score_text = "score: " + std::to_string(Player::s_getPlayerPoints());
  const float score_text_width = MeasureText(score_text.c_str(), gui_font_size);
  DrawText(score_text.c_str(), screen_width * 0.5f - score_text_width * 0.5f, screen_height * 0.5f + gui_offset_y, gui_font_size, WHITE);

  // draw survival time text
  const std::string survival_text = "You survived for " + std::to_string(static_cast<int>(this->m_SceneManager->getGameDuration())) + " seconds!";
  const float survival_text_width = MeasureText(survival_text.c_str(), gui_font_size);
  DrawText(survival_text.c_str(), screen_width * 0.5f - survival_text_width * 0.5f, screen_height * 0.5f + gui_offset_y * 2.0f, gui_font_size, WHITE);

  // handle Quit Game button
  const Rectangle quit_button = {0, screen_height - scaler * 0.3f * GUI_SIZE, scaler * 1.3f * GUI_SIZE, scaler * 0.3f * GUI_SIZE};
  if (GuiButton(quit_button, "Quit Game") || IsKeyPressedRepeat(KEY_ESCAPE)) {
    SceneManager::s_exitProgram();
  }

  this->runChildren(deltaTime);
}