#ifndef PROGRAM_CONFIG_H
#define PROGRAM_CONFIG_H

#include <iostream>

/// @brief A class to encapsulate program configuration settings.
class ProgramConfig {
public:
  // --- Variables --- //

  /// @brief Changes the maximum framerate of the program to 1000 instead of vsync for performance testing.
  static const bool s_performanceTest = false;

  // --- Functions --- //

  /// @brief sets the scaler and non scaler
  static void s_setProgramConfig(int width, int height);

  /// @brief returns wether the program's width is higher then the height
  /// @return bool: true if the width is higher then the height
  static bool s_isPrimaryX() {
    return m_s_screenWidth > m_s_screenHeight;
  }

  /// @brief the smallest size between the screen width and height to prevent clipping
  /// @return int: the size in pixels
  static int s_getScaler() {
    return m_s_scaler;
  }

  /// @brief the largest size between the screen width and height to allow some scaling
  /// @return int: the size in pixels
  static int s_getNScaler() {
    return m_s_nonScaler;
  }

  /// @brief the width of the game window
  /// @return int: the width in pixels
  static int s_getScreenWidth() {
    return m_s_screenWidth;
  }

  /// @brief the height of the game window
  /// @return int: the height in pixels
  static int s_getScreenHeight() {
    return m_s_screenHeight;
  }

private:
  // --- Variables --- //

  static int m_s_screenWidth;
  static int m_s_screenHeight;
  static int m_s_scaler;
  static int m_s_nonScaler;
};

#endif