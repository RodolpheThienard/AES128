#include "../suboctet/suboctet.h"
#include "decalelignes.h"
#include "../tools/tools.h"

//version pour une matrice seul
int** decale_lignes(int** matrix){
    //on créait une nouvelle matrice pour pouvoir décaler les valeurs sans problemes
    int ** new_matrix = malloc( 4*sizeof(int*) );
    for ( int i = 0; i<4; i++ ){
        new_matrix[i] = malloc( 4*sizeof(int) );
    }

    //attribution des valeurs avec le décalage
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            new_matrix[i][j]=matrix[i][(j+i)%4]; // (i+j)%4 permet d'avoir exactement le décalage demandé
        }
    }
    free_matrix(matrix, 4);//on free l'ancienne matrice
    return new_matrix;//on return la nouvelle matrice qui a beneficié du décalage
}