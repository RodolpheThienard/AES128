void aes(int **matrix, int **extended_key)
{
     addroundkey(matrix, extended_key);
     for(int i = 1; i < 10; i++)
     {
          turn(matrix, extended_key + i*4);
     }
     last_turn(matrix, extended_key + 40);
}

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