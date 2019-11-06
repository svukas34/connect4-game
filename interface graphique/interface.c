#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "victoire.h"
#include "fonctionsDeBase.h"


void initInterface(SDL_Surface *ecran){
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0,0,0)); //remplit le fond de couleur noir
    SDL_Surface *pionBlanc;
    pionBlanc = SDL_LoadBMP("jeton.bmp");
    SDL_Rect  positionPion;
    int ligne, colonne;
    int espaceX =0, espaceY =0;
    for (ligne=0; ligne<6; ligne++){	//"dessine des cercles blanc" aux cordonnées destinés au pions 
	espaceX = 0;
	for (colonne=0; colonne<7; colonne++){
	    positionPion.x = 12 +espaceX; 
	    positionPion.y = 7 +espaceY;
	    SDL_BlitSurface(pionBlanc, NULL, ecran, &positionPion);
	    espaceX = espaceX + 50 + 12; //entre chaque pions on laisse 12 pixel d'écart à l'horizontale + le pion fait 50px
	}
	espaceY = espaceY +  50 + 7;//entre chaque pions on laisse 7 pixel d'écart à la verticale + hauteur du pion (50pixel)
    }
    SDL_Flip(ecran); //on "refresh" l'ecran pour que les modifications efféctués s'affiches 
}


void affichageMAJ(SDL_Surface *ecran, int joueur, int nbLigne, int nbColonne){
    SDL_Surface *pionRouge, *pionBleu;
    pionRouge = SDL_LoadBMP("jetonRouge.bmp");
    pionBleu = SDL_LoadBMP("jetonBleu.bmp");

    /*peu etre pas utile :
      int positionYdernierPion = 292; //7x6 + 50x5 (voir fonction initinterface pour explication + détaillé sur 7 et 50) */

    SDL_Rect  positionPion;
    positionPion.x = 12 + nbColonne*(50+12);
    positionPion.y =7 + nbLigne*(50+7);// positionYdernierPion - nbLigne*(50+7);
    if (joueur == 1)
	SDL_BlitSurface(pionRouge, NULL, ecran, &positionPion);
    if (joueur == 2) 
	SDL_BlitSurface(pionBleu, NULL, ecran, &positionPion);
    SDL_Flip(ecran); // raffraichit l'ecran (pour pouvoir voir les modifications)
}


void interfaceVictoire(SDL_Surface *ecran){
    SDL_Rect pos;
    pos.x = 0;
    pos.y = 0;
    SDL_Surface *gagne;
    gagne = SDL_LoadBMP("gagne.bmp");
    SDL_SetColorKey(gagne, SDL_SRCCOLORKEY, SDL_MapRGB(gagne->format, 0,0,0)); //rend transparent le fond (voir comment gagner)

    SDL_BlitSurface(gagne,NULL,ecran,&pos);
    SDL_Flip(ecran);

    pauseAffichage();
}

void interfaceEgalite(SDL_Surface *ecran){
    SDL_Rect pos;
    pos.x = 0;
    pos.y = 0;
    SDL_Surface *egalite;
    egalite = SDL_LoadBMP("egalite.bmp");
    SDL_SetColorKey(egalite, SDL_SRCCOLORKEY, SDL_MapRGB(egalite->format, 0,0,0));

    SDL_BlitSurface(egalite,NULL,ecran,&pos);
    SDL_Flip(ecran);

    pauseAffichage();
}

//NE FONCTIONNE PAS
/*struct SDL_Rect* initPositionNulle(){
    SDL_Rect pos;
    pos.x = 0;
    pos.y = 0;
    return &pos;
    }*/


//la fonction pauseAffichage est fortement inspiré du site www.openclassroom.fr (tutoriel sur la SDL)
void pauseAffichage(){
    SDL_Event event;
    int continuer = 1;

    while(continuer == 1){
	SDL_WaitEvent(&event);
	switch(event.type){
	case SDL_QUIT:
	    continuer = 0;
	    break;
	case SDL_KEYDOWN:
	    continuer = 0;
	    break;
	}
    }
}

void afficheChoixJeu(SDL_Surface *ecran){
    SDL_Surface *surface;
    surface = SDL_LoadBMP("choixJeu.bmp");
    SDL_Rect pos;
    pos.x = 0;
    pos.y = 0;
    SDL_BlitSurface(surface,NULL,ecran,&pos);
    SDL_Flip(ecran);

}

void afficheChoixNiveau(SDL_Surface *ecran){
    SDL_Surface *surface;
    surface = SDL_LoadBMP("choixNiveau.bmp");
    SDL_Rect pos;
    pos.x = 0;
    pos.y = 0;
    SDL_BlitSurface(surface,NULL,ecran,&pos);
    SDL_Flip(ecran);
}

void afficheChoixJoueur(SDL_Surface *ecran){
    SDL_Surface *surface;
    surface = SDL_LoadBMP("choixJoueur.bmp");
    SDL_Rect pos;
    pos.x = 0;
    pos.y = 0;
    SDL_BlitSurface(surface,NULL,ecran,&pos);
    SDL_Flip(ecran);
}


