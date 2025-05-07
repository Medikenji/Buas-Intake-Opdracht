#ifndef PROGRAM_CONFIG_H
#define PROGRAM_CONFIG_H

#include <iostream>

/// @brief A class to encapsulate program configuration settings.
class ProgramConfig {
public:
  // --- Variables --- //

  /// @brief Changes the maximum framerate of the program to 1000 instead of vsync for performance testing.
  static const bool s_performanceTest = true;

  // --- Functions --- //

  static void s_setProgramConfig(int width, int height);

  static bool s_isPrimaryY() {
    return m_s_screenWidth > m_s_screenHeight;
  }

  static int s_getScaler() {
    return m_s_scaler;
  }

  static int s_getNScaler() {
    return m_s_nonScaler;
  }

  static int s_getScreenWidth() {
    return m_s_screenWidth;
  }

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