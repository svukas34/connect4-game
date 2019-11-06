#include <stdlib.h>
#include <stdio.h>

int gagnerHorizontale(int joueurActuel, int numeroLigne,int plateau[6][7]){
  if (plateau[numeroLigne][3]!=joueurActuel)
    return 0;
  int j, k=0;
  for (j=0 ; j<7 ; j++){
    if (plateau[numeroLigne][j] == joueurActuel)
      k++;
    else k = 0 ;
    if (k == 4)
      return 1;
  }
  return 0 ;
}


int gagnerVerticale(int joueurActuel , int numeroColonne ,int plateau[6][7]){
  int i, k=0 ;
  for (i=0 ; i<6 ; i++){
    if (plateau[i][numeroColonne] == joueurActuel)
      k++;
    else k=0 ;
    if (k == 4)
      return 1;
  }
  return 0 ;
}


int gagnerNOSE(int joueurActuel, int numeroLigne, int numeroColonne, int plateau[6][7]){
  int k=0;
  while(numeroLigne!=0 && numeroColonne!=0)     //la jrecherche les plus hautes et à gauche coordonee qui sont sur la diagonale du coup quon etudie
    numeroLigne--, numeroColonne--;
  while(numeroLigne<6 && numeroColonne<7){
    if(plateau[numeroLigne][numeroColonne]==joueurActuel)
      k++;
    else k=0;
    if(k==4)
      return 1 ;
    numeroLigne++ , numeroColonne++ ;
  }
  return 0 ;
}

int gagnerSONE(int joueurActuel, int numeroLigne, int numeroColonne, int plateau[6][7]){
  int k=0;
  while(numeroLigne!=5 && numeroColonne!=0)
    numeroLigne++, numeroColonne--;
  while(numeroLigne!=0 && numeroColonne<7){
    if (plateau[numeroLigne][numeroColonne] == joueurActuel)
      k++;
    else k = 0;
    if(k == 4)
      return 1;
    numeroLigne--, numeroColonne++;
  }
  return 0;
}


int victoireDe(int joueurActuel, int numeroLigne, int numeroColonne,int plateau[6][7]){
  if(gagnerHorizontale(joueurActuel,numeroLigne,plateau) == 1 || gagnerVerticale(joueurActuel,numeroColonne,plateau) == 1 || gagnerNOSE(joueurActuel,numeroLigne,numeroColonne,plateau) == 1 || gagnerSONE(joueurActuel,numeroLigne,numeroColonne,plateau) == 1) 
    return 1;
  else return 0;
}
