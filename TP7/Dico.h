/* Dos Santos Loïc */
/* Mikael Mezouar */
/* Création : 30-03-2021 */
/* Dernière modification : 03-04-2021 */
#ifndef __DICO__H__
#define __DICO__H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct noeud {
	char lettre;
	struct noeud *fg;
	struct noeud *fd;
	struct noeud *fils;
} Tnoeud, *Tarbre;

/* Alloue et renvoie un Tnoeud. */
Tarbre alloue_Tnoeud(char lettre);

/* Libère tout le Tarbre a. */
void libere_Tarbre(Tarbre a);

/* Fonction auxiliaire pour parcourir l'arbre. */
void affiche_chemin_aux(Tarbre a, char* buffer, int indice);

/* Affiche les mots de l'arbre. */
void affiche_chemin(Tarbre a);

/* Recherche un mot dans l'arbre. */
int rechercher(Tarbre tr, char mot[]);

/* Ajoute un mot dans l'arbre. */
int ajout_arbre(Tarbre *a, char* mot, int indice);

/* Lis le fichier Mots et écrit tous les mots dans le Tarbre a. */
void lire_mots(Tarbre *a);

#endif