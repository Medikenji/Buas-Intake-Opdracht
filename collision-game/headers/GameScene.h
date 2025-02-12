#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "Entity.h"
#include "GameManager.h"
#include "InfoScene.h"
#include "SceneManager.h"

// Forward declaration to avoid circular dependency
class SceneManager;
class GameManager;
class InfoScene;

/// @brief handles the gameplay scene.
class GameScene : public Entity {
public:
  // --- Functions --- //

  GameScene();
  ~GameScene();

  virtual void Run(float deltaTime);

private:
  // --- Variables --- //

  GameManager *_gameManager;
};

#endif