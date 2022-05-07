#include "command_line.h"
#include "exec.h"
#include "tools.h"

int command(int argc, char **argv)
{
    if(argc < 3) return 1;
    if(strlen(argv[1]) != 16) return 5;
    for(int i = 2; i < argc; i++)
    {
        if(!strcmp(argv[i], "-a"))
        {
            if(i == argc - 1) return 1;

            int **key = format_key(argv[1]);
            aes_attack(key);
            
            free_matrix(key, 4);
            return 0;
        }
        if(!strcmp(argv[i], "-e"))
        {
            
            if(i == argc - 1) return 1;
            FILE *file = fopen(argv[i+1], "r");
            if(!file) return 4;
            
            char *outfile = calloc(11, sizeof(char));
            strcpy(outfile, "output.txt");
            for(int j = 0; j < argc; j++)
            {
                if(!strcmp(argv[j], "-out"))
                {
                    if(j == argc - 1) return 1;
                    if(i == j) return 2;
                    printf("i : %d\tj : %d\t argc : %d\n", i, j, argc);
                    outfile = realloc(outfile, strlen(argv[j+1]));
                    strcpy(outfile, argv[j+1]);
                }
            }

            int **key = format_key(argv[1]);
            struct init_matrix *all_text = init_plaintext(file, argv[i+1] );
            aes_128(all_text, key);

            write_to_file(all_text, outfile);

            fclose(file);
            free_matrix(key, 4);
            free_attack_matrix(all_text);
            free(outfile);
            return 0;
        }
        if(!strcmp(argv[i], "-h"))
        {
            return 3;
        }
        
    }
    return 0;
}

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
        case 100:
            help:
            printf("Usage : ./main [KEY] [OPTION...] \n");
            printf("\t-a        \tAttack mode\n");
            printf("\t-e file   \tEncryption/Decryption mode\n\t\t\tUsage: ./main -e foo.txt\n");
            printf("\t-out file \toutput filename, ONLY FOR -enc option\n");
            printf("\t-h        \tHelp page\n");
            break;
        default:
            break;
    }
    
}