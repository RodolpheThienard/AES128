#include "ctr.h"

// Permet de faire les 10 tours d'AES-128 et de chiffrer les matrices en faisant un XOR avec la nonce.
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

// Permet de faire le chiffrement CTR en nous plaçant au début de la liste chainée.
void loop_ctr(struct chained_matrix *chained, int **matrix, int **extended_key, int turns)
{
    while(chained->next)
    {
        loop_ctr(chained->next, matrix, extended_key, turns);
        break;
    }
    counter_mode(matrix, extended_key, chained->matrix, turns);
}