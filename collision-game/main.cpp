#define RAYGUI_IMPLEMENTATION
#include "Core.h"

int main() {
  Core *game = new Core();
  game->Run();
  delete game;
  return 0;
}