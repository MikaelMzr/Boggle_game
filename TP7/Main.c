/* Dos Santos Loïc */
/* Mikael Mezouar */
/* Création : 30-03-2021 */
/* Dernière modification : 05-04-2021 */
#include <assert.h>
#include <string.h>
#include "Regle.h"
#include "Graphique.h"
#include "Test.h"

int main(int argc, char const *argv[]) {
	int points, i, tour, touche, souris_x, souris_y, cmp_mot, taille, verif;
    int indice;
	char mot[64];
	int tab_x[64], tab_y[64];
	char **grille;
    Tarbre dico, mot_trouve;
	MEVENT ev;

	/* Tests. */
	if(argc == 2) {
		if(strcmp(argv[1], "-t") == 0) {
			test_global();
		}
		else {
			fprintf(stderr, "Erreur, arguments.\n");
		}
	}
	/* Programme. */
	else {
		cmp_mot = 0;
		points = 0;
		tour = 4;
		
	    indice=2;
	    mot_trouve = NULL;
	    dico = NULL;
	    /* Charge le dico. */
	    lire_mots(&dico);

	    /* Grille */
		taille = Ini_taille();
		grille = (char**)malloc(taille * sizeof(char *));
		assert(grille != NULL);
		for(i = 0; i < taille; i++) {
			grille[i] = (char*)malloc(taille * sizeof(char));
			assert(grille[i] != NULL);
		}
		init_grille(taille, grille);
		remplir_lettre_vide(taille, grille);

		/* Fenêtre */
		init_fenetre();
	    affiche_grille(4, grille);
	    refresh();

		while(tour != 0){
	        touche = getch();

	        /*quitter le jeu*/
	        if(touche == 'q')
	            break;

	        if(touche == 'a'){
	            cmp_mot--;
	            mot[cmp_mot] = 0;
	        }

	        /*récupération des clics*/
	        if(cmp_mot == 0) {
	        	if(touche == KEY_MOUSE && getmouse(&ev) == OK) {
					souris_x = ev.x;
		            souris_y = ev.y;
		            if(souris_x < 4 && souris_y < 4){
		                mot[cmp_mot] = grille[souris_y][souris_x];
						tab_x[cmp_mot] = souris_y;
						tab_y[cmp_mot] = souris_x;
		                cmp_mot++;
		                mvprintw(LINES - 1, COLS - 30 + 13, "%s", mot);
		                refresh();
		            }
	        	}
	        }
	        else {
	        	if(touche == KEY_MOUSE && getmouse(&ev) == OK) {
	        		souris_x = ev.x;
	            	souris_y = ev.y;
	            	if(souris_x < 4 && souris_y < 4){
		                mot[cmp_mot] = grille[souris_y][souris_x];
						tab_x[cmp_mot] = souris_y;
						tab_y[cmp_mot] = souris_x;
		                cmp_mot++;
		                mvprintw(LINES - 1, COLS - 30 + 13, "%s", mot);
		                refresh();

						if(indice != 0) {
							/*mot invalide*/
							if (coup_legal(4, grille, souris_x, souris_y, cmp_mot-1 , tab_x, tab_y) == 0){
								indice = 0;
							}

							/*mot valide*/ 
							if (coup_legal(4, grille, souris_x, souris_y, cmp_mot-1 , tab_x, tab_y) == 1){
								indice = 1;
							}
						}
	            	}
	        	}
	        }

	        if(touche == 10){
				if (indice == 2){
					mvprintw(15, 15, "Erreur saisie !");
					refresh();
					sleep(1);
					tour--;
					for(i = 0; i < cmp_mot; i++)
	        			mot[i] = '\0';
	        		cmp_mot = 0;
				}

				if (indice == 0){
					mvprintw(15, 15, "Mot non valide !");
					refresh();
					sleep(1);
					tour--;
					for(i = 0; i < cmp_mot; i++)
	        			mot[i] = '\0';
	        		cmp_mot = 0;
	    			indice=2;
				}

				if (indice == 1){
					verif = verif_mot(4, &indice, /*Tarbre*/ dico, /*Tarbre*/ &mot_trouve, mot, &points , tab_x, tab_y);
					if (verif == 1){
						mvprintw(15, 15, "saisie valide !");
						refresh();
						sleep(1);
						tour--;
						for(i = 0; i < cmp_mot; i++)
	        				mot[i] = '\0';
	        			cmp_mot = 0;
					}
					else{
						mvprintw(15, 15, "saisie invalide !");
						refresh();
						sleep(1);
						tour--;
						for(i = 0; i < cmp_mot; i++)
	        				mot[i] = '\0';
	        			cmp_mot = 0;
					}
				}
	        	efface();
	        }
	        message_score_tour(points, tour, mot);
	    }

	    fin_fenetre(points);

		for(i = 0; i < taille; i++) {
			free(grille[i]);
		}
	    free(grille);

	    libere_Tarbre(dico);
	    libere_Tarbre(mot_trouve);
	}

    return 0;
}