#include <stdio.h>
#include <stdlib.h>

void free_matrix(int x,int** tab){
    for ( int i = 0; i<x; i++ )
    {
        free(tab[i]);
    }
    free(tab);
}

int** DecaleLignes(int** a){
    //on créait une nouvelle matrice pour pouvoir décaler les valeurs sans problemes
    int ** b = malloc( 4*sizeof(int*) );
    for ( int i = 0; i<4; i++ ){
        b[i] = malloc( 4*sizeof(int) );
    }

    //attribution des valeurs avec le décalage
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            b[i][j]=a[i][(j+i)%4]; // (i+j)%4 permet d'avoir exactement le décalage demandé
        }
    }
    free_matrix(4,a);//on free l'ancienne matrice
    return b;//on return la nouvelle matrice qui a beneficié du décalage
}

void display_matrix(int x, int y, int** tab){
    for(int i = 0;i<x;i++){
        for(int j = 0; j<y;j++){
            printf("|%2x|",tab[i][j]);
        }
        printf("\n");
    }
}

