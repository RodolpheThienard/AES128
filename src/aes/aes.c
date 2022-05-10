#include "aes.h"

//Effectue un tour d'AES sur une matrice avec une clé précédemment crée
void turn(int **matrix, int **key)
{
     suboctet(matrix);
     decale_lignes(matrix);
     melange_colonnes(matrix);
     addroundkey(matrix, key);
}

//Effectue le dernier tour d'AES sans mélanger les colonnes
void last_turn(int **matrix, int **key)
{
     suboctet(matrix);
     decale_lignes(matrix);
     addroundkey(matrix, key);
}

//Effectue autant de tours d'AES que ceux mis en argument et se termine par un tour sans mélanger les colonnes
void aes(int **matrix, int **extended_key, int turns)
{
     addroundkey(matrix, extended_key);
     int i;
     for(i = 1; i < turns; i++)
     {
          turn(matrix, extended_key + i*4);
     }
     last_turn(matrix, extended_key + i*4);
}
