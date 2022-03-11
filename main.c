#include "matrices.h"
#include "decalelignes.h"

int main(int argc, char **argv){  

    printf("Hello world !\n");

    lecture(argv[1]);

    /*
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
    */

    return 0;
}