#include "ProgramConfig.h"

int ProgramConfig::m_s_screenWidth = 0;
int ProgramConfig::m_s_screenHeight = 0;
int ProgramConfig::m_s_scaler = 0;
int ProgramConfig::m_s_nonScaler = 0;

void ProgramConfig::s_setProgramConfig(int width, int height) {
  m_s_screenWidth = width;
  m_s_screenHeight = height;
  if (m_s_screenWidth < m_s_screenHeight) {
    m_s_scaler = m_s_screenWidth;
    m_s_nonScaler = m_s_screenHeight;
  } else {
    m_s_scaler = m_s_screenHeight;
    m_s_nonScaler = m_s_screenWidth;
  }
}