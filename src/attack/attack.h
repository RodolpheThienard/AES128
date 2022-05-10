#ifndef ATTACK_H
#define ATTACK_H
#include "../tools/tools.h"
#include "../aes/aes.h"
#include "../key_reduction/key_reduction.h"

struct init_matrix* define_attack_matrix();
void free_attack_matrix(struct init_matrix *init);
void free_chained_matrix(struct chained_matrix *matrix);
struct chained_matrix* copy_chained_matrix(struct chained_matrix *matrix);
int** attack_4turns(struct init_matrix *init);
int xor(struct chained_matrix *init, int k, int l);
void suboctet_inverse(int* matrix,int a);
int **find_k4(int **key, struct init_matrix *attacked_matrix);

#endif