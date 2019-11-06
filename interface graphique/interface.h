#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "victoire.h"
#include "fonctionsDeBase.h"


void initInterface(SDL_Surface *ecran);

void affichageMAJ(SDL_Surface *ecran, int joueur, int nbLigne, int nbColonne);

void interfaceVictoire(SDL_Surface *ecran);

void interfaceEgalite(SDL_Surface *ecran);

SDL_Rect initPositionNulle();

void pauseAffichage();

void afficheChoixJeu(SDL_Surface *ecran);

void afficheChoixNiveau(SDL_Surface *ecran);

void afficheChoixJoueur(SDL_Surface *ecran);
