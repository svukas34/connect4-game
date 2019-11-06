#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include<time.h>
#include "puissance4.h"

int main(){
    srand(time(NULL));
    SDL_Surface *ecran = NULL, *menu=NULL;
    SDL_Event event; //variable de type SDL_Event qui va servire à gerer les evenements (qui va contenir un evenement)
    int continuer = 1; //si vaut 0, on ferme le programme
    
    SDL_Init(SDL_INIT_VIDEO);
    
    ecran = SDL_SetVideoMode(450,350,32, SDL_HWSURFACE | SDL_DOUBLEBUF); //doublebuf = anti scintillement ...

    menu = SDL_LoadBMP("menu.bmp");
    SDL_Rect posMenu;
    posMenu.x = 0;
    posMenu.y=0;
    SDL_BlitSurface(menu, NULL, ecran, &posMenu);
    SDL_Flip(ecran);
    
    //    SDL_EnableKeyRepeat(10,10); //gestion du maintient d'une touche enfoncé
    
    while(continuer){ //tant que la variable ne vaut pas 0
	SDL_WaitEvent(&event); //on atd un evenement qui sera stocker dans "event"
	switch(event.type){   //on regarde le type d'evenemnt que c'est (apuye sur une touche, clik de souris, etc...)
	case SDL_QUIT: //si on apuye sur quitter
	    continuer = 0;
	    break;
	case SDL_KEYDOWN:
	    switch(event.key.keysym.sym){
	    case SDLK_ESCAPE:
		continuer = 0;
		break;
	    case SDLK_RETURN:
		puissance4_jeu(ecran);
		break;
	    }
	    break;
	}
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
	SDL_BlitSurface(menu, NULL, ecran, &posMenu);
	SDL_Flip(ecran);
    }
    SDL_Quit();
    return EXIT_SUCCESS;
}
