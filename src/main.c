#include "matrices/matrices.h"
#include "suboctet/suboctet.h"
#include "decalelignes/decalelignes.h"
#include "melangecolonnes/melangecolonnes.h"
#include "addroundkey/addroundkey.h"
#include "key_extension/key_extension.h"
#include "tools/tools.h"
#include "ctr/ctr.h"
#include "aes/aes.h"
#include "attack/attack.h"
#include "tools/command_line.h"
#include <pthread.h>
#include <sys/stat.h>

struct init_matrix *init_plaintext(char *is_file)
{
     FILE *file = fopen(is_file, "r");
     struct stat *file_stat = calloc(1, sizeof(struct stat));
     stat(is_file, file_stat);
     int size = file_stat->st_size;
     int matrix_amount = size/16;
     if(size%16 != 0) matrix_amount++;
     printf("%d\t%d\t%c\n", size, matrix_amount,70);

     struct chained_matrix *chained= calloc(1, sizeof(struct chained_matrix));
     struct init_matrix *init = calloc(1, sizeof(struct init_matrix));
     init->init = chained;
     for(int i = 0; i < matrix_amount; i++)
     {
          int **current_matrix = create_matrix(4, 4);

          for(int j = 0; j < 16; j++)
          {
               int val = fgetc(file);
               if (val == EOF) current_matrix[j/4][j%4] = 0;
               else current_matrix[j/4][j%4] = val;
          }
          chained->matrix = current_matrix;
          if(i == matrix_amount-1)
          {
               chained->next = NULL;
               fclose(file);
               free(file_stat);
               return init;
          }
          struct chained_matrix *next_chained= calloc(1, sizeof(struct chained_matrix));
          
          chained->next = next_chained;
          chained = next_chained;
     }
     fclose(file);
     free(file_stat);
     return init;
     
}

int write_to_file(struct init_matrix *init)
{
     FILE *file = fopen("output.txt", "w");
     struct chained_matrix *matrix = init->init;
     char *output = calloc(16, sizeof(char));
     int j = 0;
     while(matrix)
     {
          j++;
          output = realloc(output, j*16);
          for(int i = 0; i < 16; i++)
          {
               sprintf(output, "%s%c", output, matrix->matrix[i/4][i%4]);
               
          }
          matrix = matrix->next;
          
     }
     fwrite(output, 16, j, file);
     free(output);
     fclose(file);
     return 0;
}

void aes_128(struct init_matrix *init)
{
     int **master_key = create_matrix(4, 4);
     int **extended_key = create_matrix(4, 44);
     int **nonce_matrix = create_matrix(4, 4);

     // Random key
     int keys[4][4] = {
            {0x49, 0x55, 0x49, 0x49},
            {0x49, 0x49, 0x49, 0x49},
            {0x49, 0x49, 0x49, 0x49},
            {0x49, 0x49, 0x49, 0x49}
     };

     int random[4][4] = {
            {0x49, 0x55, 0x49, 0x49},
            {0x49, 0x49, 0x49, 0x49},
            {0x49, 0x49, 0x49, 0x49},
            {0x49, 0x49, 0x49, 0x49}
     };

     for (int i = 0; i < 4; i++)
     {
          for (int j = 0; j < 4; j++)
          {
               master_key[i][j] = keys[i][j];
               nonce_matrix[i][j] = random[i][j];
          }
     }

     key_extension(master_key, extended_key);

     struct chained_matrix *chained = init->init;
     loop_ctr(chained, nonce_matrix, extended_key, 10);


     free_matrix(nonce_matrix, 4);
     free_matrix(extended_key, 44);
     free_matrix(master_key, 4);
}

void aes_attack(int argc, char **argv)
{
     int **master_key = create_matrix(4, 4);
     int **extended_key = create_matrix(4, 44);
     int **nonce_matrix = create_matrix(4, 4);

     // Random key
     int keys[4][4] = {
            {0x55, 0x55, 0x49, 0x49},
            {0x49, 0x49, 0x49, 0x49},
            {0x49, 0x49, 0x49, 0x49},
            {0x49, 0x49, 0x49, 0x49}
     };

     int random[4][4] = {
            {0x49, 0x55, 0x49, 0x49},
            {0x49, 0x49, 0x49, 0x49},
            {0x49, 0x49, 0x49, 0x49},
            {0x49, 0x49, 0x49, 0x49}
     };

     for (int i = 0; i < 4; i++)
     {
          for (int j = 0; j < 4; j++)
          {
               master_key[i][j] = keys[i][j];
               nonce_matrix[i][j] = random[i][j];
          }
     }

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

     free_matrix(nonce_matrix, 4);
     free_matrix(extended_key, 44);
     free_matrix(master_key, 4);
     free_attack_matrix(attack);
}

int main(int argc, char **argv)
{
     int error = command(argc, argv);
     error_display(error);
     if(error) return 0;

     struct init_matrix *all_text = init_plaintext(argv[2]);

     printf("%c%c\n",0x49,0x55);
     // creation_matrice(argv[1]);
     aes_128(all_text);
     //aes_attack(argc, argv);

     write_to_file(all_text);

     free_attack_matrix(all_text);
}


int backup (int argc, char **argv)
{

     // float nonce;
     // FILE *thermal;
     // int n;


     // thermal = fopen("/sys/class/thermal/thermal_zone2/temp","r");
     // n = fscanf(thermal,"%f",&nonce);
     // fclose(thermal);

     // printf("%f\n\n", nonce);

     // (void) argc;
     // (void) argv;

     
     int **master_key = create_matrix(4, 4);
     int **extended_key = create_matrix(4, 44);
     int **nonce_matrix = create_matrix(4, 4);

     // Random key
     int keys[4][4] = {
            {0x49, 0x55, 0x49, 0x49},
            {0x49, 0x49, 0x49, 0x49},
            {0x49, 0x49, 0x49, 0x49},
            {0x49, 0x49, 0x49, 0x49}
     };

     int random[4][4] = {
            {0x49, 0x55, 0x49, 0x49},
            {0x49, 0x49, 0x49, 0x49},
            {0x49, 0x49, 0x49, 0x49},
            {0x49, 0x49, 0x49, 0x49}
     };

     for (int i = 0; i < 4; i++)
     {
          for (int j = 0; j < 4; j++)
          {
               master_key[i][j] = keys[i][j];
               nonce_matrix[i][j] = random[i][j];
          }
     }

     key_extension(master_key, extended_key);

     // print_matrix(extended_key, 44, 4);

     

     //Pour tester
     // char *str = malloc(2048);
     // strcpy(str,"je suis un genti");
     
     // int **plaintext = create_list_block(str);


     // ATTACK

     struct init_matrix *attack = define_attack_matrix();

     attack_4turns(attack);
     

     // CTR 

     counter_mode(nonce_matrix, extended_key, attack->init->matrix, 4);

     print_matrix(attack->init->matrix, 4, 4);

     // for (int i =0; i < 4; i++)
     // {
     //      for (int j =0; j < 4; j++)
     //      {
     //           printf("%c \n", (plaintext[i][j]));
     //      }
     // }

     

     if(argc != 2){
           printf("Too many arguments or Too few arguments");
           return 1;
     }

     
     


     // int **matrix2 = create_matrix(4, 4);
     // matrix2[0][1] = 0x64;
     // matrix2[0][2] = 0x65;

     //        char *binary = lecture(argv[1]);
     
     // creation_matrice(argv[1]);

     //        matrices(binary);

     //        free(binary);
     
     // print_matrix(matrix2, 4, 4);
     // printf("\n");

     // aes(matrix2 , extended_key);
     // print_matrix(matrix2, 4, 4);
     // printf("\n");
     
     // print_matrix(matrix, 4, 4);

     // for(int i = 0; i < 4; i++)
     // {
     //      for(int j = 0; j < 4; j++)
     //      {
     //           matrix[i][j] = matrix[i][j] ^ matrix2[i][j];
     //      }   
     // }
     // printf("ENDDD :\n");

     // print_matrix(matrix, 4, 4);

     // char output[16];
     // for (int i =0; i < 4; i++)
     // {
     //      for (int j =0; j < 4; j++)
     //      {
     //           output[i*4 +j]= matrix[i][j]; 
     //           printf("%c \n", (output[i*4 +j]));
     //      }
     // }
     // FILE *file = fopen("result.txt", "w");
     // fwrite(output, 1, sizeof(output), file);


     // free(str);
     // free_matrix(plaintext, 4);
     free_matrix(nonce_matrix, 4);
     free_matrix(extended_key, 44);
     free_matrix(master_key, 4);
     free_attack_matrix(attack);

     return 0;
}
