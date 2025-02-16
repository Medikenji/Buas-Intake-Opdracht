#include "GameScene.h"

GameScene::GameScene() {
  this->addChild(m_GameManager = new GameManager());
#ifdef PRIMARY_Y
  position.x = (NON_SCALER - SCALER) / 2;
#endif
#ifdef PRIMARY_X
  position.y = (NON_SCALER - SCALER) / 2;
#endif
  this->scale = {SCALER,
                 SCALER};
}

GameScene::~GameScene() {
  delete m_GameManager;
}

void GameScene::Run(float deltaTime) {
  DrawRectangleLines(position.x, position.y, scale.x + 1, scale.y + 1, WHITE);
  this->runChildren(deltaTime);
}