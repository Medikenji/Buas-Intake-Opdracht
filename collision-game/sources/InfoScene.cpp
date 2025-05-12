#include "InfoScene.h"

InfoScene::InfoScene(SceneManager &scenemanager) {
  this->m_SceneManager = &scenemanager;
}

InfoScene::~InfoScene() {
}

void InfoScene::Run(float deltaTime) {
  Cursor::s_setCursorState(DEFAULT_CURSOR);
  this->m_SceneManager->switchSceneKeybind(KEY_ESCAPE, 0);
  DrawText("Gotta put something here", ProgramConfig::s_getScreenWidth() * 0.5f - MeasureText("Gotta put something here", 50) * 0.5f, ProgramConfig::s_getScreenHeight() * 0.5f - 150, 50, WHITE);
  DrawText("Press ESC to go back", 0, ProgramConfig::s_getScreenHeight() - 25.0f, 25.0f, WHITE);
}