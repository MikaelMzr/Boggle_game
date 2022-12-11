/* Dos Santos Loïc */
/* Mikael Mezouar */
/* Création : 30-03-2021 */
/* Dernière modification : 03-04-2021 */
#include "Grille.h"
#define N 4


int Ini_taille(void){
    /* fonction qui initialise la taille de la grille et la renvoie */
    int taille;
    printf("saisir taille de la grille");
    scanf("%d",&taille);
    while(taille>20 || taille<1){
    printf("Erreur , veuillez saisir une taille valide de la grille");
    scanf("%d",&taille);
    }
    return taille; 
}

void init_grille(int taille, char **grille){
    /*fonction qui initialise la grille avec des '.' dans chaque case*/
    int i,j;
    for(i=0;i<taille;i++){
        for(j=0;j<taille;j++){
            grille[i][j]='.';
        }
    }
}

char lettre_aleatoire(void){
    int cas;
    int i;
    int alea;

    char tab0[]={'e'};
    char tab1[]={'t'};
    char tab2[]={'a','i','n','o','s'};
    char tab3[]={'r'};
    char tab4[]={'h'};
    char tab5[]={'d', 'l'};
    char tab6[]={'c', 'm', 'u'};
    char tab7[]={'b', 'f', 'g', 'p', 'w', 'y'};
    char tab8[]={'j', 'k', 'q', 'v', 'x', 'z'};

    alea= rand()%100;
    
    if ( alea >= 0 && alea <= 10 ){
        cas = 0;
    }

    if ( alea >= 11 && alea <= 18){
        cas = 1;
    }

    if ( alea >= 19 && alea <= 53){
        cas = 2;
    }

    if ( alea >= 54 && alea <= 58){
        cas = 3;
    }

    if ( alea >= 59 && alea <= 66){
        cas = 4;
    }

    if ( alea >= 67 && alea <= 74){
        cas = 5;
    }

    if ( alea >= 75 && alea <=83){
        cas = 6;
    }

    if ( alea >= 84 && alea <=95){
        cas = 7;
    }

    if ( alea >= 96 && alea <=100){
        cas = 8;
    }

    switch(cas){
        case(0) : return tab0[0];
                  break;

        case(1) : return tab1[0];
                  break;
        
        case(2) : i=rand()%5;
                  return tab2[i];
                  break;
        
        case(3) : return tab3[0];
                  break;
        
        case(4) : return tab4[0];
                  break;
        
        case(5) : i=rand()%2;
                  return tab5[i];
                  break;
        
        case(6) : i=rand()%3;
                  return tab6[i];
                  break;
        
        case(7) : i=rand()%6;
                  return tab7[i];
                  break;
        
        case(8) : i=rand()%6;
                  return tab8[i];
                  break;
    }
    return 0;
}

void remplir_lettre_vide(int taille, char **tab){
    /*fonction qui remplie la grille avec des lettre au hasard en minuscule quand la case est vide */
    int i,j;
    char lettre;
    srand(time(NULL));
    for(i=0;i<taille;i++){
        for(j=0;j<taille;j++){
            if(tab[i][j]=='.'){
                lettre = lettre_aleatoire();
                tab[i][j]=lettre;
            }
        }
    }
}