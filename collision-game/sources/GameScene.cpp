#include "GameScene.h"

GameScene::GameScene() {
  this->addChild(m_GameManager = new GameManager());
}

GameScene::~GameScene() {
  delete m_GameManager;
}

void GameScene::Run(float deltaTime) {
  this->runChildren(deltaTime);
}