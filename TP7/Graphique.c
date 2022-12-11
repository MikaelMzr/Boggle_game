/* Dos Santos Loïc */
/* Mikael Mezouar */
/* Création : 05-04-2021 */
#include "Graphique.h"

void init_fenetre(void){
    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(0);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));
}

void fin_fenetre(int score){
    clear();
    mvprintw(LINES / 2, COLS / 2 - 8, "Score final : %d", score);
    refresh();
    sleep(2);
    getch();
    endwin();
}

void affiche_grille(int taille, char **grille){
    int i;
    int j;
  
    for(i = 0; i < taille; i++){
        for(j = 0; j < taille; j++){
        	mvprintw(i,j,"%c",grille[i][j]);  
        }
    }
}

void message_score_tour(int points, int tour, char mot[]){
    mvprintw(LINES - 3, COLS - 24, "Score actuel : %d", points);
    mvprintw(LINES - 2, COLS - 27, "Tentatives restantes : %d", tour);
    mvprintw(LINES - 1, COLS - 30, "mot actuel : ", "%s", mot); 
    refresh();
    sleep(1);
}

void efface(void){
    mvprintw(LINES - 3, COLS - 24, "                        ");
    mvprintw(LINES - 2, COLS - 27, "                            ");
    mvprintw(LINES - 1, COLS - 30, "                               ");
    mvprintw(15, 15, "                                                            ");
    refresh();
}