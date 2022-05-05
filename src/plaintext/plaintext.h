#ifndef PLAINTEXT_H
#define PLAINTEXT_H

#include "../tools/tools.h"
#include <sys/stat.h>

struct init_matrix *init_plaintext(char *is_file);
int write_to_file(struct init_matrix *init);

#endif