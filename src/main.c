#include "matrices/matrices.h"
#include "suboctet/suboctet.h"
#include "decalelignes/decalelignes.h"
#include "melangecolonnes/melangecolonnes.h"
#include "addroundkey/addroundkey.h"
#include "key_extension/key_extension.h"
#include "tools/tools.h"

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

int main (int argc, char **argv){

     (void) argc;
     (void) argv;

     int **master_key = create_matrix(4, 4);
     int **extended_key = create_matrix(4, 44);

     // Random key
     int keys[4][4] = {
            {0x49, 0x49, 0x49, 0x49},
            {0x49, 0x49, 0x49, 0x49},
            {0x49, 0x49, 0x49, 0x49},
            {0x49, 0x49, 0x49, 0x49}
     };

     for (int i = 0; i < 4; i++)
     {
          for (int j = 0; j < 4; j++)
          {
               master_key[i][j] = keys[i][j];
          }
     }

     key_extension(master_key, extended_key);

     // print_matrix(extended_key, 44, 4);

     
     //Pour tester
     char *str = malloc(2048);
     strcpy(str,"Lorem ipsum dolor consectetur adipisicing elit. Vitae repellendus quod saepe eveniet asperiores nam et tenetur veniam delectus! Voluptas ");

     
     
     
     int **matrix = create_list_block(str);     

     if(argc != 2){
          printf("Too many arguments or Too few arguments");
          return 1;
     }

     // char *binary = lecture(argv[1]);

     // matrices(binary);

     // free(binary);
     
     print_matrix(matrix, 4, 4);
     printf("\n");

     aes(matrix, extended_key);
     print_matrix(matrix, 4, 4);

     
     free(str);
     free_matrix(matrix, 4);
     free_matrix(extended_key, 11);
     free_matrix(master_key, 4);

     return 0;
}
