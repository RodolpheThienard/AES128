/// make fonction which XOR block with key
#include "../suboctet/suboctet.h"
#include "addroundkey.h"

void addroundkey(int **matrix, int **key)
{
    int keys[4][4] = {
            0x12, 0x45, 0xf6, 0x88,
            0x0f, 0x63, 0xc9, 0xc7,
            0x5b, 0x22, 0xa9, 0x00,
            0x85, 0xcf, 0x0a, 0xd8
        };
    
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                matrix[i][j] = matrix[i][j] ^ keys[i][j];
            }
        }
    
}