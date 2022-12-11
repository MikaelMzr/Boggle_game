/* Dos Santos Loïc */
/* Mikael Mezouar */
/* Création : 30-03-2021 */
/* Dernière modification : 03-04-2021 */
#ifndef __REGLE__H__
#define __REGLE__H__
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Saisie.h"

/* Parcours la liste de coordonnée et renvoie 0 si les coordonnées n'existe pas deja
 * et donc voir si la lettre n'a pas été déjà utilisé,
 * renvoie 1 si la coordonnée est déjà présente. */
int lettre_presente(int taille, int tab_x[], int tab_y[], int x, int y);

/* Fonction qui vérifie si le coup suivant est légal par rapport à l'ancien.
 * Renvoie 1 si le coup est légal,
 * renvoie 0 sinon. */
int coup_legal(int taille, char **grille, int x_fin, int y_fin, int i, int tab_x[], int tab_y[]);

/* Vérifie si un mot existe dans le dictionnaire et n'a pas déjà été rentrée,
 * Renvoie 1 s'il existe et n'a pas déjà été joué,
 * renvoie 0 sinon. */
int verif_mot(int taille, int *indice, Tarbre dico, Tarbre *mot_trouve, char *mot, int *score ,int tab_x[], int tab_y[]);

#endif
