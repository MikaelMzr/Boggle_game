# Dos Santos Loïc
# Mikael Mezouar
# Création : 30-03-2021
# Dernière modification : 05-04-2021
CC = gcc
CFLAGS = -ansi -Wall -pedantic -lm -lncurses
OBJ = Main.o Test.o Regle.o Saisie.o Graphique.o Grille.o Dico.o

Boggle: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

Main.o: Main.c Test.h Regle.h Graphique.h

Test.o: Test.c Test.h Grille.h

Regle.o: Regle.c Regle.h Saisie.h

Saisie.o: Saisie.c Saisie.h Grille.h

Graphique.o: Graphique.c Graphique.h Grille.h

Grille.o: Grille.c Grille.h Dico.h

Dico.o: Dico.c Dico.h

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o