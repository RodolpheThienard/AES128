#include "../suboctet/suboctet.h"
#include "decalelignes.h"

void DecaleLignes(Block* a, int nb_block){
    int value = 0;
    //On fait toutes les matrices
    for(int l = 0; l<nb_block;l++){
        //attribution des valeurs avec le décalage
        for(int i=0;i<4;i++){
            //k fois decalage de 1 
            //(possibilité de juste décalé de (i+j)%4 mais il faut stocker completement la ligne a chaque fois)
            for(int k = 0; k<i; k++){
                for(int j=0;j<4;j++){
                    //on retient la premiere valeur
                    if(!j)value = a[l].matrice[i][j];
                    if(j<3){
                        a[l].matrice[i][j]=a[l].matrice[i][j+1];
                    }
                    else{
                        //on remplace la 4 eme valeur par la premiere
                        a[l].matrice[i][j]=value;
                    }
                } 
            }
        }
    }    
}
