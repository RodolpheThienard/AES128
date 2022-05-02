#ifndef AES_H
#define AES_H

void aes(int **matrix, int **extended_key, int turns);
void turn(int **matrix, int **key);
void last_turn(int **matrix, int **key);

#endif