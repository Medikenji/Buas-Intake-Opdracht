#include "Core.h"

Core::Core() {
  this->m_SceneManager = new SceneManager();
  this->m_deltaTime = 0.0f;
}

Core::~Core() {
}

void Core::Run() {
  // Initialize the window
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Collide!");
  SetTargetFPS(MAX_FPS);

  // Disable escape to close
  SetExitKey(0);

#if PERFORMANCE_TEST == 1
  SetTargetFPS(1000);
#endif

  // Run the game loop
  while (!WindowShouldClose()) {
    // Check if the window is focused and slow the delta time if not.
    if (IsWindowFocused()) {
      this->m_deltaTime = 1.0f / MAX_FPS;
#if PERFORMANCE_TEST == 1
      this->m_deltaTime = GetFrameTime();
#endif
    } else {
      this->m_deltaTime = (1.0f / MAX_FPS) * 0.1f;
#if PERFORMANCE_TEST == 1
      this->m_deltaTime = GetFrameTime() * 0.1f;
#endif
    }

    BeginDrawing();
    ClearBackground(BLACK);
    this->m_SceneManager->Run(m_deltaTime);
#if TEST_ENVIROMENT == 1 || PERFORMANCE_TEST == 1
    DrawFPS(0, 0);
#endif
    EndDrawing();
  }

  // Close the window
  CloseWindow();
}
