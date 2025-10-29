
#include "stdafx.h"                          
#include "CombinationTree.h"                  
#include "CombinationTreeNode.h"              
#include "IRandom.h"                          
#include "Combination.h"                     
#include <iostream>                           







// fonctions utilitaires recursives 



       // fonction recursive pour construire tout l arbre de combinaisons 

static void buildAll ( CombinationTreeNode* node, int depth )

{
// prof
// Ne placez pas de code sur la m�me ligne qu'un if
// QC-1
  if (depth == Combination::CODE_LENGTH) return;                 // si profondeur egale a la taille du code on arrete


  const int nbColors = static_cast<int>(Color::NB_COLORS);         // nombre de couleurs


  for (int c = 0; c < nbColors; ++c)

  {

    CombinationTreeNode* child = new CombinationTreeNode ();  // creation d un nouveau noeud enfant

    child->setColor ( static_cast<Color>(c) );                 // on assigne une couleur au noeud enfant

    node->getChildren ().add ( child );                         // on rattache l enfant au noeud courant

    buildAll ( child, depth + 1 );                            // appel recursif pour descendre

  }

}






// fonction recursive pour afficher toutes les combinaisons stockees dans l arbre  
// prof
// Attention au nommage de la fonction. Ça prend un verbe d'action et un complément.
// SP-1
static void diQClayDFS ( std::ostream& os,

                         const CombinationTreeNode* node,

                         LinkedList<Color>& accumulation,

                         int depth )

{
// prof
// A plein d'endroits vous sautez des lignes pour rien
// Évitez cela
// QC-1
  if (depth == Combination::CODE_LENGTH)          // si profondeur egale a taille du code

  {
    Combination combination ( accumulation );             // on construit une combinaison a partir de acc

    // affiche une combinaison et un saut de ligne
    os << combination << std::endl;
    // on retourne la valeur attendue ici
    return;

  }
  // on recupere la liste des enfants du noeud
  const LinkedList<CombinationTreeNode*>& children = node->getChildren ();
  // boucle for on parcourt des elements dans l ordre
  for (unsigned int i = 0; i < children.size (); ++i)

  {
    CombinationTreeNode* child = children.get ( i );           // recuperation d un enfant

    // on ajoute cette couleur dans le chemin temporaire accumulation
    accumulation.add ( child->getColor () );

    diQClayDFS ( os, child, accumulation, depth + 1 );       // appel recursif
    LinkedList<Color> temporary;
    // liste temporaire pour supprimer le dernier element
// prof
// Je ne comprends pas pourquoi vous faites tout ça 
// CIC-1
// boucle for on parcourt des elements dans l ordre
    for (unsigned int k = 0; k + 1 < accumulation.size (); ++k)

      temporary.add ( accumulation.get ( k ) );

    accumulation.clear ();                                 // on vide la liste

    // boucle for on parcourt des elements dans l ordre
    for (unsigned int k = 0; k < temporary.size (); ++k)
      // on ajoute cette couleur dans le chemin temporaire accumulation

      accumulation.add ( temporary.get ( k ) );                     // on recopie sans le dernier

  }

}









// fonction qui supprime recursivement un sous arbre

static void deleteSubtree ( CombinationTreeNode* node )

{
// prof
// Ne placez pas de code sur la m�me ligne qu'un if
// QC-1
  if (!node) return;                                      // si pointeur nul on sort

  delete node;                                            // suppression du noeud et de ses enfants (via destructeur)

}






// fonction utilitaire pour retirer le dernier element d une liste de couleurs 

static void popBackColor ( LinkedList<Color>& list )

{
  const int n = list.size ();
// prof
// Ne placez pas de code sur la m�me ligne qu'un if
// QC-1
  if (n == 0) return;                   // si liste vide rien a faire
  LinkedList<Color> temporary;
  // boucle for on parcourt des elements dans l ordre

  for (unsigned int i = 0; i + 1 < n; ++i) // copie sauf dernier
    temporary.add ( list.get ( i ) );
  list.clear ();
  // boucle for on parcourt des elements dans l ordre
  for (unsigned int i = 0; i < temporary.size (); ++i)
    list.add ( temporary.get ( i ) );

}










// fonction recursive pour choisir une combinaison selon un index   

// prof
// Beaucoup trop de lignes sautées
// QC-1
static bool pickByIndex ( const CombinationTreeNode* node,

                          int depth,

// prof
// Pourquoi recevez-vous tout par référence?
// SP-1
                          int& index,


                          LinkedList<Color>& accumulation,

                          Combination& out )

{


  if (depth == Combination::CODE_LENGTH) // si on est sur une feuille

  {
    // construit un objet combination a partir des couleurs de acc
    out = Combination ( accumulation );
    // on retourne la valeur attendue ici
    return true;

  }
  // on recupere la liste des enfants du noeud

  const LinkedList<CombinationTreeNode*>& children = node->getChildren ();

  // boucle for on parcourt des elements dans l ordre
  for (int i = 0; i < children.size (); ++i)

  {
    const CombinationTreeNode* child = children.get ( i );

    const int subLeaves = child->size ();        // nombre de feuilles sous cet enfant

    if (index < subLeaves)                        // si l index correQCond a ce sous arbre

    {
      // on ajoute cette couleur dans le chemin temporaire accumulation
      accumulation.add ( child->getColor () );
      const bool ok = pickByIndex ( child, depth + 1, index, accumulation, out );

      // on enleve la derniere couleur ajoutee dans acc pour remonter
      popBackColor ( accumulation );
      // on retourne la valeur attendue ici
      return ok;

    }
    index -= subLeaves;                      // sinon on decremente et continue

  }

  return false;

}






// fonction qui compare deux tableaux d indicateurs 

// prof
// Attention au nommage de la fonction. Ça prend un verbe d'action et un complément.
// SP-1
static bool sameIndicators ( Color a[], Color b[] )

{
  // boucle for on parcourt des elements dans l ordre
  for (int i = 0; i < Combination::CODE_LENGTH; ++i)

    if (a[i] != b[i]) return false;                // si difference retourne faux

  return true;                                         // sinon identiques

}







// calcule les indicateurs noirs blancs pour comparer deux combinaisons 

// prof
// C'était déjà fourni. Pas besoin de le coder à nouveau
static void computeIndicators ( const Combination& guess,

                                const Combination& secretCandidate,

                                Color out[Combination::CODE_LENGTH] )

{
  // boucle for on parcourt des elements dans l ordre
  for (int i = 0; i < Combination::CODE_LENGTH; ++i)

  {

    if (guess.getColorAt ( i ) == secretCandidate.getColorAt ( i ))
      out[i] = Color::BLACK;                                   // bonne couleur et bonne position
    else if (secretCandidate.contains ( guess.getColorAt ( i ) ))
      out[i] = Color::WHITE;                                  // bonne couleur mauvaise position
    else
      // couleur QCeciale pour dire aucune couleur reelle

      out[i] = Color::NB_COLORS;                    // couleur absente

  }

}






// fonction recursive pour elaguer l arbre selon les indicateurs donnes 


static bool pruneByIndicators ( CombinationTreeNode* node,

                                int depth,

                                LinkedList<Color>& accumulation,

                                const Combination& guess,

                                Color indicators[Combination::CODE_LENGTH] )

{

  if (depth == Combination::CODE_LENGTH)

  {
    Combination candidate ( accumulation );
    Color indicatorsCalculated[Combination::CODE_LENGTH];
    // on calcule les indicateurs noir et blanc
    computeIndicators ( guess, candidate, indicatorsCalculated );
    // on retourne la valeur attendue ici

    return sameIndicators ( indicatorsCalculated, indicators );           // verifie si compatible

  }

  CombinationTreeNode* toKeep[16];                     // tableau temporaire pour enfants a garder

  unsigned int keepCount = 0;
  // on recupere la liste des enfants du noeud
  LinkedList<CombinationTreeNode*>& children = node->getChildren ();

  const unsigned int childCount = children.size ();
  // boucle for on parcourt des elements dans l ordre
  for (unsigned int i = 0; i < childCount; ++i)

  {
    CombinationTreeNode* child = children.get ( i );
    // on ajoute cette couleur dans le chemin temporaire accumulation
    accumulation.add ( child->getColor () );

    const bool keep = pruneByIndicators ( child, depth + 1, accumulation, guess, indicators );
    // on enleve la derniere couleur ajoutee dans acc pour remonter
    popBackColor ( accumulation );
// prof
// Ne placez pas de code sur la m�me ligne qu'un if
    if (keep) toKeep[keepCount++] = child;             // garder enfant valide

    // supprime recursivement un sous arbre
    else      deleteSubtree ( child );

  }
  // on vide la liste des enfants on va rattacher seulement ceux qui reste
  children.clear ();

  // boucle for on parcourt des elements dans l ordre
  for (unsigned int i = 0; i < keepCount; ++i)

    children.add ( toKeep[i] );               // on rattache les gardes

  return (keepCount > 0);                    // retourne vrai si au moins un reste

}







//  mandat commun









CombinationTree::CombinationTree ()

{
  treeRoot = new CombinationTreeNode ();

  treeRoot->setColor ( Color::NB_COLORS );

}








unsigned int CombinationTree::size () const

{

  if (treeRoot == nullptr || treeRoot->getChildren ().isEmpty ())

    return 0;

  return treeRoot->size ();

}






// destructeur  

CombinationTree::~CombinationTree ()

{

  deleteSubtree ( treeRoot );      // supprime recursivement l arbre

  treeRoot = nullptr;           // reinitialisation du pointeur racine




  // PROF
 // A REMPLACER PAR VOTRE CODE
// LibProfTP3::CTDestructor(treeRoot);
}






// genere toutes les combinaisons possibles  

void CombinationTree::generateAllCombinations ()

{
  buildAll ( treeRoot, 0 );                          // appel de la fonction recursive



  // PROF
  // A REMPLACER PAR VOTRE CODE
  //LibProfTP3::CTGenerateAllCombinations(treeRoot);
}






// operateur sert pour montrer les combinaison 


std::ostream& operator<<( std::ostream& os, const CombinationTree& combinationTree )

{

  if (combinationTree.treeRoot == nullptr ||
       // on recupere la liste des enfants du noeud
       combinationTree.treeRoot->getChildren ().isEmpty ())
    // on retourne la valeur attendue ici
    return os;
  LinkedList<Color> accumulation;                               // liste temporaire pour stocker chemin

  diQClayDFS ( os, combinationTree.treeRoot, accumulation, 0 ); // parcours recursif





  // PROF
  // A REMPLACER PAR VOTRE CODE
  // LibProfTP3::CTDiQClay(os, combinationTree.treeRoot);
  return os;

}











// mandat 1  retourne une combinaison choisie aleatoirement      (MAHRANE)

Combination CombinationTree::getRandomCombination ( const IRandom& randomGenerator ) const

{
  const  int totalLeaves = size ();          // nombre de feuilles valides
  // prof
  // Ne place pas de code sur la m�me ligne qu'un if
  // QC-1
  if (totalLeaves == 0) return Combination ();

  const int idx = randomGenerator.next ( 0, static_cast<int>(totalLeaves) ); // index aleatoire

  int index = static_cast<int>(idx);


  LinkedList<Color> accumulation;

  Combination out;

  pickByIndex ( treeRoot, 0, index, accumulation, out );            // on cherche la combinaison correQCondante

  return out;





  // PROF
  // A REMPLACER PAR VOTRE CODE
  //LibProfTP3::CTGetRandomCombination(treeRoot, randomGenerator);

}










// mandat 2 supprime les combinaisons incompatibles avec les indicateurs  (HAAAAMED)

void CombinationTree::removeCombinations ( Color indicators[Combination::CODE_LENGTH],

                                           const Combination& combination )

{

  if (treeRoot == nullptr || treeRoot->getChildren ().isEmpty ())

    return;                                                   // si arbre vide rien a faire
  LinkedList<Color> accumulation;
  const bool keepRoot = pruneByIndicators ( treeRoot, 0, accumulation, combination, indicators );

  if (!keepRoot)                                              // si aucun noeud valide reste

  {
    // supprime recursivement un sous arbre
    deleteSubtree ( treeRoot );

    treeRoot = new CombinationTreeNode (); // on recree une racine vide

    treeRoot->setColor ( Color::NB_COLORS );  // on fixe la couleur pour ce noeud

  }



  // PROF
  // A REMPLACER PAR VOTRE CODE
  //LibProfTP3::CTRemoveCombinations(indicators, combination, treeRoot);
}