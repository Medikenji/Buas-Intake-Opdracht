#include "Core.h"

Core::Core() {
  this->sceneManager = new SceneManager();
  this->_deltaTime = 0.0f;
}

Core::~Core() {
}

void Core::Run() {
  // Initialize the window
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Collide!");
  SetTargetFPS(MAX_FPS);

#if PERFORMANCE_TEST == 1
  SetTargetFPS(1000);
#endif

  bool isFocussed = true;

  // Run the game loop
  while (!WindowShouldClose()) {
    // Check if the window is focused
    if (IsWindowFocused()) {
      isFocussed = true;
      this->_deltaTime = 1.0f / MAX_FPS;
#if PERFORMANCE_TEST == 1
      this->_deltaTime = GetFrameTime();
#endif
    } else {
      isFocussed = false;
      this->_deltaTime = (1.0f / MAX_FPS) * 0.1f;
#if PERFORMANCE_TEST == 1
      this->_deltaTime = GetFrameTime() * 0.1f;
#endif
    }

    // Update and draw the scene
    sceneManager->Run(this->_deltaTime);

    BeginDrawing();
    ClearBackground(BLACK);
    sceneManager->Run(_deltaTime);
#if TEST_ENVIROMENT == 1 || PERFORMANCE_TEST == 1
    DrawFPS(0, 0);
#endif
    EndDrawing();
  }

  // Close the window
  CloseWindow();
}
