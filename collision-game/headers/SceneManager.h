#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "Entity.h"
#include "GameScene.h"
#include "InfoScene.h"
#include "StartScene.h"

// Forward declaration to avoid circular dependency
class StartScene;
class GameScene;
class InfoScene;

/// @brief handles the switching of scenes.
class SceneManager : public Entity {
public:
  // --- Functions --- //

  SceneManager();
  ~SceneManager();
  virtual void Run(float deltaTime);

  /// @brief a setter that switches the scene.
  void SwitchScene(int scene) { this->m_currentScene = scene; };

private:
  // --- Variables --- //

  /// @brief the current scene.
  int m_currentScene;
  /// @brief the start and pause scene.
  StartScene *m_StartScene;
  /// @brief the actual game.
  GameScene *m_GameScene;
  /// @brief the info scene.
  InfoScene *m_InfoScene;
};

#endif