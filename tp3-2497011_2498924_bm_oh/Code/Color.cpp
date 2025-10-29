#include "stdafx.h"
#include "Color.h"

static const char* colorCodes[] = { "\033[31m", "\033[32m", "\033[36m", "\033[33m","", "\033[37m", "\033[30m" };
static const char* colorSymbols[] = { "R", "G", "C", "Y"," ", "W", "B" };
std::ostream& operator<<(std::ostream& os, const Color& color)
{
  os << colorCodes[static_cast<int>(color)];
  os << colorSymbols[static_cast<int>(color)];
  os << "\033[0m"; // Reset color
  return os;
}
