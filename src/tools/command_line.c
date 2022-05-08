#include "command_line.h"
#include "exec.h"
#include "tools.h"
#include "../nonce/nonce.h"

// La fonction command qui comme son nom l'inquide effectue la gestion des commandes.
int command(int argc, char **argv)
{
    // On verifie le nombre d'arguments et l'arguments souhaité. 
    // La fonction returnera un nombre en fonction de la commande et effectura les différentes actions possibles.
    // Càd l'encryptage/decrypatge, l'attaque, génération d'une nonce ou le nom du fichier de sortie.

    // -h pour help
    if(!strcmp(argv[1], "-h"))
    {
        return 3;
    }
    // -nonce pour générer une nonce aléatoire
    if(!strcmp(argv[1], "-nonce"))
    {
        char *nonce = get_nonce();
        printf("your random nonce is : %s\n", nonce);
        free(nonce);
        return 0;
    }
    if(argc < 3) return 3;
    if(strlen(argv[1]) != 16) return 5;
    if(strlen(argv[2]) != 16) return 6;
    int **key = str_to_matrix(argv[1]);
    int **nonce = str_to_matrix(argv[2]);
    for(int i = 2; i < argc; i++)
    {
        // -a pour l'attaque.
        if(!strcmp(argv[i], "-a"))
        {
            if(i == argc - 1) return 1;

            aes_attack(key, nonce);

        }

        // -e pour l'encryptage/décryptage par l'AES-128 et le CTR.
        if(!strcmp(argv[i], "-e"))
        {
            // On ouvre le fichier de lecture
            if(i == argc - 1) return 1;
            FILE *file = fopen(argv[i+1], "r");
            if(!file) return 4;
            
            // On créer le fichier de sortie
            char *outfile = calloc(11, sizeof(char));
            strcpy(outfile, "output.txt");
            for(int j = 0; j < argc; j++)
            {
                if(!strcmp(argv[j], "-out"))
                {
                    if(j == argc - 1) return 1;
                    if(i == j) return 2;
                    printf("i : %d\tj : %d\t argc : %d\n", i, j, argc);
                    outfile = realloc(outfile, strlen(argv[j+1])+1);
                    strcpy(outfile, argv[j+1]);
                }
            }

            // On effectue l'encryptage du fichier
            struct init_matrix *all_text = init_plaintext(file, argv[i+1] );
            aes_128(all_text, key, nonce);
            
            // On recopie le resultat dans le fichier de sortie
            write_to_file(all_text, outfile);

            free_matrix(key,4);
            free_matrix(nonce,4);
            fclose(file);
            free_attack_matrix(all_text);
            free(outfile);
            return 0;
        }
        
        
    }
    free_matrix(nonce, 4);
    free_matrix(key, 4);
    return 0;
}

// error_display permet l'affiche des erreurs en fonctions de la sortie de command.
void error_display(int error)
{
    switch(error)
    {
        case 0:
            break;
        case 1:
            printf("Error, insufisant argument !\n");
            goto help;
            break;
        case 2:
            printf("Error, Bad Format !\n");
            goto help;
            break;
        case 3:
            printf("Welcome in the help list !\n");
            goto help;
            break;
        case 4:
            printf("Error, Bad file's path !\n");
            break;
        case 5:
            printf("Error, Bad key's format !\nThe key need to be in 128bits (16 chars)\n");
            break;
        case 6:
            printf("Error, Bad nonce's format !\nThe nonce need to be in 128bits (16 chars)\nGenerate it with ./main -nonce\n");
            break;
        case 100:
            help:
            printf("Usage : ./main [KEY] [NONCE] [OPTION...] \n");
            printf("\t-nonce    \tGenerate random nonce, no argument is require!\n\t\t\tex: ./main -nonce\n");
            printf("\t-a        \tAttack mode\n");
            printf("\t-e file   \tEncryption/Decryption mode\n\t\t\tUsage: ./main -e foo.txt\n");
            printf("\t-out file \toutput filename, ONLY FOR -enc option\n");
            printf("\t-h        \tHelp page\n");
            break;
        default:
            break;
    }
    
}