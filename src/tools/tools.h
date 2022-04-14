#ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>
#include <stdlib.h>

int **create_matrix(int n, int m);
void copy_matrix(int **matrix, int **new_matrix);
void print_matrix(int **matrix, int n, int m);
void free_matrix(int **matrix, int n);

#endif