#include "GameScene.h"

GameScene::GameScene() {
  if (ProgramConfig::s_isPrimaryX())
    this->position.x = (ProgramConfig::s_getNScaler() - ProgramConfig::s_getScaler()) * 0.5f;
  else
    this->position.y = (ProgramConfig::s_getNScaler() - ProgramConfig::s_getScaler()) * 0.5f;

  this->scale = {(float)ProgramConfig::s_getScaler(),
                 (float)ProgramConfig::s_getScaler()};
  this->addChild(this->m_GameManager = new GameManager());
}

GameScene::~GameScene() {
  delete this->m_GameManager;
}

void GameScene::Run(float deltaTime) {
  Cursor::s_setCursorState(HIDDEN_CURSOR);
  DrawRectangleLines(position.x - 1.0f, position.y - 1.0f, scale.x + 2.0f, scale.y + 2.0f, WHITE);
  DrawRectangle(position.x, position.y, scale.x, scale.y, BLACK);
  this->runChildren(deltaTime);

  // draw after the children have been drawn
  drawUI();
}

void GameScene::drawUI() {
  // create an ostringstream object for styling floats with one decimal, copilot helped with this
  std::ostringstream oss;
  oss.precision(1);

  // constants to make this functions more managable and readable
  float non_scaler = ProgramConfig::s_getNScaler();
  float scaler = ProgramConfig::s_getScaler();
  float gui_font_size = scaler * GUI_SIZE * 0.2f;
  float gui_offset_y = scaler * 0.04f;
  float screen_width = ProgramConfig::s_getScreenWidth();

  // draw external rectangles to hide clipping game entities
  Color external_color = {15, 15, 15, 255};
  if (ProgramConfig::s_isPrimaryX()) {
    DrawRectangle(0, 0, this->position.x - 2.0f, non_scaler, external_color);
    DrawRectangle(this->position.x + this->scale.x + 1.0f, 0.0f, non_scaler, non_scaler, external_color);
  } else {
    DrawRectangle(0, 0, non_scaler, this->position.y - 2.0f, external_color);
    DrawRectangle(0, this->position.y + this->scale.y + 1.0f, non_scaler, non_scaler, external_color);
  }

  // player points
  DrawText(std::to_string(Player::s_getPlayerPoints()).c_str(), 0, 0, gui_font_size, WHITE);

  // player points multiplier
  oss << std::fixed << Player::s_getPlayerPointsMultiplier();
  std::string playerMultiplier = "x" + oss.str();

  // clear the oss string
  oss.str("");
  DrawText(playerMultiplier.c_str(), 0, gui_offset_y, gui_font_size, WHITE);

  // enemy flair text
  const char *enemyText = "Enemy difficulty";
  float enemyTextWidth = MeasureText(enemyText, gui_font_size);
  DrawText(enemyText, screen_width - enemyTextWidth, 0, gui_font_size, RED);

  // enemy difficulty multiplier
  oss << std::fixed << Enemy::s_getMultiplier();
  std::string enemyMultiplier = "x" + oss.str();
  float enemyMultiplierWidth = MeasureText(enemyMultiplier.c_str(), gui_font_size);
  DrawText(enemyMultiplier.c_str(), screen_width - enemyMultiplierWidth, gui_offset_y, gui_font_size, RED);
}