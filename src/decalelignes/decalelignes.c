#include "../suboctet/suboctet.h"
#include "decalelignes.h"
#include "../tools/tools.h"

void decale_lignes(int **matrix){
    int value = 0;
    //On fait toutes les matrices
    //attribution des valeurs avec le décalage
    for(int i=0;i<4;i++){
        //k fois decalage de 1 
        //(possibilité de juste décalé de (i+j)%4 mais il faut stocker completement la ligne a chaque fois)
        for(int k = 0; k<i; k++){
            for(int j=0;j<4;j++){
                //on retient la premiere valeur
                if(!j)value = matrix[i][j];
                if(j<3){
                    matrix[i][j]=matrix[i][j+1];
                }
                else{
                    //on remplace la 4 eme valeur par la premiere
                    matrix[i][j]=value;
                }
            } 
        }
        }  
}

//version pour une matrice seul
// int** decale_lignes(int** matrix){
//     //on créait une nouvelle matrice pour pouvoir décaler les valeurs sans problemes
//     int ** new_matrix = malloc( 4*sizeof(int*) );
//     for ( int i = 0; i<4; i++ ){
//         new_matrix[i] = malloc( 4*sizeof(int) );
//     }

//     //attribution des valeurs avec le décalage
//     for(int i=0;i<4;i++){
//         for(int j=0;j<4;j++){
//             new_matrix[i][j]=matrix[i][(j+i)%4]; // (i+j)%4 permet d'avoir exactement le décalage demandé
//         }
//     }
//     free_matrix(4,matrix);//on free l'ancienne matrice
//     return new_matrix;//on return la nouvelle matrice qui a beneficié du décalage
// }