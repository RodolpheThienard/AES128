#ifndef EXEC_H
#define EXEC_H

#include "tools.h"
#include "../ctr/ctr.h"
#include "../attack/attack.h"
#include "../plaintext/plaintext.h"
#include "../key_extension/key_extension.h"

void aes_128(struct init_matrix *init, int **master_key, int **nonce);
void aes_attack(int **master_key, int **nonce);

#endif