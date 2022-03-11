#include "matrices.h"

void lecture(char *argv){

    FILE *fic = fopen(argv, "r") ;
    if (fic==NULL)
    {
        printf("Ouverture fichier impossible !");
        return;
    }

    char ligne[100];

    while (fgets(ligne, 100, fic)){
        printf("%s", ligne);
    }

    fclose(fic);
}