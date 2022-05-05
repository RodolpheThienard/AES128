#include "plaintext.h"

struct init_matrix *init_plaintext(char *is_file)
{
     FILE *file = fopen(is_file, "r");
     struct stat *file_stat = calloc(1, sizeof(struct stat));
     stat(is_file, file_stat);
     int size = file_stat->st_size;
     int matrix_amount = size/16;
     if(size%16 != 0) matrix_amount++;
     printf("%d\t%d\n", size, matrix_amount);

     struct chained_matrix *chained= calloc(1, sizeof(struct chained_matrix));
     struct init_matrix *init = calloc(1, sizeof(struct init_matrix));
     init->init = chained;
     for(int i = 0; i < matrix_amount; i++)
     {
          int **current_matrix = create_matrix(4, 4);

          for(int j = 0; j < 16; j++)
          {
               int val = fgetc(file);
               printf("%2X\t%c\n", val, val);
               if (val == EOF) current_matrix[j/4][j%4] = 255;
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