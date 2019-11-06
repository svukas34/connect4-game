#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "victoire.h"
#include "interface.h"
#include "lecture.h"
#include "fonctionsDeBase.h"



void puissance4_jeu(SDL_Surface *ecran){

    int continuer =1; //si vaut 0 le jeu s'arrete
    afficheChoixJeu(ecran);
    int choix1 = choixJeu(); //on choisit de jouer à 2 1 ou 0 joueurs;

    int plateau[6][7]={0};

    int nombreCoupJoue = 0; 
    int premierJoueur = 1;
    int joueurActuel = 1; //joeuur qui jou actuellement 1 si c'est j1, 2 si c'est j2
    int numeroColonne =0, numeroLigne=0;




    if(choix1 == 2){
	afficheChoixJoueur(ecran);
	//premierJoueur = choixJoueur(choix1); // retourne 1 ou 2 //ici va etre le pierre feuille ciseau;
	initInterface(ecran);
	while((victoireDe(joueurActuel, numeroLigne, numeroColonne, plateau) != 1 || estRemplie(42,nombreCoupJoue) != 1) && ( continuer == 1)){
	    nombreCoupJoue++;
	    
	    if(nombreCoupJoue%2 == 1){ //si c'est impaire c'est le premier joueur qui joue
		joueurActuel = premierJoueur;
	    }else {
		joueurActuel = intervertirJoueur(premierJoueur);
	    }
	    numeroColonne = lireColonne();
	    if (numeroColonne == -1){
		continuer = 0;
	    } else {
		numeroLigne = coordonneeDerniereLigne(plateau, numeroColonne);
		while((coupJouable(plateau, numeroColonne) != 1) && ( continuer ==1)){ //si colone est ligne ne permette pas un coup jouable
		    numeroColonne = lireColonne();
		    if (numeroColonne == -1)
			continuer = 0;
		    numeroLigne = coordonneeDerniereLigne(plateau, numeroColonne);
		}
		plateau[numeroLigne][numeroColonne] = joueurActuel;
		affichageMAJ(ecran, joueurActuel, numeroLigne, numeroColonne); //Met A Jour l'affichage avec le nouveau jetton
		
		if(victoireDe(joueurActuel, numeroLigne, numeroColonne, plateau)){
		    interfaceVictoire(ecran);
		    continuer = 0;
		}else { // else =  si on gagne du dernier coup
		    if(estRemplie(42,nombreCoupJoue)){
			interfaceEgalite(ecran);
			continuer = 0;
		    }
		}
	    }
	}
    }
    if(choix1 == 1){
	afficheChoixNiveau(ecran);
	int difficulte = choixNiveau();
	if(difficulte >3)
	    premierJoueur = 2;
	else
	    premierJoueur = 1;
	initInterface(ecran);
	while((victoireDe(joueurActuel, numeroLigne, numeroColonne, plateau) != 1 || estRemplie(42,nombreCoupJoue) != 1) && ( continuer == 1)){

	    nombreCoupJoue++;
	    
	    if(nombreCoupJoue%2 == 1){
		joueurActuel = premierJoueur;
	    }else {
		joueurActuel = intervertirJoueur(premierJoueur);
	    }
	    if(joueurActuel == 2){ //si c'est un robot
		numeroColonne = strategie(joueurActuel, plateau, difficulte);
	    } else {
		numeroColonne = lireColonne();
	    }
	    if (numeroColonne == -1){
		continuer = 0;
	    } else {
		numeroLigne = coordonneeDerniereLigne(plateau, numeroColonne);
		while((coupJouable(plateau, numeroColonne) != 1) && ( continuer ==1)){
		    numeroColonne = lireColonne();
		    if (numeroColonne == -1)
			continuer = 0;
		    numeroLigne = coordonneeDerniereLigne(plateau, numeroColonne);
		}
		plateau[numeroLigne][numeroColonne] = joueurActuel;
		affichageMAJ(ecran, joueurActuel, numeroLigne, numeroColonne); //Met A Jour l'affichage avec le nouveau jetton
		
		if(victoireDe(joueurActuel, numeroLigne, numeroColonne, plateau)){
		    interfaceVictoire(ecran);
		    continuer = 0;
		}else { // else =  si on gagne du dernier coup
		    if(estRemplie(42,nombreCoupJoue)){
			interfaceEgalite(ecran);
			continuer = 0;
		    }
		}
	    }
	}
    }
    if(choix1 == 0){
	afficheChoixNiveau(ecran);
	int difficulte1 = choixNiveau();
	int difficulte2 = choixNiveau();
	initInterface(ecran);
	//premierJoueur = (strategie(0,plateau)%2); // = aléatoire 1 ou 2
	while((victoireDe(joueurActuel, numeroLigne, numeroColonne, plateau) != 1 || estRemplie(42,nombreCoupJoue) != 1) && ( continuer == 1)){
	    nombreCoupJoue++;
	    
	    if(nombreCoupJoue%2 == 1){
		joueurActuel = premierJoueur;
	    }else {
		joueurActuel = intervertirJoueur(premierJoueur);
	    }
	    if(joueurActuel == 2){ //si c'est un robot
		numeroColonne = strategie(joueurActuel, plateau, difficulte2);
	    } else {
		numeroColonne = strategie(joueurActuel, plateau, difficulte1);
	    }
	    /* if (numeroColonne == -1){
		continuer = 0;
		} else {*/
	    numeroLigne = coordonneeDerniereLigne(plateau, numeroColonne);
		/*	while((coupJouable(plateau, numeroColonne) != 1) && ( continuer ==1)){
		    numeroColonne = lireColonne();
		    if (numeroColonne == -1)
			continuer = 0;
		    numeroLigne = coordonneeDerniereLigne(plateau, numeroColonne);
		    }*/
	    plateau[numeroLigne][numeroColonne] = joueurActuel;
	    affichageMAJ(ecran, joueurActuel, numeroLigne, numeroColonne); //Met A Jour l'affichage avec le nouveau jetton
	    
	    if(victoireDe(joueurActuel, numeroLigne, numeroColonne, plateau)){
		interfaceVictoire(ecran);
		continuer = 0;
	    }else { // else =  si on gagne du dernier coup
		if(estRemplie(42,nombreCoupJoue)){
		    interfaceEgalite(ecran);
		    continuer = 0;
		}
	    }
	}
    }
}

//ESSAYER DE FAIRE APRES
/*struct Joueur aQuiLeTour(struct Joueur j1, struct Joueur j2){
    if(nombreCoupJoue%2 == 1){ //si c'est impaire c'est le premier joueur qui joue
	if(j1.numero == 1){
	    return j1;
	} else {
	    return j2;
	}
    }
	joueurActuel = premierJoueur;
    }else {
	joueurActuel = intervertirJoueur(premierJoueur); //sinon on intervertit avec le premier => c'est le deuxieme
    }
    }*/



/*
int coupJouable(int ligne, int colone){
    return 1; // a copier coller plus tard
}

int coordonneDerniereLigne(int numeroColone){
    return 1; // a copier coller plus tard
    }*/





int estRemplie(int nombreDeCaseTotal, int nombreDeCaseRemplie){
    if(nombreDeCaseTotal > nombreDeCaseRemplie)
	return 0;
    else return 1;
}


/*int aGagne(){
    return 0; //a remplir plus tard (copier coller)
    }*/




