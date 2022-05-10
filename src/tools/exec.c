#include "exec.h"

// Effectue l'AES-128 finale avec le chiffrement CTR
void aes_128(struct init_matrix *init, int **master_key, int **nonce)
{
     int **extended_key = create_matrix(44, 4);

     key_extension(master_key, extended_key,10);

     struct chained_matrix *chained = init->init;
     loop_ctr(chained, nonce, extended_key, 10);

     free_matrix(extended_key, 44);
}

// Effectue l'attaque sur l'AES-128 de 4 tours.
void aes_attack(int **master_key, int **nonce)
{
     int **extended_key = create_matrix(44, 4);
     

     key_extension(master_key, extended_key, 4);

               //AFFICHAGE TEMPORAIRE DE MASTER_KEY AND EXTENDED_KEY(4)
     printf("-----Original Master Key-----\nOnly for verif, unknown values\n\n");
     print_matrix(master_key, 4, 4);


     struct init_matrix *attack = define_attack_matrix();


     struct chained_matrix *matrix = attack->init;
     for(int i = 0; i < 256; i++)
     {
          aes(matrix->matrix, extended_key, 4);
          matrix = matrix->next;
     }


     int** tmpK4 = attack_4turns(attack);

     int** result = test_a(master_key, tmpK4, attack);
     if(result != NULL){
          printf("-----Result-----\n");
          print_matrix(result, 4, 4);
          printf("-----Result-----\n");
          hex_to_str(result);
     }
     else printf("No result found\n");

     free_matrix(tmpK4, 16);
     free_matrix(result, 4);
     free_matrix(extended_key, 44);
     free_attack_matrix(attack);
}