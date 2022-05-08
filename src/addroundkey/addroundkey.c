/// make fonction which XOR block with key
#include "../suboctet/suboctet.h"
#include "addroundkey.h"

// addroundkey effectue la AjouteCléTour
void addroundkey(int **matrix, int **key)
{    
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                // On fait le XOR entre la matrice et la clé tour
                matrix[i][j] = matrix[i][j] ^ key[i][j];
            }
        }
}