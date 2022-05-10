#include "attack.h"

/* 
    return struct init_matrix (containing all matrix)
    Each matrix :
    i   0   0   0
    0   0   0   0
    0   0   0   0
    0   0   0   0
*/
struct init_matrix* define_attack_matrix()
{
    struct chained_matrix *init = calloc(1, sizeof(struct chained_matrix));
    struct init_matrix *init_matrix = calloc(1, sizeof(struct init_matrix));
    init_matrix->init = init;

    for(int i = 0; i < 256; i++)
    {
        int **new_matrix = create_matrix(4, 4); 
        new_matrix[0][0] = i;
        init->matrix = new_matrix;
        if(i == 255)
        {
            init->next = NULL;
            return init_matrix;
        }
        struct chained_matrix *next_matrix = calloc(1, sizeof(struct chained_matrix));
        init->next = next_matrix;
        init = next_matrix;
    }
    free_attack_matrix(init_matrix);
    return define_attack_matrix(); // gestion erreur de génération.
}


void free_attack_matrix(struct init_matrix *init)
{
    free_chained_matrix(init->init);
    free(init);
}

void free_chained_matrix(struct chained_matrix *matrix)
{
    if(matrix->next)
    {
        free_chained_matrix(matrix->next);
    }
    free_matrix(matrix->matrix, 4);
    free(matrix);
}


struct chained_matrix* copy_chained_matrix(struct chained_matrix *matrix)
{
    struct chained_matrix *new_matrix = calloc(1, sizeof(struct chained_matrix));
    new_matrix->matrix = create_matrix(4, 4);
    copy_matrix(new_matrix->matrix, matrix->matrix);
    if(matrix->next)
    {
        new_matrix->next = copy_chained_matrix(matrix->next);
    }
    return new_matrix;
}

int** attack_4turns(struct init_matrix *init)
{
    int k = 0;

    int** result = create_matrix(16, 256);
    int* indices = calloc(16, sizeof(int));

    for (int l = 0; l < 16; l++) // case par case [k][l], k = l/4 et l = l%4
    {
       for(int a = 0; a < 256; a++)
        {
            struct chained_matrix* matrix = copy_chained_matrix(init->init);
            struct chained_matrix* head = matrix;
            for(int j = 0; j < 256; j++)
            {
                suboctet_inverse(&matrix->matrix[l/4][l%4], a); // on calcule les 256 suboctets inverses
                matrix = matrix->next;
            }
            if(xor(head,l/4,l%4)) // on xor tout les suboctets inverses
            {
                result[l][indices[l]] = a;
                if(indices[l] < 255) result[l][indices[l] + 1] = -1;
                indices[l]++;
                // if(l==0) printf("a: %2x\n", a);
                printf("[%d][%d] = %2x\n", l/4, l%4, a);
                k++;
            }
            free_chained_matrix(head);
        }
    }
    printf("k: %d\n",k) ;
    if (k == 0) printf("No solution found\n");
    return result;
}

int xor(struct chained_matrix *init, int k, int l)
{
    struct chained_matrix *matrix = init;
    int output = matrix->matrix[k][l];
    for(int j = 1; j < 256; j++)
    {
        matrix = matrix->next;
        output ^= matrix->matrix[k][l]; 
    }
    return output?0:1;
}


void suboctet_inverse(int* matrix, int a)
{
     int aes_table_inv[16][16] = {
          {0x52,0x09,0x6A,0xD5,0x30,0x36,0xA5,0x38,0xBF,0x40,0xA3,0x9E,0x81,0xF3,0xD7,0xFB},
          {0x7C,0xE3,0x39,0x82,0x9B,0x2F,0xFF,0x87,0x34,0x8E,0x43,0x44,0xC4,0xDE,0xE9,0xCB},
          {0x54,0x7B,0x94,0x32,0xA6,0xC2,0x23,0x3D,0xEE,0x4C,0x95,0x0B,0x42,0xFA,0xC3,0x4E},
          {0x08,0x2E,0xA1,0x66,0x28,0xD9,0x24,0xB2,0x76,0x5B,0xA2,0x49,0x6D,0x8B,0xD1,0x25},
          {0x72,0xF8,0xF6,0x64,0x86,0x68,0x98,0x16,0xD4,0xA4,0x5C,0xCC,0x5D,0x65,0xB6,0x92},
          {0x6C,0x70,0x48,0x50,0xFD,0xED,0xB9,0xDA,0x5E,0x15,0x46,0x57,0xA7,0x8D,0x9D,0x84},
          {0x90,0xD8,0xAB,0x00,0x8C,0xBC,0xD3,0x0A,0xF7,0xE4,0x58,0x05,0xB8,0xB3,0x45,0x06},
          {0xD0,0x2C,0x1E,0x8F,0xCA,0x3F,0x0F,0x02,0xC1,0xAF,0xBD,0x03,0x01,0x13,0x8A,0x6B},
          {0x3A,0x91,0x11,0x41,0x4F,0x67,0xDC,0xEA,0x97,0xF2,0xCF,0xCE,0xF0,0xB4,0xE6,0x73},
          {0x96,0xAC,0x74,0x22,0xE7,0xAD,0x35,0x85,0xE2,0xF9,0x37,0xE8,0x1C,0x75,0xDF,0x6E},
          {0x47,0xF1,0x1A,0x71,0x1D,0x29,0xC5,0x89,0x6F,0xB7,0x62,0x0E,0xAA,0x18,0xBE,0x1B},
          {0xFC,0x56,0x3E,0x4B,0xC6,0xD2,0x79,0x20,0x9A,0xDB,0xC0,0xFE,0x78,0xCD,0x5A,0xF4},
          {0x1F,0xDD,0xA8,0x33,0x88,0x07,0xC7,0x31,0xB1,0x12,0x10,0x59,0x27,0x80,0xEC,0x5F},
          {0x60,0x51,0x7F,0xA9,0x19,0xB5,0x4A,0x0D,0x2D,0xE5,0x7A,0x9F,0x93,0xC9,0x9C,0xEF},
          {0xA0,0xE0,0x3B,0x4D,0xAE,0x2A,0xF5,0xB0,0xC8,0xEB,0xBB,0x3C,0x83,0x53,0x99,0x61},
          {0x17,0x2B,0x04,0x7E,0xBA,0x77,0xD6,0x26,0xE1,0x69,0x14,0x63,0x55,0x21,0x0C,0x7D}
     };
    *matrix = *(*aes_table_inv + (*matrix ^ a));

}


int **find_k4(int **key, struct init_matrix *attacked_matrix)
{
    int **tmp_key = create_matrix(4, 4);
    int **master_key = create_matrix(4, 4);
    int **extended_key = create_matrix(44, 4);

    copy_matrix(tmp_key, key);
    
    for(int i = 0; i < 16; i++)
    {
        for(int j = 0; j < 256; j++)
        {
            if(key[i][j] == -1) 
            {
                i++;
                for(int k = 0; k < 256; k++) 
                {
                    if(key[i][k] == tmp_key[i/4][i%4])
                    {
                        if(key[i][k+1] == -1)
                        {
                            tmp_key[i/4][i%4] = key[i][0];
                            i++;
                            k = 0;
                            continue;
                        }
                        tmp_key[i/4][i%4] = key[i][k+1];

                    }
                }
                tmp_key[i/4][i%4] = key[i][j];
                i = 0;
            }
            tmp_key[i/4][i%4] = key[i][j];

            key_reduction(master_key, tmp_key, 4);
            key_extension(master_key, extended_key, 4);

            struct init_matrix *verif = define_attack_matrix(); 
            
            aes(verif->init->matrix, extended_key, 4);
            if(!cmp_matrix(verif->init->matrix, attacked_matrix->init->matrix, 4, 4)) return tmp_key;

        }
    }
}