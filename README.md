TP3 - Algorithmique avancee (EFCS - Mastermind)
===============================================

Cours : 420-W31-SF - Algorithmique avancee  
Cegep de Sainte-Foy  

---------------------------------------------------------

Objectif du projet
------------------
Ce projet consiste a creer un algorithme capable de trouver la solution d'un jeu de type Mastermind.  
Le travail permet de mettre en pratique la programmation recursive, la manipulation de structures de donnees personnalisees (liste chainee et arbre de combinaisons), et la realisation de tests unitaires pour valider la logique.

---------------------------------------------------------

Partie 1 - Individuelle : Liste chainee modele
----------------------------------------------
- Coder une classe **LinkedList** representant une liste chainee generique.  
- Produire les tests unitaires complets de la classe **LinkedList**.  
- Chaque test unitaire doit referencer, en commentaire, le numero du cas de test decrit dans le document Word **DescriptionsTests.docx**.  
- Les tests doivent couvrir toutes les operations : insertion, suppression, recherche, parcours, destructeur, etc.  
- Aucun algorithme ou structure de la STL (ex. vector, list, sort) ne doit etre utilise.  
- Le code et les tests unitaires doivent etre remis dans une premiere remise sur LEA.

---------------------------------------------------------

Partie 2 - En equipe : Algorithme de resolution du jeu
------------------------------------------------------
Cette partie consiste a implementer un algorithme qui determine la combinaison secrete dans le jeu Mastermind, a l'aide d'un **arbre de combinaisons**.  
Le projet de base contient deja un jeu fonctionnel, mais sans le code de la solution.  
Les methodes a completer se trouvent dans **CombinationTree.cpp**.

### Mandat commun
Les deux coequipiers doivent coder :
- Le **destructeur** de la classe CombinationTree pour liberer correctement la memoire.  
- L'**operateur <<** pour afficher toutes les combinaisons de l'arbre.  
- La methode **generateAllCombinations**, qui genere recursivement toutes les combinaisons possibles de couleurs.

### Mandat 1
- Coder la methode **getRandomCombination**, qui retourne une combinaison choisie aleatoirement a partir de l'arbre.  
- Utiliser un generateur aleatoire fourni pour choisir parmi les combinaisons numerotees de 0 a N-1.

### Mandat 2
- Coder la methode **removeCombinations**, qui elimine de l'arbre toutes les combinaisons impossibles selon les resultats d'une tentative.  
- Utiliser le tableau d'indicateurs recu en parametre, contenant les valeurs :
  - **BLACK** : couleur correcte et bien placee.  
  - **WHITE** : couleur presente mais mal placee.  
  - **NB_COLORS** : couleur absente de la combinaison secrete.  
- Le code doit supprimer recursivement les branches de l'arbre qui ne respectent plus les criteres.

---------------------------------------------------------

Contraintes et remarques
------------------------
- Toutes les solutions doivent etre **recursives**.  
- Aucun algorithme de la STL n'est autorise.  
- Le destructeur doit assurer l'absence de fuite memoire.  
- Chaque methode doit etre independante et testee individuellement.  
- Les signatures des methodes dans CombinationTree.h ne doivent pas etre modifiees.  
- L'IA peut etre utilisee uniquement pour la generation des tests unitaires.  
- Toute autre utilisation constitue un acte de plagiat.

---------------------------------------------------------

Tests unitaires
---------------
- Produire des tests unitaires pour la classe LinkedList et les methodes de CombinationTree.  
- Identifier clairement les cas de test dans le document Word **DescriptionsTests.docx**.  
- Chaque test dans le code doit mentionner le numero du cas correspondant en commentaire.  
- La correction tient compte :
  - de la pertinence des cas identifies,  
  - de la couverture du code par les tests,  
  - et du bon fonctionnement des tests du professeur.

---------------------------------------------------------

Technologies utilisees
----------------------
- C++  
- Programmation recursive  
- Structures de donnees : liste chainee et arbre  
- Algorithmes de recherche et d'exploration  
- Tests unitaires (C++ ou framework libre)  
- IDE : Visual Studio / VS Code  

---------------------------------------------------------

Auteur
------
Cherif Ouattara- Etudiant AEC Programmation, bases de donnees et serveurs  
Cegep de Sainte-Foy  
GitHub : https://github.com/BoOm00001  
LinkedIn : https://www.linkedin.com/in/cherif-ouattara/
