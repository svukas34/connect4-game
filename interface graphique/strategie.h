#include<stdlib.h>
#include<time.h>
#include "fonctionsDeBase.h"

int strategieAttaqueColone(int joueur, int colonne,int plateau[6][7]);

int strategieAttaqueLigne(int joueur, int colonne,int plateau[6][7]);

int testLigne(Direction d,int j,int l,int c,int p[6][7]);

int strategieAttaqueDiagonaleNOSE(int joueur, int colonne, int plateau[6][7]);

int strategieAttaqueDiagonaleSONE(int joueur, int colonne, int plateau[6][7]);

int testDiag(Direction x,Direction y,int j,int l,int c,int p[6][7]);

int potentielDeLaColonne(int colonne, int joueur ,int plateau[6][7]);

int max(int a, int b);

int strategieAttaque(int joueur, int plateau[6][7]);

int strategieAleatoire();

int strategieDefense(int joueur, int plateau[6][7]);

int strategie(int joueur, int plateau[6][7], int difficulte);

int strategieDefense2(int joueur, int plateau[6][7]);

int strategieAttaque2(int joueur, int plateau[6][7]);

int strategieIdeal(int joueur, int plateau[6][7]);

int strategieIdeal2(int joueur, int plateau[6][7]);
