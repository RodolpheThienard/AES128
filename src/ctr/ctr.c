#include "ctr.h"
#include "../aes/aes.h"

void counter_mode(int **matrix, int **extended_key, int **plaintext, int turns)
{
    aes(matrix, extended_key, turns);
    
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            plaintext[i][j] ^= matrix[i][j];
        }   
    }
}