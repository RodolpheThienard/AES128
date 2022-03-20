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

int* binaire_hexa(int binary_number){
    
    int hexadecimal_number = 0, i = 1, remainder;

    while (binary_number != 0)
    {
        remainder = binary_number % 10;
        hexadecimal_number = hexadecimal_number + remainder * i;
        i = i * 2;
        binary_number = binary_number / 10;
    }
}

char *lecture(char *argv){

    FILE *fic = fopen(argv, "r") ;
    if (fic==NULL)
    {
        printf("Ouverture fichier impossible !");
        return NULL;
    }

    char ligne[100];
    char *text = malloc(sizeof(char*)+1);

    while (fgets(ligne, 100, fic)){
        // printf("%s", ligne);

        char *binary = chainebinaire(ligne);

        int taille = strlen(binary) + strlen(text);

        text = realloc(text, taille+1);
        text = strcat(text,binary);
        //printf("Text : %s\n\n", text);
        
    }

    // printf("text: %s\n", text);

    fclose(fic);

    return text;
}

void matrices(char *text){

    int i,j;

    int taille = strlen(text);
    int mod = taille / 8;
    // printf("taille : %d\nmod : %d\n", taille, mod);
    int *hexa = malloc(sizeof(int*)*8);
    int cpt = 1;

    if(taille == 128){
        for(i=0;i<mod;i++){
            for(j=0;j<8;j++){
                hexa[j] = text[j*cpt];
            }
            // printf("%dhexa : %ls\n", i,hexa);
            cpt++;
        }

        for(i=0;i<mod;i++){
            int temp = 0;
            for(j=0;j<8;j++){
                temp += hexa[j];
            }
            // printf("Temp : %d\n", temp);
        }
    }

    return ;
}