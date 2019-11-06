#include <stdio.h>
#include <stdlib.h>

//int main()
//{
  //  printf("Hello world!\n");
  //  return 0;
//}

int afficheQuestion(){
  int q;
  printf("\n Quelle colonne choisissez-vous de jouer ? : ");
  scanf("%d",&q);
  return q;
}






int afficheTerminal(int plateau[6][7], int estHumain){
    int i,j,q;
    for(i=0 ; i<6 ; i++){
    printf(" \n");
    for(j=0 ; j<7 ; j++){
     printf(" %d", plateau[i][j]);
    }
    printf(" \n");
  }
    if(estHumain==1 || estHumain==2){
        q = afficheQuestion();
        while(q<0 || q>6 || plateau[0][q]!=0){ //tant que le coup n'est pas jouable
        printf("ERREUR \n");
        q = afficheQuestion();
    }
    return q;

}
}


int initialiseVide(int plateau[6][7]){
  int i,j;
  for(i=0 ; i<6 ; i++){
    for(j=0 ; j<7 ; j++)
      plateau[i][j]=0 ;
  }
return plateau;
}



int coupjouable(int plateau[6][7], int q){
  if (q<0 || q>6 || plateau[0][q]!=0){
    return 0;
    }
  else return 1;
}



int gagnerHorizontale(int n, int p,int plateau[6][7]){
  if (plateau[p][3]!=n)
    return 0;
  int j, k=0;
  for (j=0 ; j<7 ; j++){
    if (plateau[p][j] == n)
      k++;
    else k = 0 ;
    if (k == 4)
      return 1;
  }
  return 0 ;
}

int gagnerVerticale(int n , int q ,int plateau[6][7]){
  int i, k=0 ;
  for (i=0 ; i<6 ; i++){
    if (plateau[i][q] == n)
      k++;
    else k=0 ;
    if (k == 4)
      return 1;
  }
  return 0 ;
}


int gagnerNOSE(int n, int p, int q, int plateau[6][7]){
  int i=p, j=q, k=0;
  while(i!=0 && j!=0)     //la jrecherche les plus hautes et à gauche coordonee qui sont sur la diagonale du coup quon etudie
    i--, j--;
  while(i<6 && j<7){
    if(plateau[i][j]==n)
      k++;
    else k=0;
    if(k==4)
      return 1 ;
    i++ , j++ ;

  }
  return 0 ;
}



int gagnerSONE(int n, int p, int q, int plateau[6][7]){
  int i=p, j=q, k=0;
  while(i!=5 && j!=0)
    i++, j--;
  while(i!=0 && j<7){
    if (plateau[i][j] == n)
      k++;
    else k = 0;
    if(k == 4)
      return 1;
    i--, j++;
  }
  return 0;
}



int Gagner(int n, int p, int q,int plateau[6][7]){ //numero du joueur, la cordonné de la ligne de la colone jouer, colone
  if(gagnerHorizontale(n,p,plateau) == 1 || gagnerVerticale(n,q,plateau) == 1 || gagnerNOSE(n,p,q,plateau) == 1 || gagnerSONE(n,p,q,plateau) == 1) {
    return 1;
  }
  else return 0;
}


int coordonneeLigne(int q, int plateau[6][7]){
  int p=5;

  while(plateau[p][q]!=0){
    p--;
  }
  return p;
}



int remplirPlateau(int n, int q,int plateau[6][7]){
  int p = coordonneeLigne(q,plateau);
  plateau[p][q] = n;
  return plateau;
}








void Jeux(){

  int plateau[6][7],i ,j ,p ,q ,k ;
  plateau[6][7] = initialiseVide(plateau);

  for(k=1 ; k<43 ; k++){
    q =  afficheTerminal(plateau, 1);
    p = coordonneeLigne(q, plateau);
    plateau[6][7] = remplirPlateau(1 ,q ,plateau);
    if(Gagner(1 ,p ,q ,plateau) == 0){
        q = afficheTerminal(plateau, 2);
        p = coordonneeLigne(q, plateau);
        plateau[6][7] = remplirPlateau(2, q, plateau);
        if(Gagner(2, p, q, plateau)== 1){
            printf(" \n JOUEUR 2 A GAGNER \n");
            afficheTerminal(plateau,3);
            return;
        }
    }
    else {
    printf(" \n JOUEUR 1 A GAGNER !!! \n");
    afficheTerminal(plateau,3);
    return ;
    }
  }
}

int main(){
    Jeux();
    return 0;
    }
