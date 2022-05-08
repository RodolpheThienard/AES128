# AES-128

## Sommaire :


### Calcul Matrice inverse : 
```c
int *foo = calloc(256, 4);
int *tmp = aes_table;
for(int i = 0; i < 256; i++)
{
    *(foo + tmp[i]) = i;
}

for(int j = 0; j < 16; j++)
{
    for(int i = 0; i< 16; i++)
    {
        printf("0x%02X,", foo[j*16 + i]);
    }
    printf("\n");
}
```