#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "fonctionsDeBase.h"




int lireColonne(){
    int continuer = 1;
    SDL_Event event;
    while (continuer) {
	SDL_WaitEvent(&event); //on atd un evenement qui sera stocker dans "event"
	switch(event.type){   //on regarde le type d'evenemnt que c'est (apuye sur une touche, clik de souris, etc...)
	case SDL_QUIT:
	    return -1;
	    break;
	case SDL_KEYDOWN:
	    switch(event.key.keysym.sym){
	    case SDLK_ESCAPE:
		return -1;
		break;
	    case SDLK_q:
		return  0;
		break;
	    case SDLK_s:
		return 1;
		break;
	    case SDLK_d:
		return 2;
		break;
	    case SDLK_f:
		return 3;
		break;
	    case SDLK_g:
		return 4;
		break;
	    case SDLK_h:
		return 5;
		break;
	    case SDLK_j:
		return 6;
		break;;
	    }
	    break;
	}
    }
}




int choixJoueur(int choixJeu){
    int continuer = 1;
    SDL_Event event;
    while (continuer) {
	SDL_WaitEvent(&event); //on atd un evenement qui sera stocker dans "event"
	switch(event.type){   //on regarde le type d'evenemnt que c'est (apuye sur une touche, clik de souris, etc...)
	case SDL_QUIT:
	    return -1;
	    break;
	case SDL_KEYDOWN:
	    switch(event.key.keysym.sym){
	    case SDLK_ESCAPE:
		return -1;
		break;
	    case SDLK_p:
		return 0;
		break;
	    case SDLK_f:
		return 1;
		break;
	    case SDLK_c:
		return 2;
		break;
	    }
	    break;
	}
    }
    return -1;
}

int choixJeu(){
    int continuer = 1;
    SDL_Event event;
    while (continuer) {
	SDL_WaitEvent(&event); //on atd un evenement qui sera stocker dans "event"
	switch(event.type){   //on regarde le type d'evenemnt que c'est (apuye sur une touche, clik de souris, etc...)
	case SDL_QUIT:
	    return -1;
	    break;
	case SDL_KEYDOWN:
	    switch(event.key.keysym.sym){
	    case SDLK_ESCAPE:
		return -1;
		break;
	    case SDLK_p:
		return 1;
		break;
	    case SDLK_j:
		return 2;
		break;
	    case SDLK_o:
		return 0;
		break;
	    }
	    break;
	}
    }
    return -1;
}


int choixNiveau(){
    int continuer = 1;
    SDL_Event event;
    while (continuer) {
	SDL_WaitEvent(&event);
	switch(event.type){
	case SDL_QUIT:
	    return -1;
	    break;
	case SDL_KEYDOWN:
	    switch(event.key.keysym.sym){
	    case SDLK_ESCAPE:
		return -1;
		break;
	    case SDLK_q:
		return  0;
		break;
	    case SDLK_s:
		return 1;
		break;
	    case SDLK_d:
		return 2;
		break;
	    case SDLK_f:
		return 3;
		break;
	    case SDLK_g:
		return 4;
		break;
	    case SDLK_h:
		return 5;
		break;
	    case SDLK_j:
		return 6;
		break;;
	    }
	    break;
	}
    }
}
