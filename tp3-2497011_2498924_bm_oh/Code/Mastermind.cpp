#include "stdafx.h"
#include "Mastermind.h"
#include "SimpleRandom.h"

void Mastermind::playGame()
{
  // Initialiser la combinaison gagnante
  secretCode = Combination::getRandomCombination();
  std::cout << "Secret code is:\t\t" << secretCode << std::endl << std::endl;

  // Construire l'arbre de jeu avec toutes les possibilit�s
  combinationTree.generateAllCombinations();
  std::cout << combinationTree << std::endl;
  Combination actualCombinaison;
  unsigned int nbIterations = 0;
  Color indicators[Combination::CODE_LENGTH];
  do
  {
    std::cout << "Iterations # " << nbIterations++ << "\t(Tree size : " << combinationTree.size() << ")" << std::endl;

    // A chaque tour on g�n�re une combinaison au hasard
    actualCombinaison = combinationTree.getRandomCombination(randomGenerator);
    std::cout << "Actual combination is:\t" << actualCombinaison << std::endl << std::endl;
    // Cette combinaison est test�e contre la combinaison secr�te
    // Le tableau indicators est rempli avec les r�sultats: 
    // BLACK = bien plac�, WHITE = mal plac�, NB_COLORS = pas dans la combinaison
    evaluateGuess(actualCombinaison, indicators);

    // On enl�ve ensuite toutes les combinaisons qui ne correspondent pas aux r�sultats
    combinationTree.removeCombinations(indicators, actualCombinaison);
  } while (actualCombinaison != secretCode);
  // On a trouv� la combinaison secr�te
  std::cout << "Secret code found in " << nbIterations << " iterations" << std::endl;
}

void Mastermind::evaluateGuess(const Combination& guess, Color indicators[Combination::CODE_LENGTH])
{
  for (unsigned int i = 0; i < Combination::CODE_LENGTH; i++)
  {
    if (guess.getColorAt(i) == secretCode.getColorAt(i))
      indicators[i] = Color::BLACK;
    else if (secretCode.contains(guess.getColorAt(i)))
      indicators[i] = Color::WHITE;
    else
      indicators[i] = Color::NB_COLORS;
  }
}
