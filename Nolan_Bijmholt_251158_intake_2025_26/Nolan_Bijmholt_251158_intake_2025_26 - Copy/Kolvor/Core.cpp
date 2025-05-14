#include "Core.h"

Core::Core() {
}

Core::~Core() {
  delete this->m_SceneManager;
}

void Core::Run() {
  // initialize the window
  InitWindow(GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor()), "Kolvor!");
  ProgramConfig::s_setProgramConfig(GetScreenWidth(), GetScreenHeight());
  this->m_SceneManager = new SceneManager();

  SetRandomSeed(time(nullptr));

  // enable vsync
  SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));

  if (ProgramConfig::s_performanceTest)
    SetTargetFPS(0);

  // disable escape to close
  SetExitKey(0);

  // disable the cursor
  HideCursor();

  GuiSetStyle(DEFAULT, TEXT_SIZE, ProgramConfig::s_getScaler() * GUI_SIZE * 0.15f);
  // run the game loop
  float delta_time;
  Cursor Cursor;
  while (!WindowShouldClose() && !SceneManager::s_shouldExitProgram()) {
    // check if the window is focused and slow the delta time if not.
    if (IsWindowFocused()) {
      delta_time = GetFrameTime();
    } else {
      delta_time = GetFrameTime() * 0.1f;
    }

    BeginDrawing();
    ClearBackground({32, 32, 32, 255});
    this->m_SceneManager->Run(delta_time);
    Cursor.drawCursor();
    if (ProgramConfig::s_performanceTest)
      DrawFPS(0, 0);
    EndDrawing();
  }
  // close the window
  CloseWindow();
}
