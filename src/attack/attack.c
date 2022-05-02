#include "attack.h"
#include "../tools/tools.h"

/* 
    Calloc donc pas besoin de définir les autres états.
    return struct init_matrix (containing all matrix)
*/
struct init_matrix* define_attack_matrix()
{
    struct chained_matrix *init = calloc(1, sizeof(struct chained_matrix));
    struct init_matrix *init_matrix = calloc(1, sizeof(struct init_matrix));
    init_matrix->init = init;

    for(int i = 0; i < 255; i++)
    {
        int **new_matrix = create_matrix(4, 4); 
        new_matrix[0][0] = i;
        init->matrix = new_matrix;
        if(i == 254)
        {
            init->next = NULL;
            return init_matrix;
        }
        struct chained_matrix *next_matrix = calloc(1, sizeof(struct chained_matrix));
        init->next = next_matrix;
        init = next_matrix;
    }

}


void free_attack_matrix(struct init_matrix *init)
{
    free_chained_matrix(init->init);
    free(init);
}

void free_chained_matrix(struct chained_matrix *matrix)
{
    if(matrix->next)
    {
        free_chained_matrix(matrix->next);
    }
    free_matrix(matrix->matrix, 4);
    free(matrix);
}
