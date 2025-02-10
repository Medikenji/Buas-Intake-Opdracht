#include "StartScene.h"

bool StartScene::_gameStarted = false;

StartScene::StartScene(SceneManager &scenemanager) {
  // Set the scene manager
  this->_sceneManager = &scenemanager;
}

StartScene::~StartScene() {
}

void StartScene::Run(float deltaTime) {
  if (GuiButton({SCREEN_WIDTH / 2 - 75, SCREEN_HEIGHT / 2 - 90, 150, 50}, "Start Game")) {
    _sceneManager->SwitchScene(1);
  }

  if (GuiButton({SCREEN_WIDTH / 2 - 75, SCREEN_HEIGHT / 2 - 25, 150, 50}, "Help")) {
    _sceneManager->SwitchScene(2);
  }
  if (GuiButton({SCREEN_WIDTH / 2 - 75, SCREEN_HEIGHT / 2 + 40, 150, 50}, "Quit Game")) {
    CloseWindow();
  }

  for (int i = 0; i < this->children().size(); i++) {
    this->children()[i]->Run(deltaTime);
  }
}
