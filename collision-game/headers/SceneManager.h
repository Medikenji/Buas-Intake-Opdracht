#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "Entity.h"
#include "GameScene.h"
#include "StartScene.h"

// Forward declaration to avoid circular dependency
class StartScene;
class GameScene;

/// @brief handles the switching of scenes.
class SceneManager : public Entity {
public:
  // --- Functions --- //

  SceneManager();
  ~SceneManager();
  virtual void Run(float deltaTime);

  // @brief a setter that switches the scene.
  void SwitchScene(int scene) { this->_currentScene = scene; };

private:
  // --- Variables --- //

  // @brief the current scene.
  int _currentScene;
  // @brief the start and pause scene.
  StartScene *_startScene;
  // @brief the actual game.
  GameScene *_gameScene;
};

#endif