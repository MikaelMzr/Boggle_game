/* Dos Santos Loïc */
/* Mikael Mezouar */
/* Création : 30-03-2021 */
/* Dernière modification : 03-04-2021 */
#include "Dico.h"

Tarbre alloue_Tnoeud(char lettre) {
	Tarbre newNoeud = (Tnoeud*)malloc(sizeof(Tnoeud));

	if(newNoeud != NULL) {
		newNoeud->lettre = lettre;
		newNoeud->fg = NULL;
		newNoeud->fils = NULL;
		newNoeud->fd = NULL;
	}
	return newNoeud;
}

void libere_Tarbre(Tarbre a) {
	if(a == NULL)
		return;

	libere_Tarbre(a->fg);
	libere_Tarbre(a->fils);
	libere_Tarbre(a->fd);
	free(a);
}

void affiche_chemin_aux(Tarbre a, char* buffer, int indice) {
	if(a == NULL)
		return;
	if(a->fg != NULL)
		affiche_chemin_aux(a->fg, buffer, indice);

	buffer[indice] = a->lettre;
	if(a->lettre == '\0')
		printf("%s\n", buffer);
	affiche_chemin_aux(a->fils, buffer, indice + 1);

	if(a->fd != NULL)
		affiche_chemin_aux(a->fd, buffer, indice);
}

void affiche_chemin(Tarbre a) {
	char buffer[512];
	affiche_chemin_aux(a, buffer, 0);
}

int rechercher(Tarbre tr, char mot[]){
    if(tr == NULL){
        return 0;
    }
    if (mot[0] == tr->lettre){
        if(mot[0]=='\0'){
            return 1;
        }
        else{
            return rechercher(tr->fils,mot+1);
        }
    }
    else{
        if(mot[0] < tr->lettre){
            return rechercher(tr->fg, mot);
        }
        else{
            return rechercher(tr->fd, mot);
        }
    }
}

int ajout_arbre(Tarbre *a, char* mot, int indice) {
	Tarbre tmp;

	if(*a != NULL) {
		if(indice == strlen(mot) - 1 && (*a)->fils != NULL && (*a)->lettre == mot[indice]) {
			tmp = (*a)->fils;
			(*a)->fils = alloue_Tnoeud('\0');
			(*a)->fils->fd = tmp;
			return 1;
		}
	}
	if(*a == NULL) {
		*a = alloue_Tnoeud(mot[indice]);
		if(indice == strlen(mot) - 1) {
			(*a)->fils = alloue_Tnoeud('\0');
			return 1;
		}
		return ajout_arbre(&((*a)->fils), mot, indice + 1);
	}

	if((*a)->lettre > mot[indice])
		return ajout_arbre(&((*a)->fg), mot, indice);
	else if((*a)->lettre < mot[indice])
		return ajout_arbre(&((*a)->fd), mot, indice);
	return ajout_arbre(&((*a)->fils), mot, indice + 1);
}

void lire_mots(Tarbre *a) {
	FILE *f;
	char mot[512];
	char lettre_fin;

	f = fopen("Mots", "r");
	if(f == NULL)
		fprintf(stderr, "fichier est NULL.\n");
	while(!(feof(f))) {
		fscanf(f, "%s", mot);
		lettre_fin = mot[strlen(mot) - 1];
		if(lettre_fin == ',' || lettre_fin == '.' || lettre_fin == '!' || lettre_fin == '?' || lettre_fin == ';')
			mot[strlen(mot) - 1] = '\0';
		if(!(rechercher(*a, mot)))
			ajout_arbre(a, mot, 0);
	}

	fclose(f);
}
