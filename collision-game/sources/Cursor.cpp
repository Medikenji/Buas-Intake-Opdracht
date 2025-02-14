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
  case DEFAULT_CURSOR:
    DrawCircleV({m_position}, m_scale + 1, DARKGRAY);
    DrawCircleLinesV({m_position}, m_scale, WHITE);
    DrawCircleV({m_position}, m_scale / 2, WHITE);
    break;
  case HIDDEN_CURSOR:
    break;

  default:
    DrawCircleV({0, 0}, 10.0f, RED);
    break;
  }
}