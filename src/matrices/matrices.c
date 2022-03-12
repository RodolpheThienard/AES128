#include "matrices.h"

char* chainebinaire(char* s) {

    if(s == NULL) return 0;
    size_t len = strlen(s);
    char *binary = malloc(len*8 + 1);
    binary[0] = '\0';

    for(size_t i = 0; i < len; ++i) {
        char ch = s[i];
        for(int j = 7; j >= 0; --j){
            if(ch & (1 << j)) {
                strcat(binary,"1");
            } else {
                strcat(binary,"0");
            }
        }
    }

    return binary;
}

char *lecture(char *argv){

    FILE *fic = fopen(argv, "r") ;
    if (fic==NULL)
    {
        printf("Ouverture fichier impossible !");
        return;
    }

    char ligne[100];

    while (fgets(ligne, 100, fic)){
        printf("%s", ligne);

        char *binary = chainebinaire(ligne);
        printf("%s\n", binary); 

    }

    fclose(fic);
}