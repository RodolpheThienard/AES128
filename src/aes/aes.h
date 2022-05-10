#ifndef AES_H
#define AES_H
#include "../suboctet/suboctet.h"
#include "../decalelignes/decalelignes.h"
#include "../melangecolonnes/melangecolonnes.h"
#include "../addroundkey/addroundkey.h"
#include "../key_extension/key_extension.h"
#include "../tools/tools.h"
#include "../ctr/ctr.h"

void aes(int **matrix, int **extended_key, int turns);
void turn(int **matrix, int **key);
void last_turn(int **matrix, int **key);

#endif