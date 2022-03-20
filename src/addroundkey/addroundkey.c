/// make fonction which XOR block with key
#include "../suboctet/suboctet.h"
#include "addroundkey.h"

void addroundkey(int **matrix, int **key)
{    
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                matrix[i][j] = matrix[i][j] ^ key[i][j];
            }
        }
    
}