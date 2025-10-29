#include "stdafx.h"
#include "Combination.h"

Combination Combination::getRandomCombination()
{
  // Choisir une couleur aléatoire
  Color c1 = static_cast<Color>(rand() % static_cast<int>(Color::NB_COLORS));
  Color c2 = static_cast<Color>(rand() % static_cast<int>(Color::NB_COLORS));
  Color c3 = static_cast<Color>(rand() % static_cast<int>(Color::NB_COLORS));
  Color c4 = static_cast<Color>(rand() % static_cast<int>(Color::NB_COLORS));
  return Combination(c1, c2, c3, c4);
}
Combination::Combination(const Combination& src)
{
  for (int i = 0; i < CODE_LENGTH; i++)
    colors[i] = src.colors[i];
}

Combination::Combination(const LinkedList<Color>& colors)
{
  // Check if the size of the colors list is equal to CODE_LENGTH
  if (colors.size() != CODE_LENGTH)
  {
    throw std::invalid_argument("Combination must have exactly " + std::to_string(CODE_LENGTH) + " colors.");
  }
  for (int i = 0; i < CODE_LENGTH; i++)
    this->colors[i] = colors.get(i);
}

Combination::Combination(Color c1, Color c2, Color c3, Color c4)
{
  colors[0] = c1;
  colors[1] = c2;
  colors[2] = c3;
  colors[3] = c4;
}

Color Combination::getColorAt(unsigned int index) const
{
  return colors[index];
}

bool Combination::contains(Color color) const
{
  for (int i = 0; i < CODE_LENGTH; i++)
  {
    if (colors[i] == color)
      return true;
  }
  return false;
}

std::ostream& operator<<(std::ostream& os, const Combination& combination)
{
  os << "[";
  for (unsigned int i = 0; i < Combination::CODE_LENGTH; ++i)
  {
    os << combination.getColorAt(i);
    if (i < Combination::CODE_LENGTH - 1)
      os << "-";
  }
  os << "]";
  return os;
}

bool operator==(const Combination& lhs, const Combination& rhs)
{
  bool areEquals = true;

  for (unsigned int i = 0; i < Combination::CODE_LENGTH; ++i)
  {
    if (lhs.getColorAt(i) != rhs.getColorAt(i))
    {
      areEquals = false;
      break;
    }
  }

  return areEquals;
}
