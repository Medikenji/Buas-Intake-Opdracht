#define RAYGUI_IMPLEMENTATION
#include "Core.h"

int main() {
  int width, height;
  std::cout << "Enter screen width: ";
  std::cin >> width;
  std::cout << "Enter screen height: ";
  std::cin >> height;
  ProgramConfig::s_setProgramConfig(width, height);

  // Create a new game instance
  Core *game = new Core();

  // Run the game
  game->Run();

  // Delete the game instance
  delete game;
  return 0;
}