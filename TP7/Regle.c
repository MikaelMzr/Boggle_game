/* Dos Santos Loïc */
/* Mikael Mezouar */
/* Création : 30-03-2021 */
/* Dernière modification : 03-04-2021 */
#include "Regle.h"

int lettre_presente(int taille, int tab_x[], int tab_y[], int x, int y){
    /*Parcours la liste de coordonnée et renvoi 0 si les coordonnées n'existe pas deja et donc voir si la lettre n'a pas été deja utiliser */
    int i;
    for(i=0;i<taille;i++){
        if(tab_x[i] == y && tab_y[i] == x){
            return 0;
        }
    }
    return 1;
}

int coup_legal(int taille, char **grille, int x_fin, int y_fin, int i, int tab_x[], int tab_y[]){
    /*fonction qui vérifie si le coup suivant est legal par rapport a l'ancien*/
    assert(taille == 4);
    if (lettre_presente(i, tab_x, tab_y, x_fin, y_fin) == 1 && 
            tab_x[i-1]-1 == tab_x[i] && tab_y[i-1]-1 == tab_y[i]){
        return 1;
    }
    if (lettre_presente(i, tab_x, tab_y, x_fin, y_fin) == 1 && 
            tab_x[i-1]-1 == tab_x[i] && tab_y[i-1] == tab_y[i]){
        return 1;
    }
    if (lettre_presente(i, tab_x, tab_y, x_fin, y_fin) == 1 && 
            tab_x[i-1]-1 == tab_x[i] && tab_y[i-1]+1 == tab_y[i]){
        return 1;
    }
    if (lettre_presente(i, tab_x, tab_y, x_fin, y_fin) == 1 && 
            tab_x[i-1] == tab_x[i] && tab_y[i-1]+1 == tab_y[i]){
        return 1;
    }
    if (lettre_presente(i, tab_x, tab_y, x_fin, y_fin) == 1 && 
            tab_x[i-1]+1 == tab_x[i] && tab_y[i-1]+1 == tab_y[i]){
        return 1;
    }
    if (lettre_presente(i, tab_x, tab_y, x_fin, y_fin) == 1 && 
            tab_x[i-1]+1 == tab_x[i] && tab_y[i-1] == tab_y[i]){
        return 1;
    }
    if (lettre_presente(i, tab_x, tab_y, x_fin, y_fin) == 1 && 
            tab_x[i-1]+1 == tab_x[i] && tab_y[i-1]-1 == tab_y[i]){
        return 1;
    }
    if (lettre_presente(i, tab_x, tab_y, x_fin, y_fin) == 1 && 
            tab_x[i-1] == tab_x[i] && tab_y[i-1]-1 == tab_y[i]){
        return 1;
    }

    return 0;
}

int verif_mot(int taille, int *indice, Tarbre dico, Tarbre *mot_trouve, char *mot, int *score ,int tab_x[], int tab_y[]){
    int t;
    assert(taille == 4);
    if(*indice == 1 && rechercher(dico, mot) == 1 && rechercher(*mot_trouve, mot) == 0){
        /* 1 alors on ajoute le mot à une liste des mots trouvé puis on affiche que c'est trouvé + augmentation du score*/
        t = strlen(mot);
        *score = *score + pow(2, (t-3));
        /*ajouter mot dans l'arbre mot_trouve */
        ajout_arbre(mot_trouve, mot, 0);
        
        init_tab_coord(taille, tab_x, tab_y);
        *indice = 2;
        return 1;
    }
    else{
        init_tab_coord(taille, tab_x, tab_y);
        *indice = 2;
        return 0;
    }
}