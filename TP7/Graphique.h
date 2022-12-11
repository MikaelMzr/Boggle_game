/* Dos Santos Loïc */
/* Mikael Mezouar */
/* Création : 05-04-2021 */
#ifndef __GRAPHIQUE__H__
#define __GRAPHIQUE__H__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include "Grille.h"
#define N 4

/* Initialise la fenêtre. */
void init_fenetre(void);

/* Ferme la fenêtre. */
void fin_fenetre(int score);

/* Affiche les lettres de la grille. */
void affiche_grille(int taille, char **grille);

/* Affiche le score. */
void message_score_tour(int points, int tour, char mot[]);

/* Efface la fennêtre. */
void efface(void);

#endif