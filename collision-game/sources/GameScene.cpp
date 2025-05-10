#include "GameScene.h"

GameScene::GameScene() {
  if (ProgramConfig::s_isPrimaryX())
    position.x = (ProgramConfig::s_getNScaler() - ProgramConfig::s_getScaler()) * 0.5f;
  else
    position.y = (ProgramConfig::s_getNScaler() - ProgramConfig::s_getScaler()) * 0.5f;

  this->scale = {(float)ProgramConfig::s_getScaler(),
                 (float)ProgramConfig::s_getScaler()};
  this->addChild(m_GameManager = new GameManager());
}

GameScene::~GameScene() {
  delete m_GameManager;
}

void GameScene::Run(float deltaTime) {
  DrawRectangleLines(position.x - 1, position.y - 1, scale.x + 2, scale.y + 2, WHITE);
  DrawRectangle(position.x, position.y, scale.x, scale.y, BLACK);
  this->runChildren(deltaTime);

  // draw after the children have been drawn
  drawUI();
}

void GameScene::drawUI() {
  // constants to make this functions more managable
  float guiFontSize = ProgramConfig::s_getScaler() * GUI_SIZE * 0.2f;
  float guiOffsetY = ProgramConfig::s_getScaler() * 0.035f;
  float screenWidth = ProgramConfig::s_getScreenWidth();
  float nonScaler = ProgramConfig::s_getNScaler();
  float scaler = ProgramConfig::s_getScaler();

  // draw external rectangles to hide clipping game entities
  Color external_color = {15, 15, 15, 255};
  if (ProgramConfig::s_isPrimaryX()) {
    DrawRectangle(0, 0, position.x - 2, nonScaler, external_color);
    DrawRectangle(position.x + scale.x + 1, 0, nonScaler, nonScaler, external_color);
  } else {
    DrawRectangle(0, 0, nonScaler, position.y - 2, external_color);
    DrawRectangle(0, position.y + scale.y + 1, nonScaler, nonScaler, external_color);
  }

  // player points
  DrawText(std::to_string(Player::s_getPlayerPoints()).c_str(), 0, 0, guiFontSize, WHITE);

  // player points multiplier
  std::string playerMultiplier = "x" + std::to_string(Player::s_getPlayerPointsMultiplier());
  DrawText(playerMultiplier.c_str(), 0, guiOffsetY, guiFontSize, WHITE);

  // enemy flair text
  const char *enemyText = "Enemy difficulty";
  float enemyTextWidth = MeasureText(enemyText, guiFontSize);
  DrawText(enemyText, screenWidth - enemyTextWidth, 0, guiFontSize, RED);

  // enemy difficulty multiplier
  std::string enemyMultiplier = "x" + std::to_string(Enemy::s_getMultiplier());
  float enemyMultiplierWidth = MeasureText(enemyMultiplier.c_str(), guiFontSize);
  DrawText(enemyMultiplier.c_str(), screenWidth - enemyMultiplierWidth, guiOffsetY, guiFontSize, RED);
}