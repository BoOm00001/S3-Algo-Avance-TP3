#pragma once
#include "LinkedList.h"
#include "Combination.h"
#include "color.h";


class CombinationTreeNode;
struct IRandom;
class CombinationTree
{
public:
	CombinationTree();

	unsigned int size() const;

	
	// Méthode à coder
	// Mandat commun
	~CombinationTree();
	friend std::ostream& operator<<(std::ostream& os, const CombinationTree& combinationTree);
	void generateAllCombinations();

	// Mandat 1
	Combination getRandomCombination(const IRandom& randomGenerator) const;

	// Mandat 2
	void removeCombinations(Color indicators[Combination::CODE_LENGTH], const Combination& combination);
	



private:
	CombinationTreeNode* treeRoot;

	friend class LibProfTP3;
};
