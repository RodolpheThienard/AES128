#include "../suboctet/suboctet.h"
#include "decalelignes.h"
#include "../tools/tools.h"

void decale_lignes(int **matrix){
    int** tmp = create_matrix(4, 4);
    copy_matrix(tmp, matrix);
    for (int i = 0; i < 4; i++)
    {
        int tmp[4] = {matrix[i][0], matrix[i][1], matrix[i][2], matrix[i][3]};
        for (int j = 0; j < 4; ++j)
        {
            matrix[i][j] = tmp[(j + i) % 4];
        }
    } 
    free_matrix(tmp, 4);
}