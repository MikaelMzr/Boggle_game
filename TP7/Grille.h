/* Dos Santos Loïc */
/* Mikael Mezouar */
/* Création : 30-03-2021 */
/* Dernière modification : 03-04-2021 */
#ifndef __GRILLE__H__
#define __GRILLE__H__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "Dico.h"

/* Renvoie la taille entrez par l'utilisateur. */
int Ini_taille(void);

/* Fonction qui initialise la grille avec des '.' dans chaque case. */
void init_grille(int taille, char **grille);

/* Renvoie une lettre aléatoire plus de chance pour les lettres les plus utilisées. */
char lettre_aleatoire(void);

/* Fonction qui remplie la grille avec des lettre au hasard en minuscule quand la case est vide. */
void remplir_lettre_vide(int taille, char **tab);

#endif