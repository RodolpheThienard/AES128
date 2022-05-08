#include "exec.h"

void aes_128(struct init_matrix *init, int **master_key, int **nonce)
{
     int **extended_key = create_matrix(4, 44);

     key_extension(master_key, extended_key);

     struct chained_matrix *chained = init->init;
     loop_ctr(chained, nonce, extended_key, 10);

     free_matrix(extended_key, 44);
}

void aes_attack(int **master_key, int **nonce)
{
     int **extended_key = create_matrix(4, 44);


     key_extension(master_key, extended_key);

     // ATTACK

     struct init_matrix *attack = define_attack_matrix();


     struct chained_matrix *matrix = attack->init;
     for(int i = 0; i < 256; i++)
     {
          aes(matrix->matrix, extended_key, 4);
          matrix = matrix->next;
     }

     attack_4turns(attack);
     
    

     // CTR 

     //counter_mode(nonce_matrix, extended_key, attack->init->matrix, 4);

     //print_matrix(attack->init->matrix, 4, 4);
     
     free_matrix(extended_key, 44);
     free_attack_matrix(attack);
}