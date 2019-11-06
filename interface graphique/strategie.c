#include<stdio.h>
#include<stdlib.h>

#include "fonctionsDeBase.h"


typedef enum Direction Direction;
enum Direction
{
    GAUCHE,DROITE,HAUT,BAS
};


int strategieAttaqueColone(int joueur, int colonne,int plateau[6][7]){ //renommer fonction potentielleDeLaColonne ??
    if (coupJouable(plateau, colonne)){
	int ligne =  coordonneeDerniereLigne(plateau, colonne); // la ligne vide la plus basse
	if( plateau[ligne+1][colonne] != joueur ) //si le dernier jettons appartient à l'adversaire
	    return 0;
	if (ligne == 0) //si la colone est vide
	    return 0;
	if( plateau[ligne+1][colonne] == joueur) {
	    if( plateau[ligne+2][colonne] == joueur) {
		if( plateau[ligne+3][colonne] == joueur) {
		    return 3;
		} return 2;
	    } return 1;
	}
    } return 0;
}


int strategieAttaqueLigne(int joueur, int colonne,int plateau[6][7]){//renomer ?
    if (coupJouable(plateau,colonne)){
	int ligne = coordonneeDerniereLigne(plateau, colonne);
	return (testLigne(GAUCHE, joueur, ligne, colonne, plateau) + testLigne(DROITE, joueur, ligne, colonne, plateau));//on regarde a gauche ET a droite
    } return 0;
}

int testLigne(Direction d,int j,int l,int c,int p[6][7]){ // renomer ?
    int delta;
    if (d == DROITE) // si on va vers la droite on ajoute +1 aux colones
	delta = 1;
    if (d == GAUCHE) // si on va vers la gauche on enleve -1 aux colones
	delta = -1;
    if(p[l][c + delta*1] == j){
	if(p[l][c + delta*2] == j){
	    if(p[l][c + delta*3] == j){
		return 3;
	    } return 2;
	} return 1;
    }
}


/*
// ATTENTION CETTE STRATEGIE EST FAUSSE !!!!!! elle additionne 2 diagonale qui se croisent, et non aligné
// IL faut refaire avec en ajoutant NO et SE puis celle avec NE et SO
// et donc on a obligatoirement 2fonction differentes
int strategieAttaqueDiagonaleHaut(int joueur, int colonne,int plateau[6][7]){ //que les diagonale qui se finisse en hauteur
    if (coupJouable(plateau,colonne)){
	int ligne = coordonneDerniereLigne(plateau, colonne);
	if (ligne == 0) //si colone vide
	    return 0;
	int NOSE = testDiag(GAUCHE,HAUT, joueur, ligne, colonne, plateau) + testDiag(DROITE,BAS, joueur, ligne, colonne, plateau);
int SONE = 
	return (testDiag(GAUCHE, joueur, ligne, colonne, plateau) + testDiagHaut(DROITE, joueur, ligne, colonne, plateau)); // on regarde les diagonales qui vont vers le haut, par la droite et par la guache
    } return 0;
    }*/


int strategieAttaqueDiagonaleNOSE(int joueur, int colonne, int plateau[6][7]){
    if (coupJouable(plateau,colonne)){
	int ligne = coordonneeDerniereLigne(plateau, colonne);
	if (ligne == 0) //si colone vide
	    return 0;
	return (testDiag(GAUCHE, HAUT, joueur, ligne, colonne, plateau) + testDiag(DROITE, BAS, joueur, ligne, colonne, plateau));
    } return 0;
}

int strategieAttaqueDiagonaleSONE(int joueur, int colonne, int plateau[6][7]){
    if (coupJouable(plateau,colonne)){
	int ligne = coordonneeDerniereLigne(plateau, colonne);
	if (ligne == 0) //si colone vide
	    return 0;
	return (testDiag(GAUCHE, BAS, joueur, ligne, colonne, plateau) + testDiag(DROITE, HAUT, joueur, ligne, colonne, plateau));
    } return 0;
}


int testDiag(Direction x,Direction y,int j,int l,int c,int p[6][7]){
    int deltaX, deltaY;
    if(x == DROITE)
	deltaX = 1;
    if(x == GAUCHE)
	deltaX = -1;
    if(y == HAUT)
	deltaY = -1;
    if(y == BAS)
	deltaY = 1;
    if(p[l + deltaY*1][c + deltaX*1] == j){
	if(p[l + deltaY*2][c + deltaX*2] == j){
	    if(p[l+ deltaY*3][c + deltaX*3] == j){
		return 3;
	    } return 2;
	} return 1;
    }
}

/* PB RESOLUE
int strategieAttaqueDiagonaleBas(){} //soit refaire DELTA, soit copier coller et changer 2 valeurs
*/



int potentielDeLaColonne(int colonne, int joueur ,int plateau[6][7]){ //renommer potentielColonne ?
    int potentiel=0;
    int a = max(strategieAttaqueColone(joueur, colonne, plateau), strategieAttaqueLigne(joueur, colonne, plateau));
    int b = max(strategieAttaqueDiagonaleNOSE(joueur, colonne, plateau), strategieAttaqueDiagonaleSONE(joueur, colonne, plateau));
    potentiel = max(a,b);
}


int max(int a, int b){
    if (a>=b)
	return a;
    else
	return b;
}


int strategieAttaque(int joueur, int plateau[6][7]){
    int colonneAjouer;
    if(coupJouable(plateau,3)) //jouer au milieu si possible
	colonneAjouer = 3;
    else
	colonneAjouer = strategieAleatoire();
    int i;
    for(i=0; i<7; i++){
	if (potentielDeLaColonne(i, joueur, plateau) > potentielDeLaColonne(colonneAjouer, joueur, plateau))
	    colonneAjouer = i;
    }
    return colonneAjouer;
}


int strategieAleatoire(){

    return (rand()%7);
}

int strategieDefense(int joueur, int plateau[6][7]){
    int adversaire = intervertirJoueur(joueur);
    return (strategieAttaque(adversaire, plateau));
}


int strategie(int joueur, int plateau[6][7], int difficulte){
    if(difficulte == 0)
	return strategieAleatoire();
    if(difficulte == 1)
	return strategieDefense(joueur, plateau);
    if(difficulte == 2)
	return strategieAttaque(joueur, plateau);
    if(difficulte == 3)
	return strategieDefense2(joueur, plateau);
    if(difficulte == 4)
	return strategieAttaque2(joueur, plateau);
    if(difficulte == 5)
	return  strategieIdeal(joueur, plateau);
    if(difficulte == 6)
	return strategieIdeal2(joueur, plateau);
    return strategieAleatoire();
}	


int strategieDefense2(int joueur, int plateau[6][7]){
    int adversaire = intervertirJoueur(joueur);
    int i;
    for(i=0; i<7; i++){
	if ((strategieAttaqueColone(adversaire, i, plateau) == 3) && coupJouable(plateau, i))
	    return i;
    }
    for(i=0; i<7; i++){
	if ((strategieAttaqueLigne(adversaire, i, plateau) == 3) && coupJouable(plateau, i))
	    return i;
    }
    for(i=0; i<7; i++){
	if ((strategieAttaqueDiagonaleNOSE(adversaire, i, plateau) == 3) && coupJouable(plateau, i))
	    return i;
    }
    for(i=0; i<7; i++){
	if ((strategieAttaqueDiagonaleSONE(adversaire, i, plateau) == 3) && coupJouable(plateau, i))
	    return i;
    }
    for(i=0; i<7; i++){
	if ((strategieAttaqueColone(adversaire, i, plateau) == 2) && coupJouable(plateau, i))
	    return i;
    }
    for(i=0; i<7; i++){
	if ((strategieAttaqueLigne(adversaire, i, plateau) == 2) && coupJouable(plateau, i))
	    return i;
    }
    for(i=0; i<7; i++){
	if ((strategieAttaqueDiagonaleNOSE(adversaire, i, plateau) == 2) && coupJouable(plateau, i))
	    return i;
    }
    for(i=0; i<7; i++){
	if ((strategieAttaqueDiagonaleSONE(adversaire, i, plateau) == 2) && coupJouable(plateau, i))
	    return i;
    }
    for(i=0; i<7; i++){
	if ((strategieAttaqueColone(adversaire, i, plateau) == 1) && coupJouable(plateau, i))
	    return i;
    }
    for(i=0; i<7; i++){
	if ((strategieAttaqueLigne(adversaire, i, plateau) == 1) && coupJouable(plateau, i))
	    return i;
    }
    for(i=0; i<7; i++){
	if ((strategieAttaqueDiagonaleNOSE(adversaire, i, plateau) == 1) && coupJouable(plateau, i))
	    return i;
    }
    for(i=0; i<7; i++){
	if ((strategieAttaqueDiagonaleSONE(adversaire, i, plateau) == 1) && coupJouable(plateau, i))
	    return i; 
    }
}

int strategieAttaque2(int joueur, int plateau[6][7]){
    int adversaire = intervertirJoueur(joueur);
    return (strategieDefense2(adversaire, plateau));
}


int strategieIdeal(int joueur, int plateau[6][7]){
    int adversaire = intervertirJoueur(joueur);
    int i;
    for(i=0; i<7; i++){
	if(potentielDeLaColonne(i, adversaire ,plateau) == 3)
	    return i;
    }
    return strategieAttaque(joueur, plateau);
}


int strategieIdeal2(int joueur, int plateau[6][7]){
    int adversaire = intervertirJoueur(joueur);
    int i;
    // DEFENSE :
    for(i=0; i<7; i++){
	if ((strategieAttaqueColone(adversaire, i, plateau) == 3) && coupJouable(plateau, i))
	    return i;
    }
    for(i=0; i<7; i++){
	if ((strategieAttaqueLigne(adversaire, i, plateau) == 3) && coupJouable(plateau, i))
	    return i;
    }
    for(i=0; i<7; i++){
	if ((strategieAttaqueDiagonaleNOSE(adversaire, i, plateau) == 3) && coupJouable(plateau, i))
	    return i;
    }
    for(i=0; i<7; i++){
	if ((strategieAttaqueDiagonaleSONE(adversaire, i, plateau) == 3) && coupJouable(plateau, i))
	    return i;
    }
    // ATTAQUE :
    for(i=0; i<7; i++){
	if ((strategieAttaqueColone(joueur, i, plateau) == 3) && coupJouable(plateau, i))
	    return i;
    }
    for(i=0; i<7; i++){
	if ((strategieAttaqueLigne(joueur, i, plateau) == 3) && coupJouable(plateau, i))
	    return i;
    }
    for(i=0; i<7; i++){
	if ((strategieAttaqueDiagonaleNOSE(joueur, i, plateau) == 3) && coupJouable(plateau, i))
	    return i;
    }
    for(i=0; i<7; i++){
	if ((strategieAttaqueDiagonaleSONE(joueur, i, plateau) == 3) && coupJouable(plateau, i))
	    return i;
    }
    for(i=0; i<7; i++){
	if ((strategieAttaqueColone(joueur, i, plateau) == 2) && coupJouable(plateau, i))
	    return i;
    }
    for(i=0; i<7; i++){
	if ((strategieAttaqueLigne(joueur, i, plateau) == 2) && coupJouable(plateau, i))
	    return i;
    }
    for(i=0; i<7; i++){
	if ((strategieAttaqueDiagonaleNOSE(joueur, i, plateau) == 2) && coupJouable(plateau, i))
	    return i;
    }
    for(i=0; i<7; i++){
	if ((strategieAttaqueDiagonaleSONE(joueur, i, plateau) == 2) && coupJouable(plateau, i))
	    return i;
    }
    for(i=0; i<7; i++){
	if ((strategieAttaqueColone(joueur, i, plateau) == 1) && coupJouable(plateau, i))
	    return i;
    }
    for(i=0; i<7; i++){
	if ((strategieAttaqueLigne(joueur, i, plateau) == 1) && coupJouable(plateau, i))
	    return i;
    }
    for(i=0; i<7; i++){
	if ((strategieAttaqueDiagonaleNOSE(joueur, i, plateau) == 1) && coupJouable(plateau, i))
	    return i;
    }
    for(i=0; i<7; i++){
	if ((strategieAttaqueDiagonaleSONE(joueur, i, plateau) == 1) && coupJouable(plateau, i))
	    return i; 
    }
    return strategieAleatoire();
}


