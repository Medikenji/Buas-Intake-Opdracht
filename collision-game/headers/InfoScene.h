#ifndef INFOSCENE_H
#define INFOSCENE_H

#include "Entity.h"
#include "SceneManager.h"

// Forward declaration to avoid circular dependency
class SceneManager;

/// @brief handles the info scene (keybinds and explanation of the game).
class InfoScene : public Entity {

public:
  InfoScene(SceneManager &scenemanager);
  ~InfoScene();

  void Run(float deltaTime) override;

private:
  SceneManager *_sceneManager;
};

#endif