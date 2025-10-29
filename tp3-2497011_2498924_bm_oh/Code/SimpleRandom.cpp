#include "stdafx.h"
#include "SimpleRandom.h"
#include <cstdlib>



int SimpleRandom::next(int min, int max) const
{
  float random = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
  return static_cast<int>(min + random * (max - min));
}
