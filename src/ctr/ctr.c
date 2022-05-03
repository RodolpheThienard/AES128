#include "ctr.h"


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

void loop_ctr(struct chained_matrix *chained, int **matrix, int **extended_key, int turns)
{
    while(chained->next)
    {
        loop_ctr(chained->next, matrix, extended_key, turns);
        break;
    }
    counter_mode(matrix, extended_key, chained->matrix, turns);
}