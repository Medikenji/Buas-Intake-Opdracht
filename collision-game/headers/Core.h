#ifndef CORE_H
#define CORE_H

#include "GlobalVariables.h"
#include "SceneManager.h"

// Forward declaration to avoid circular dependency
class SceneManager;

/// @brief runs the full game loop to keep main clear. Also creates the window.
class Core {
public:
  // --- Functions --- //

  Core();
  ~Core();

  void Run();

private:
  // --- Variables --- //

  SceneManager *m_SceneManager;
  float m_deltaTime;
};

#endif