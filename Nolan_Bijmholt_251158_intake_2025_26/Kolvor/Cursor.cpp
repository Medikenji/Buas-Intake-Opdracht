#include "Cursor.h"

int Cursor::m_s_cursorState = DEFAULT_CURSOR;

Cursor::Cursor() {
  this->m_scale = ProgramConfig::s_getScaler() * 0.005f;
}

Cursor::~Cursor() {
}

void Cursor::drawCursor() {
  this->m_position = GetMousePosition();
  switch (this->m_s_cursorState) {
    // styling of default cursor
  case DEFAULT_CURSOR:
    DrawCircleV({this->m_position}, this->m_scale + 1.0f, DARKGRAY);
    DrawCircleLinesV({this->m_position}, this->m_scale, WHITE);
    DrawCircleV({this->m_position}, this->m_scale * 0.5f, WHITE);
    break;

    // styling of hidden cursor
  case HIDDEN_CURSOR:
    SetMousePosition(ProgramConfig::s_getScreenWidth() * 0.5f, ProgramConfig::s_getScreenWidth() * 0.5f);
    break;

    // styling when N/A cursor happens, should not be possible
  default:
    DrawCircleV({(float)ProgramConfig::s_getScreenWidth() * 0.5f, (float)ProgramConfig::s_getScreenHeight() * 0.5f}, 10.0f, RED);
    break;
  }
}