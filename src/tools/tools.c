#include "tools.h"

// Créer des matrices de taille n et m.
int **create_matrix(int n, int m)
{
    int **matrix = calloc(m, sizeof(int*));

    for (int i =0; i < m; i++)
    {
        matrix[i] = calloc(n, sizeof(int));
    }
    return matrix;
}

// Permet de copier une matrices dans une autre matrice.
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

// Permet de libérer la mémoire des matrices malloc.
void free_matrix(int **matrix, int n)
{
    for (int i =0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

// Permet d'afficher une matrice.
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

// Permet d'afficher une liste chainé de matrice.
void print_box(struct chained_matrix *n)
{
     while(n->next)
     {
          print_box(n->next);
          break;
     }
     print_matrix(n->matrix, 4, 4);
}