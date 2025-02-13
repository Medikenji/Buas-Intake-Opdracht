#include "GameScene.h"

GameScene::GameScene() {
  this->addChild(m_GameManager = new GameManager());
}

GameScene::~GameScene() {
}

void GameScene::Run(float deltaTime) {
  this->runChildren(deltaTime);
}