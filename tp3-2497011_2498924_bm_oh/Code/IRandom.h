#pragma once
#include <climits>
struct IRandom
{
  virtual int next(int min=INT_MIN, int max=INT_MAX) const = 0;
};