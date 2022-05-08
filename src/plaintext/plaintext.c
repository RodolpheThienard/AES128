#include "plaintext.h"

struct init_matrix *init_plaintext(FILE *file, char *filename)
{
     struct stat *file_stat = calloc(1, sizeof(struct stat));
     stat(filename, file_stat);
     int size = file_stat->st_size;
     int matrix_amount = size/16;
     if(size%16 != 0) matrix_amount++;

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
               free(file_stat);
               return init;
          }
          struct chained_matrix *next_chained= calloc(1, sizeof(struct chained_matrix));
          
          chained->next = next_chained;
          chained = next_chained;
     }
     free(file_stat);
     return init;
     
}

int **str_to_matrix(char *key)
{
     int **output = create_matrix(4, 4);
     for(int i = 0; i < 16; i++)
     {
          output[i/4][i%4] = key[i];
     }
     return output;
}

int write_to_file(struct init_matrix *init, char *outfile)
{
     FILE *output_file = fopen(outfile, "w");
     struct chained_matrix *matrix = init->init;
     char *output = calloc(16, sizeof(char));
     int j = 0;
     while(matrix)
     {
          j++;
          output = realloc(output, (j*16)+1);
          for(int i = 0; i < 16; i++)
          {
               // sprintf(output, "%s%c", output, matrix->matrix[i/4][i%4]);
               // printf("%d", matrix->matrix[i/4][i%4]);
               char tmp[1] = "";
               tmp[0] = matrix->matrix[i/4][i%4];
               strcat(output, tmp);
          }
          matrix = matrix->next;
          
     }
     fprintf(output_file, "%s", output);

     free(output);
     fclose(output_file);
     return 0;
}