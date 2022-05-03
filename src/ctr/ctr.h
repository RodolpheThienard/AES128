#ifndef CTR_H
#define CTR_H
#include "../aes/aes.h"
#include "../tools/tools.h"

void loop_ctr(struct chained_matrix *chained, int **matrix, int **extended_key, int turns);
void counter_mode(int **matrix, int **extended_key, int **plaintext, int turns);

#endif 