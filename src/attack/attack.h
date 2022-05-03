#ifndef ATTACK_H
#define ATTACK_H
#include "../tools/tools.h"

struct init_matrix* define_attack_matrix();
void free_attack_matrix(struct init_matrix *init);
void free_chained_matrix(struct chained_matrix *matrix);
void attack_4turns(struct init_matrix *init);
int xor(struct init_matrix *init);
void suboctet_inverse(int **matrix, int a);

#endif