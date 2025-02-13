#ifndef START_SCENE_H
#define START_SCENE_H

#include "Entity.h"
#include "SceneManager.h"

// Forward declaration to avoid circular dependency
class SceneManager;

/// @brief handles the start and pause scene.
class StartScene : public Entity {
public:
  // --- Functions --- //

  StartScene(SceneManager &scenemanager);
  ~StartScene();

  virtual void Run(float deltaTime);

private:
  // --- Variables --- //

  bool m_gameStarted;
  SceneManager *m_SceneManager;
};

#endif
