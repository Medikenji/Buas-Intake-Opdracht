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
  bool isFocussed = true;

  // Run the game loop
  while (!WindowShouldClose()) {
    // Check if the window is focused
    if (IsWindowFocused()) {
      isFocussed = true;
      this->_deltaTime = 1.0f / MAX_FPS;
    } else {
      isFocussed = false;
      this->_deltaTime = (1.0f / MAX_FPS) * 0.1f;
    }

    // Update and draw the scene
    sceneManager->Run(this->_deltaTime);

    BeginDrawing();
    ClearBackground(BLACK);
    sceneManager->Run(_deltaTime);
    EndDrawing();
  }

  // Close the window
  CloseWindow();
}
