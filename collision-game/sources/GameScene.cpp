#include "GameScene.h"

GameScene::GameScene() {
  this->addChild(m_GameManager = new GameManager());
  if (ProgramConfig::isPrimaryY())
    position.x = (ProgramConfig::getNScaler() - ProgramConfig::getScaler()) / 2;
  else
    position.y = (ProgramConfig::getNScaler() - ProgramConfig::getScaler()) / 2;

  this->scale = {(float)ProgramConfig::getScaler(),
                 (float)ProgramConfig::getScaler()};
  this->m_GameManager->position = this->position;
  this->m_GameManager->scale.x = this->scale.x;
  this->m_GameManager->scale.y = this->scale.y;
}

GameScene::~GameScene() {
  delete m_GameManager;
}

void GameScene::Run(float deltaTime) {
  DrawRectangleLines(position.x, position.y, scale.x + 1, scale.y + 1, WHITE);
  this->runChildren(deltaTime);
}