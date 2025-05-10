#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "Entity.h"
#include "GameManager.h"
#include "InfoScene.h"
#include "SceneManager.h"

// forward declaration to avoid circular dependency
class SceneManager;
class GameManager;
class InfoScene;

/// @brief handles the gameplay scene
class GameScene : public Entity {
public:
  // --- Functions --- //

  GameScene();
  ~GameScene();

  virtual void Run(float deltaTime);

  /// @brief function that returns the bounds of the GameScene
  /// @return Rectangle: returns a Rectangle with the x, y, width and height of the GameScene
  Rectangle getMapBoundry() {
    return {this->position.x, this->position.y, this->scale.x, this->scale.y};
  }

private:
  // --- Functions --- //

  /// @brief draws all the UI stuff after the gamescene has rendered
  void drawUI();

  // --- Variables --- //

  GameManager *m_GameManager;
};

#endif