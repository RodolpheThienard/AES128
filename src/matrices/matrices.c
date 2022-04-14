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

void creation_matrice(char *argv)
{
    struct stat *stats; 
    stats = malloc(sizeof(struct stat));

    stat(argv, stats);
    int taille = stats->st_size;

    printf("%d\n",taille);

    int nbr_matrice = taille / 16;
    int verif = taille % 16;
    if (verif > 0){
        nbr_matrice++;
    }
    //printf("Nombre de matrices a faire : %d\n", nbr_matrice);

    FILE *fic = fopen(argv, "r") ;
    if (fic==NULL)
    {
        printf("Ouverture fichier impossible !");
        return ;
    }

    char* contenu = malloc(sizeof(char*)*taille);
    char temp[100];

    while(fgets(temp, 100, fic)){
        strcat(contenu, temp);
    }
    // printf("%staille : %ld\n", contenu, strlen(contenu));


    char hexadecimal[(taille*2)+1];
    //sprintf((char*)(hexadecimal),"%02X", contenu[1]);

    int i,j; 
    i=0;
    j=0;
    
    while(contenu[j] != '\0')
    {
        sprintf((char*)(hexadecimal+i),"%02X", contenu[j]);
        j+=1;
        i+=2;
    }
    hexadecimal[i++] = '\0';
    printf("Hexa: %s\n", hexadecimal);
    //printf("hexa : %c%c contenu : %c\n", hexadecimal[0], hexadecimal[1], contenu[1]); //attention une lettre = 2 places dans hexadecimal

    free(stats);
    //free(temp);
    free(contenu);
    fclose(fic);
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
            //printf("%dhexa : %ls\n", i,hexa);
            cpt++;
        }

        for(i=0;i<mod;i++){
            int temp = 0;
            for(j=0;j<8;j++){
                temp += hexa[j];
            }
            //printf("Temp : %d\n", temp);
        }
    }
    
}