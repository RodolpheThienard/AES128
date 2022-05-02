#include "command_line.h"

int command(int argc, char **argv)
{
    if(argc < 3) return 1;
    for(int i = 1; i < argc; i++)
    {
        if(!strcmp(argv[i], "-a"))
        {
            if(i == argc) return 2;
        }
        if(!strcmp(argv[i], "-e"))
        {
            if(i == argc) return 2;
        }
        if(!strcmp(argv[i], "-h"))
        {
            return 3;
        }
    }
}

void error_display(int error)
{
    switch(error)
    {
        case 0:
            break;
        case 1:
            printf("Error, insufisant arguments !\n");
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
            break;
        default:
            help:
            printf("Usage : ./main [OPTION...] \n");
            printf("\t-a        \t\tAttack mode\n");
            printf("\t-e file   \tEncryption/Decryption mode\n\t\t\tUsage: ./main -e foo.txt\n");
            printf("\t-h        \t\tHelp page\n");
            break;
    }
}