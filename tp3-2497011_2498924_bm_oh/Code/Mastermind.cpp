#include "stdafx.h"
#include "Mastermind.h"
#include "SimpleRandom.h"

void Mastermind::playGame()
{
  // Initialiser la combinaison gagnante
  secretCode = Combination::getRandomCombination();
  std::cout << "Secret code is:\t\t" << secretCode << std::endl << std::endl;

  // Construire l'arbre de jeu avec toutes les possibilités
  combinationTree.generateAllCombinations();
  std::cout << combinationTree << std::endl;
  Combination actualCombinaison;
  unsigned int nbIterations = 0;
  Color indicators[Combination::CODE_LENGTH];
  do
  {
    std::cout << "Iterations # " << nbIterations++ << "\t(Tree size : " << combinationTree.size() << ")" << std::endl;

    // A chaque tour on génère une combinaison au hasard
    actualCombinaison = combinationTree.getRandomCombination(randomGenerator);
    std::cout << "Actual combination is:\t" << actualCombinaison << std::endl << std::endl;
    // Cette combinaison est testée contre la combinaison secrète
    // Le tableau indicators est rempli avec les résultats: 
    // BLACK = bien placé, WHITE = mal placé, NB_COLORS = pas dans la combinaison
    evaluateGuess(actualCombinaison, indicators);

    // On enlève ensuite toutes les combinaisons qui ne correspondent pas aux résultats
    combinationTree.removeCombinations(indicators, actualCombinaison);
  } while (actualCombinaison != secretCode);
  // On a trouvé la combinaison secrète
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
