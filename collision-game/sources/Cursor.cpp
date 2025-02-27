#include "Cursor.h"

int Cursor::m_s_cursorState = DEFAULT_CURSOR;

Cursor::Cursor() {
  m_scale = 5.0f;
}

Cursor::~Cursor() {
}

void Cursor::drawCursor() {
  m_position = GetMousePosition();
  switch (m_s_cursorState) {
    // styling of default cursor
  case DEFAULT_CURSOR:
    DrawCircleV({m_position}, m_scale + 1, DARKGRAY);
    DrawCircleLinesV({m_position}, m_scale, WHITE);
    DrawCircleV({m_position}, m_scale / 2, WHITE);
    break;

    // styling of hidden cursor
  case HIDDEN_CURSOR:
    SetMousePosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    break;

    // styling when N/A cursor happens, should not be possible
  default:
    DrawCircleV({SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2}, 10.0f, RED);
    break;
  }
}