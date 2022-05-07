#ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>
#include <stdlib.h>

struct chained_matrix
{
    int **matrix;
    struct chained_matrix *next;
};

struct init_matrix
{
    struct chained_matrix *init;   
};

int **create_matrix(int n, int m);
void copy_matrix(int **matrix, int **new_matrix);
void print_matrix(int **matrix, int n, int m);
void free_matrix(int **matrix, int n);
void print_box(struct chained_matrix *n);

#endif