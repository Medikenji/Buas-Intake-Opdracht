#include "InfoScene.h"

InfoScene::InfoScene(SceneManager &scenemanager) {
  this->m_SceneManager = &scenemanager;
}

InfoScene::~InfoScene() {
}

void InfoScene::Run(float deltaTime) {
  DrawText("Gotta put something here", ProgramConfig::getScreenWidth() / 2 - MeasureText("Gotta put something here", 50) / 2, ProgramConfig::getScreenHeight() / 2 - 150, 50, WHITE);
  DrawText("Press ESC to go back", 0, ProgramConfig::getScreenHeight() - 25, 25, WHITE);
}