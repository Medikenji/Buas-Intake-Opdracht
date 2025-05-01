#include "Cursor.h"

int Cursor::m_s_cursorState = DEFAULT_CURSOR;

Cursor::Cursor() {
  m_scale = ProgramConfig::s_getScaler() * 0.005f;
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
    SetMousePosition(ProgramConfig::s_getScreenWidth() / 2, ProgramConfig::s_getScreenWidth() / 2);
    break;

    // styling when N/A cursor happens, should not be possible
  default:
    DrawCircleV({(float)ProgramConfig::s_getScreenWidth() / 2, (float)ProgramConfig::s_getScreenHeight() / 2}, 10.0f, RED);
    break;
  }
}