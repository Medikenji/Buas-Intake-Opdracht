#include "GameScene.h"

GameScene::GameScene() {
  this->addChild(m_GameManager = new GameManager());
  if (ProgramConfig::s_isPrimaryY())
    position.x = (ProgramConfig::s_getNScaler() - ProgramConfig::s_getScaler()) * 0.5f;
  else
    position.y = (ProgramConfig::s_getNScaler() - ProgramConfig::s_getScaler()) * 0.5f;

  this->scale = {(float)ProgramConfig::s_getScaler(),
                 (float)ProgramConfig::s_getScaler()};
  this->m_GameManager->position = this->position;
  this->m_GameManager->scale.x = this->scale.x;
  this->m_GameManager->scale.y = this->scale.y;
}

GameScene::~GameScene() {
  delete m_GameManager;
}

void GameScene::Run(float deltaTime) {
  DrawRectangleLines(position.x - 1, position.y - 1, scale.x + 2, scale.y + 2, WHITE);
  DrawRectangle(position.x, position.y, scale.x, scale.y, BLACK);
  this->runChildren(deltaTime);
  DrawText(std::to_string(Player::s_getPlayerPoints()).c_str(), 0, 0, 0, WHITE);
}