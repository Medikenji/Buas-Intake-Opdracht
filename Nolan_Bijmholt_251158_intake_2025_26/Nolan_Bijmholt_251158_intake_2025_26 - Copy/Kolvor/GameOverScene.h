#ifndef GAMEOVERSCENE_H
#define GAMEOVERSCENE_H

#include "Entity.h"
#include "SceneManager.h"

// forward declaration to avoid circular dependency
class SceneManager;

/// @brief handles the info scene (keybinds and explanation of the game)
class GameOverScene : public Entity {

public:
  // --- Functions --- //

  GameOverScene(SceneManager &scenemanager);
  ~GameOverScene();

  void Run(float deltaTime);

private:
  // --- Variables --- //

  SceneManager *m_SceneManager;
};

#endif