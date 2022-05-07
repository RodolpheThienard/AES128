#include "tools.h"

int **create_matrix(int n, int m)
{
    int **matrix = calloc(m, sizeof(int*));

    for (int i =0; i < m; i++)
    {
        matrix[i] = calloc(n, sizeof(int));
    }
    return matrix;
}

void copy_matrix(int **matrix, int **new_matrix)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matrix[i][j] = new_matrix[i][j];
        }
    }
}

void free_matrix(int **matrix, int n)
{
    for (int i =0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void print_matrix(int **matrix, int n, int m)
{
    for (int i =0; i < n; i++)
    {
        for (int j =0; j < m; j++)
        {
           printf("%2x ", matrix[i][j]); 
        }
        printf("\n");
    }

}

void print_box(struct chained_matrix *n)
{
     while(n->next)
     {
          print_box(n->next);
          break;
     }
     print_matrix(n->matrix, 4, 4);
}