#pragma once
#include "Combination.h"
#include "Color.h"
#include "CombinationTree.h"
#include "SimpleRandom.h"
class Mastermind
{
public:
  Mastermind() = default;
  void playGame();
private:
  void evaluateGuess(const Combination& guess, Color indicators[Combination::CODE_LENGTH]);
  Combination secretCode;
  CombinationTree combinationTree;
  SimpleRandom randomGenerator;
};

#ifdef _DEBUG
#pragma comment(lib, "LibProfTP3_d.lib")
#elif defined(NDEBUG)
#pragma comment(lib, "LibProfTP3.lib")
#endif