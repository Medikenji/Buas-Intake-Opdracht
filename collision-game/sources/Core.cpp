#include "Core.h"

Core::Core() {
  this->m_SceneManager = new SceneManager();
}

Core::~Core() {
  delete this->m_SceneManager;
}

void Core::Run() {
  // initialize the window
  InitWindow(ProgramConfig::getScreenWidth(), ProgramConfig::getScreenHeight(), "Kolvor!");

  // enable vsync
  SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));

  if (ProgramConfig::s_performanceTest)
    SetTargetFPS(0);

  // disable escape to close
  SetExitKey(0);

  // disable the cursor
  HideCursor();

  GuiSetStyle(DEFAULT, TEXT_SIZE, ProgramConfig::getScaler() * GUI_SIZE * 0.15f);
  // run the game loop
  while (!WindowShouldClose() && !SceneManager::s_exitProgram) {
    // check if the window is focused and slow the delta time if not.
    if (IsWindowFocused()) {
      this->m_deltaTime = GetFrameTime();
    } else {
      this->m_deltaTime = GetFrameTime() * 0.1f;
    }

    BeginDrawing();
    ClearBackground(BLACK);
    this->m_SceneManager->Run(m_deltaTime);
    this->m_Cursor.drawCursor();
#if PERFORMANCE_TEST == 1
    DrawFPS(0, 0);
#endif
    EndDrawing();
  }
  // close the window
  CloseWindow();
}
