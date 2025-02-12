#include "InfoScene.h"

InfoScene::InfoScene(SceneManager &scenemanager) {
  this->_sceneManager = &scenemanager;
}

InfoScene::~InfoScene() {
}

void InfoScene::Run(float deltaTime) {
  DrawText("Gotta put something here", SCREEN_WIDTH / 2 - MeasureText("Gotta put something here", 50) / 2, SCREEN_HEIGHT / 2 - 150, 50, WHITE);
  DrawText("Press ESC to go back", 0, SCREEN_HEIGHT - 25, 25, WHITE);
}