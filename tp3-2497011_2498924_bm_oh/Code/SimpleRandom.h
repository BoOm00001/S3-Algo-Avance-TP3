#pragma once
#include "IRandom.h"
class SimpleRandom :
    public IRandom
{
  // H�rit� via IRandom
  int next(int min, int max) const override;
};

