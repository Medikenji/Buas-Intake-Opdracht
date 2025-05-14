#include "InfoScene.h"

InfoScene::InfoScene(SceneManager &scenemanager) {
  this->m_SceneManager = &scenemanager;
}

InfoScene::~InfoScene() {
}

void InfoScene::Run(float deltaTime) {
  this->m_SceneManager->switchSceneKeybind(KEY_ESCAPE, 0, DEFAULT_CURSOR);

  // constants to make this functions more managable and readable, made by copilot
  const float scaler = ProgramConfig::s_getNScaler();
  const float gui_font_size = scaler * GUI_SIZE * 0.1f;
  const float gui_offset_y = scaler * 0.04f;
  const float screen_width = ProgramConfig::s_getScreenWidth();
  const float screen_height = ProgramConfig::s_getScreenHeight();

  // draw "The goal is Kolvor is to reach a high score"
  const char *line_1 = "The goal is Kolvor is to reach a high score";
  DrawText(line_1, 0, 0, gui_font_size, WHITE);

  // draw "You do this by colliding the pink and blue player"
  {
    // done with a for loop for inline color styling, made by copilot
    const char *line_2[] = {"You do this by colliding the ", "pink ", "and ", "blue ", "player "};
    const Color colors[] = {WHITE, MAGENTA, WHITE, SKYBLUE, WHITE};
    float x_offset = 0.0f;
    for (int i = 0; i < 5; ++i) {
      DrawText(line_2[i], x_offset, gui_offset_y, gui_font_size, colors[i]);
      x_offset += MeasureText(line_2[i], gui_font_size);
    }
  }

  // draw "Pink can be controlled using the mouse or arrow keys"
  const char *line_3 = "Pink can be controlled using the mouse or arrow keys";
  DrawText(line_3, 0, gui_offset_y * 2, gui_font_size, MAGENTA);

  // draw "Blue can be controlled using WASD"
  const char *line_4 = "Blue can be controlled using WASD";
  DrawText(line_4, 0, gui_offset_y * 3, gui_font_size, SKYBLUE);

  // draw "The faster you collide the more points you get!"
  const char *line_5 = "The faster you collide the more points you get!";
  DrawText(line_5, 0, gui_offset_y * 4, gui_font_size, WHITE);

  // draw "Your players can lose health by being idle or getting hit by the lasers"
  {
    // done with a for loop for inline color styling, made by copilot
    const char *line_6[] = {"Your players can lose health by being idle or getting hit by the ", "lasers"};
    const Color colors[] = {WHITE, RED};
    float x_offset = 0.0f;
    for (int i = 0; i < 2; ++i) {
      DrawText(line_6[i], x_offset, gui_offset_y * 5, gui_font_size, colors[i]);
      x_offset += MeasureText(line_6[i], gui_font_size);
    }
  }

  // draw "The difficulty scales with time"
  const char *line_7 = "The difficulty scales with time";
  DrawText(line_7, 0, gui_offset_y * 6, gui_font_size, MAROON);

  // draw "When a player dies its GAME OVER"
  const char *line_8 = "When a player dies its GAME OVER";
  DrawText(line_8, 0, gui_offset_y * 7, gui_font_size, WHITE);

  // draw "Press esc to go back"
  const char *line_9 = "Press esc to go back";
  DrawText(line_9, 0, screen_height - gui_font_size * 1.5f, gui_font_size, WHITE);
}