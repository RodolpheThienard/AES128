#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
     int id;
     int matrice [4][4];
}Block;

Block *create_list_block(char *str);
void print_list_block(Block *b,int nb_block);
void SubOctet (Block *l_mat_etat,int nb_block);