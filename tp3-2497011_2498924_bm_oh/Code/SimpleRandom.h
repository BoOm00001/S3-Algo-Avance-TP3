#pragma once
#include "IRandom.h"
class SimpleRandom :
    public IRandom
{
  // Hérité via IRandom
  int next(int min, int max) const override;
};

