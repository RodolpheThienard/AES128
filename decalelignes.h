#include <stdio.h>
#include <stdlib.h>

void free_matrix(int x,int** tab);
int** DecaleLignes(int** a);
//Pour fonctionner avec la struct Block
// void DecaleLignes(Block* a, int nb_block);
void display_matrix(int x, int y, int** tab);