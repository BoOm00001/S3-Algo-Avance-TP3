 #pragma once
#include <ostream>
enum class Color
{
  RED,
  GREEN,
  CYAN,
  YELLOW,
  NB_COLORS,
  WHITE,
  BLACK,
  
};

std::ostream& operator<<(std::ostream& os, const Color& color);
