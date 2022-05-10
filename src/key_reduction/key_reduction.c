#include "key_reduction.h"


void key_reduction(int **master_key, int **extended_key, int turns)
{
    int rcon[10] = {
        0x01, 0x02, 0x04, 0x08,
        0x10, 0x20, 0x40, 0x80,
        0x1b, 0x36
    };

    int** key = create_matrix(20, 4);
    for(int i = 16;i < 20;i++)
    {
        for(int j = 0;j < 4;j++)
        {   
            key[i][j] = extended_key[i-16][j];
        }
    }

    // On créer la matrice tampon
    int *tampon = calloc(4, sizeof(int));
    for (int i = (4*(turns+1))-1; i > 3; i--)
    {        
            // On copie la clé étendue dans la clé tampon
            memcpy(tampon, key[i-1], 16);
            

            if (i % 4 == 0) 
            {
                // On effectue SubOctet(RotationOctet(tampon))
                tampon = suboctect_tampon(rotation_left(tampon));
                for(int j = 0; j < 4; j++)
                {
                        // On fait le Xor
                        tampon[j] ^= rcon[j / 4];
                }
            }
        

        for(int j = 0; j < 4; j++)
        {
          key[i-4][j] = key[i][j] ^ tampon[j]; 
        }

    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            master_key[i][j] = key[i][j];
        }
    }
    free(tampon);
    free_matrix(key, 20);
}