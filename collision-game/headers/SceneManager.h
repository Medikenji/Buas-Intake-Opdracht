#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "Entity.h"
#include "GameOverScene.h"
#include "GameScene.h"
#include "InfoScene.h"
#include "StartScene.h"
#include "Timer.h"

// forward declaration to avoid circular dependency
class StartScene;
class GameScene;
class InfoScene;
class GameOverScene;
class Timer;

/// @brief handles the switching of scenes
class SceneManager : public Entity {
public:
  // --- Functions --- //

  SceneManager();
  ~SceneManager();
  virtual void Run(float deltaTime);

  /// @brief a setter that switches the scene
  void switchScene(int scene) { this->m_currentScene = scene; };

  void switchSceneKeybind(KeyboardKey key, int scene);

  /// @brief checks if the program should be closed by this custom call
  /// @return bool: if the program should close
  static bool s_shouldExitProgram() { return m_s_exitProgram; };

  /// @brief exits the program in a custom and clean way
  static void s_exitProgram() { m_s_exitProgram = true; };

  /// @brief returns how long the player has been active in the game scene
  /// @return double: the duration in seconds
  double getGameDuration() { return m_GameTimer->Seconds(); };

private:
  // --- Variables --- //

  /// @brief allows for a custom and clean call to exit the program
  static bool m_s_exitProgram;
  /// @brief the current scene
  int m_currentScene;
  /// @brief the start and pause scene
  StartScene *m_StartScene;
  /// @brief the actual game
  GameScene *m_GameScene;
  /// @brief the info scene
  InfoScene *m_InfoScene;
  /// @brief the scene that shows the player stats after they've died
  GameOverScene *m_GameOverScene;
  /// @brief saves how long the game has been running
  Timer *m_GameTimer;
};

#endif