#ifndef PLAINTEXT_H
#define PLAINTEXT_H

#include "../tools/tools.h"
#include <sys/stat.h>
#include <string.h>

struct init_matrix *init_plaintext(FILE *file, char *filename);
int write_to_file(struct init_matrix *init, char *outfile);
int **str_to_matrix(char *key);


#endif
