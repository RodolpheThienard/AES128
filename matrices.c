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

        char *token = strtok(ligne, " ");
        int i = atoi("78");

        printf("\ntoken : %s \natoi: %d\n", token, i);
    }

    fclose(fic);
}