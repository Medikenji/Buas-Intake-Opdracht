#ifndef CURSOR_H
#define CURSOR_H

#include "Entity.h"
#include "raylib.h"

#define DEFAULT_CURSOR 0
#define HIDDEN_CURSOR  1

/// @brief a cursor entity that replaces the OS cursor
class Cursor {
public:
  // --- Functions --- //

  Cursor();
  ~Cursor();

  void drawCursor();
  static void s_setCursorState(int state) { m_s_cursorState = state; }

private:
  // --- Variables --- //

  static int m_s_cursorState;
  float m_scale;
  Vector2 m_position;
};

#endif // CURSOR_H