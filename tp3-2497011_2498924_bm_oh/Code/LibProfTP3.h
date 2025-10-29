#pragma once
class CombinationTreeNode;
#include "Combination.h"
struct IRandom;
class LibProfTP3
{
public:
  static void CTDestructor(CombinationTreeNode*& tree);
  static void CTGenerateAllCombinations(CombinationTreeNode* treeRoot);
  static Combination CTGetRandomCombination(CombinationTreeNode* treeRoot, const IRandom& randomGenerator);
  static void CTRemoveCombinations(Color indicators[Combination::CODE_LENGTH], const Combination& combination, CombinationTreeNode* treeRoot);
  static void CTDisplay(std::ostream& os, CombinationTreeNode* current);
};

