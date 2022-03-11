#include "decalelignes.h"

void free_matrix(int x,int** tab){
    for ( int i = 0; i<x; i++ )
    {
        free(tab[i]);
    }
    free(tab);
}

//version actuel pour une matrice seul
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

//VERSION POUR FONCTIONNER AVEC LA STRUCT BLOCK
// void DecaleLignes(Block* a, int nb_block){
//     int value = 0;
//     //On fait toutes les matrices
//     for(int l = 0; l<nb_block;l++){
//         //attribution des valeurs avec le décalage
//         for(int i=0;i<4;i++){
//             //k fois decalage de 1 
//             //(possibilité de juste décalé de (i+j)%4 mais il faut stocker completement la ligne a chaque fois)
//             for(int k = 0; k<i; k++){
//                 for(int j=0;j<4;j++){
//                     //on retient la premiere valeur
//                     if(!j)value = a[l].matrice[i][j];
//                     if(j<3){
//                         a[l].matrice[i][j]=a[l].matrice[i][j+1];
//                     }
//                     else{
//                         //on remplace la 4 eme valeur par la premiere
//                         a[l].matrice[i][j]=value;
//                     }
//                 } 
//             }
//         }
//     }    
// }

void display_matrix(int x, int y, int** tab){
    for(int i = 0;i<x;i++){
        for(int j = 0; j<y;j++){
            printf("|%2x|",tab[i][j]);
        }
        printf("\n");
    }
}

