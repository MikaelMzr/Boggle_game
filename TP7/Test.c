#include "Test.h"

int test_init_grille() {
	int i, j;
	int taille_1, taille_2;
	char **grille_1, **grille_2;

	taille_1 = 2;

	grille_1 = (char**)malloc(taille_1 * sizeof(char *));
	for(i = 0; i < taille_1; i++) {
		grille_1[i] = (char*)malloc(taille_1 * sizeof(char));
	}

	taille_2 = 8;

	grille_2 = (char**)malloc(taille_2 * sizeof(char *));
	for(i = 0; i < taille_2; i++) {
		grille_2[i] = (char*)malloc(taille_2 * sizeof(char));
	}

	for(i = 0; i < taille_1; i++) {
		printf("\t");
		for(j = 0; j < taille_1; j++) {
			if(grille_1[i][j] != '.')
				return 0;
			printf("[%c]", grille_1[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for(i = 0; i < taille_2; i++) {
		printf("\t");
		for(j = 0; j < taille_2; j++) {
			if(grille_2[i][j] != '.')
				return 0;
			printf("[%c]", grille_2[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return 1;
}

int test_rechercher() {
	Tarbre a, b, c;

	a = NULL;

	b = NULL;
	ajout_arbre(&b, "recherche", 0);

	c = NULL;
	ajout_arbre(&c, "test", 0);

	if(rechercher(a, "test") == 1)
		return 0;
	else
		printf("\t\"test\" non trouvé dans l'arbre vide.\n");
	if(rechercher(b, "test") == 1)
		return 0;
	else
		printf("\t\"test\" non trouvé dans l'arbre qui ne contient pas \"test\".\n");
	if(rechercher(c, "test") == 0)
		return 0;
	else
		printf("\t\"test\" non trouvé dans l'arbre qui contient \"test\".\n");

	return 1;
}

int test_global() {
	int valeur_retour, valeur_retour_finale;

	valeur_retour_finale = 1;

	printf("Test de init_grille:\n");
	valeur_retour = test_init_grille();
	printf("Resultat test_init_grille: %d\n", valeur_retour);
	valeur_retour_finale = valeur_retour_finale && valeur_retour;

	printf("\nTest de rechercher:\n");
	valeur_retour = test_rechercher();
	printf("Resultat test_rechercher: %d\n", valeur_retour);
	valeur_retour_finale = valeur_retour_finale && valeur_retour;

	return valeur_retour_finale;
}