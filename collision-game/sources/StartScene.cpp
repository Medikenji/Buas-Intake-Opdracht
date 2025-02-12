#include "StartScene.h"

bool StartScene::_gameStarted = false;

StartScene::StartScene(SceneManager &scenemanager) {
  // Set the scene manager
  this->_sceneManager = &scenemanager;
}

StartScene::~StartScene() {
}

void StartScene::Run(float deltaTime) {
  // Draw the title
  DrawText("Collide!", SCREEN_WIDTH / 2 - MeasureText("Collide!", 50) / 2, SCREEN_HEIGHT / 2 - 150, 50, WHITE);

  // Dynamic start button
  if (GuiButton({SCREEN_WIDTH / 2 - 75, SCREEN_HEIGHT / 2 - 90, 150, 50}, _gameStarted ? "Resume Game" : "Start Game")) {
    _gameStarted = true;
    _sceneManager->SwitchScene(2);
  }

  // Draw the other buttons
  if (GuiButton({SCREEN_WIDTH / 2 - 75, SCREEN_HEIGHT / 2 - 25, 150, 50}, "Help")) {
    _sceneManager->SwitchScene(1);
  }
  if (GuiButton({SCREEN_WIDTH / 2 - 75, SCREEN_HEIGHT / 2 + 40, 150, 50}, "Quit Game") || IsKeyPressedRepeat(KEY_ESCAPE)) {
    CloseWindow();
  }
}