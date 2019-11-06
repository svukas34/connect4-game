#include <stdlib.h>
#include <stdio.h>

int gagnerHorizontale(int joueurActuel, int numeroLigne,int plateau[6][7]);
int gagnerVerticale(int joueurActuel , int numeroColonne ,int plateau[6][7]);
int gagnerNOSE(int joueurActuel, int numeroLigne, int numeroColonne, int plateau[6][7]);
int gagnerSONE(int joueurActuel, int numeroLigne, int numeroColonne, int plateau[6][7]);
int victoireDe(int joueurActuel, int numeroLigne, int numeroColonne,int plateau[6][7]);
