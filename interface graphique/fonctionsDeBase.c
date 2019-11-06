#include <stdlib.h>
#include <stdio.h>



int coupJouable(int plateau[6][7], int numeroColonne){
    if (numeroColonne<0 || numeroColonne>6 || plateau[0][numeroColonne]!=0){
	return 0;
    }
    else return 1;
}


int coordonneeDerniereLigne(int plateau[6][7], int numeroColonne){
    int numeroLigne=5;
    while(plateau[numeroLigne][numeroColonne]!=0){
	numeroLigne--;
    }
    return numeroLigne;
}


int intervertirJoueur(int j1){
    if (j1 == 1)
	return 2;
    if (j1 == 2)
	return 1;
    return 0;
}
