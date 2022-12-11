/* Dos Santos Loïc */
/* Mikael Mezouar */
/* Création : 30-03-2021 */
#ifndef __TEST__H__
#define __TEST__H__
#include "Grille.h"
#include "Dico.h"

/* Teste si la grille a bien été initialisée.
 * Renvoie 1 si tous les éléments de la grille sont '.',
 * Renvoie 0 sinon. */
int test_init_grille();

/* Teste si le mot est présent dans le Tarbre.
 * On test sur un arbre vide, avec un arbre qui
 * ne contient pas le mot et un qui le contient.
 * Renvoie 1 si tous les tests réussissent,
 * Renvoie 0 sinon. */
int test_rechercher();

/* Lance toutes les fonctions de tests.
 * Si une renvoie 0 test_global renvoie 0,
 * Si elles renvoient toutes 1 test_global renvoie 1. */
int test_global();

#endif