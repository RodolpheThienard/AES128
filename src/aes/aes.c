#include "../suboctet/suboctet.h"
#include "../decalelignes/decalelignes.h"
#include "../melangecolonnes/melangecolonnes.h"
#include "../addroundkey/addroundkey.h"
#include "../key_extension/key_extension.h"
#include "../tools/tools.h"
#include "../ctr/ctr.h"


void turn(int **matrix, int **key)
{
     suboctet(matrix);
     decale_lignes(matrix);
     melange_colonnes(matrix);
     addroundkey(matrix, key);
}

void last_turn(int **matrix, int **key)
{
     suboctet(matrix);
     decale_lignes(matrix);
     addroundkey(matrix, key);
}

void aes(int **matrix, int **extended_key, int turns)
{
     addroundkey(matrix, extended_key);
     for(int i = 1; i < turns; i++)
     {
          turn(matrix, extended_key + i*4);
     }
     last_turn(matrix, extended_key + 40);
}
