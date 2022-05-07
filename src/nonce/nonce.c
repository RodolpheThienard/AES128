#include "nonce.h"
#include <stdlib.h>
#include <stdio.h>


char *get_nonce()
{
    const char nonce_library[63] = "qazxswedcvfrtgbnhyujmkilop1234567890-_=+)*(&^%$!#@/?.,'\";]{[}:";
    char *nonce = calloc(16, sizeof(char));

    unsigned int randval;
    FILE *rand_file = fopen("/dev/random", "r");

    for (int i = 0; i < 16; i++)
    {
        fread(&randval, sizeof(randval), 1, rand_file);
        nonce[i] = nonce_library[randval%63];
        
    }

    fclose(rand_file);
    return nonce;
}