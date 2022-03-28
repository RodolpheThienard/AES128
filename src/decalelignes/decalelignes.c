#include "../suboctet/suboctet.h"
#include "decalelignes.h"
#include "../tools/tools.h"

void decale_lignes(int **matrix){
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; ++j)
        {
            matrix[i][j] = matrix[i][(j + i) % 4];
        }
    } 
}