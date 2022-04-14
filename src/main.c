#include "matrices/matrices.h"
#include "suboctet/suboctet.h"
#include "decalelignes/decalelignes.h"
#include "melangecolonnes/melangecolonnes.h"
#include "addroundkey/addroundkey.h"
#include "key_extension/key_extension.h"
#include "tools/tools.h"
#include "ctr/ctr.h"
#include "aes/aes.h"
#include <pthread.h>

int main (int argc, char **argv){

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
     char *str = malloc(2048);
     strcpy(str,"je suis un genti");
     
     int **plaintext = create_list_block(str);

     // CTR 

     counter_mode(nonce_matrix, extended_key, plaintext);


     print_matrix(plaintext, 4, 4);

     for (int i =0; i < 4; i++)
     {
          for (int j =0; j < 4; j++)
          {
               printf("%c \n", (plaintext[i][j]));
          }
     }

          

     // if(argc != 2){
     //      printf("Too many arguments or Too few arguments");
     //      return 1;
     // }

     // int **matrix2 = create_matrix(4, 4);
     // matrix2[0][1] = 0x64;
     // matrix2[0][2] = 0x65;

     // // char *binary = lecture(argv[1]);

     // // matrices(binary);

     // // free(binary);
     
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


     free(str);
     free_matrix(plaintext, 4);
     free_matrix(nonce_matrix, 4);
     free_matrix(extended_key, 44);
     free_matrix(master_key, 4);

     return 0;
}
