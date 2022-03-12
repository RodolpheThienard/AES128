#include "matrices.h"
#include "SubOctet.h"
#include "decalelignes.h"
int main (int argc, char* argv[]){

     /*Pour tester
     char *str = malloc(2048);
     strcpy(str,"Lorem ipsum dolor consectetur adipisicing elit. Vitae repellendus quod saepe eveniet asperiores nam et tenetur veniam delectus! Voluptas ");
     
     Block *l_mat_etat = create_list_block(str);
     int nb_block = strlen(str)/16 + 1;
     //print_list_block(l_mat_etat,nb_block);
     */

    
    //lecture(argv[1]);
    

    /*
     SubOctet(l_mat_etat,nb_block);
     print_list_block(l_mat_etat,nb_block); //(2)

    //Exemple DecaleLigne
    int ** a = malloc( 4*sizeof(int*) );
    for ( int i = 0; i<4; i++ )
    {
        a[i] = malloc( 4*sizeof(int) );
        for ( int j = 0; j<4; j++ )
        {
            a[i][j] = j;
        }
    }
    printf("Première matrice\n");
    display_matrix(4,4,a);
    printf("-------------\nMatrice Décalé\n");
    a = DecaleLignes(a);
    display_matrix(4,4,a);
    free_matrix(4,a);
    
     DecaleLignes(l_mat_etat,nb_block);

     free(str);
     free(l_mat_etat);
    */

     return 0;
}
