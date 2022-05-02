#ifndef ATTACK_H
#define ATTACK_H

struct chained_matrix
{
    int **matrix;
    struct chained_matrix *next;
};

struct init_matrix
{
    struct chained_matrix *init;   
};

struct init_matrix* define_attack_matrix();
void free_attack_matrix(struct init_matrix *init);
void free_chained_matrix(struct chained_matrix *matrix);


#endif