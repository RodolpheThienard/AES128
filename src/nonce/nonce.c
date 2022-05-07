#include "nonce.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

char *get_nonce()
{
    char *nonce = calloc(16, sizeof(char));

    int random[4][4] = {
            {0x49, 0x55, 0x49, 0x49},
            {0x49, 0x49, 0x49, 0x49},
            {0x49, 0x49, 0x49, 0x49},
            {0x49, 0x49, 0x49, 0x49}
     };

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            nonce[i*4+j] = random[i][j];
        }
    }

    return nonce;
}