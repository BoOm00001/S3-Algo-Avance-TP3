#pragma once
#include "Color.h"
#include "LinkedList.h"
class Combination
{
public:
  static const unsigned int CODE_LENGTH = 4;
  static Combination getRandomCombination(); 
  Combination()=default;
  Combination(const Combination& src);
  Combination(const LinkedList<Color>& colors);
  Combination(Color c1, Color c2, Color c3, Color c4);
  ~Combination()=default;

  Color getColorAt(unsigned int index) const;
  bool contains(Color color) const;
  
private:
  Color colors[CODE_LENGTH];
  
  friend std::ostream& operator<<(std::ostream& os, const Combination& combination);
  friend bool operator==(const Combination& lhs, const Combination& rhs);
};

