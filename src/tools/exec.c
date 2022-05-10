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
     printf("-----Original Master Key-----\n");
     for(int i = 0; i < 4; i++)
     {
          printf("\t");
     for(int j = 0; j < 4; j++)
     {
          printf("%2x ", master_key[i][j]);
     }
          printf("\n");
     }
     printf("\n");
     
     printf("-----Extended Key 4th turn-----\n");
     for(int i = 16; i < 20; i++)
     {
          printf("\t");
          for(int j = 0; j < 4; j++)
          {
               printf("%2x ", extended_key[i][j]);
          }
          printf("\n");
     }
     printf("\n");

     // ATTACK

     struct init_matrix *attack = define_attack_matrix();


     struct chained_matrix *matrix = attack->init;
     for(int i = 0; i < 256; i++)
     {
          aes(matrix->matrix, extended_key, 4);
          matrix = matrix->next;
     }


     int** tmpK4 = attack_4turns(attack);

     int** result = test_a(master_key, tmpK4);
     if(result != NULL){
          printf("-----Result-----\n");
          print_matrix(result, 4, 4);
     }
     else printf("No result found\n");

     // int tmp[4][4] =  {
     //      {0x67, 0x49, 0x4e, 0x7b},
     //      {0x82, 0x5c, 0x5b, 0x46},
     //      {0x43, 0x95, 0x88, 0xa6},
     //      {0x50, 0xb1, 0x1e, 0x09}
     // };

     //on cree une matrice sensé contenir la clé étendu et on place K(4) à la fin
     int** K4 = create_matrix(4, 4);
     for(int i = 0;i < 4;i++)
     {
          for(int j = 0;j < 4;j++)
          {   
               K4[i][j] = tmpK4[((i)*4)+j][0];
               // K4[i][j] = tmp[i-16][j];
          }
     }
     printf("-Matrice K4-\n");
     print_matrix(K4, 4,4);

     int** K = create_matrix(4, 4);
     key_reduction(K,K4,4);
     printf("-Matrice K -\n");
     print_matrix(K, 4, 4);
     
    

     // CTR 

     //counter_mode(nonce_matrix, extended_key, attack->init->matrix, 4);

     //print_matrix(attack->init->matrix, 4, 4);
     free_matrix(tmpK4, 16);
     free_matrix(K4, 4);
     free_matrix(K, 4);
     free_matrix(extended_key, 44);
     free_attack_matrix(attack);
}