#include "tools.h"

// Créer des matrices de taille n et m.
int **create_matrix(int n, int m)
{
    int **matrix = calloc(n, sizeof(int*));

    for (int i =0; i < n; i++)
    {
        matrix[i] = calloc(m, sizeof(int));
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

//return 0 if the matrix are the same, 1 otherwise
int cmp_matrix(int **matrix1, int **matrix2, int n, int m)
{
    for (int i =0; i < n; i++)
    {
        for (int j =0; j < m; j++)
        {
           if(matrix1[i][j] != matrix2[i][j])
           {
               return 1;
           }
        }
    }
    return 0;
}

void hex_to_str(int **matrix)
{

    for(int i = 0; i < 16; i++)
    {
        printf("%c", matrix[i/4][i%4]);
    }
    printf("\n");
}