#ifndef KEY_EXTENSION_H
#define KEY_EXTENSION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void key_extension(int **master_key, int **extended_key);
int *rotation_left(int *tampon);
int *suboctect_tampon(int *tampon);

#endif