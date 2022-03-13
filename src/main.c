#include "matrices/matrices.h"
#include "suboctet/suboctet.h"
#include "decalelignes/decalelignes.h"
#include "melangecolonnes/melangecolonnes.h"
#include "addroundkey/addroundkey.h"

int main (int argc, char* argv[]){

     /*
     //Pour tester
     char *str = malloc(2048);
     strcpy(str,"Lorem ipsum dolor consectetur adipisicing elit. Vitae repellendus quod saepe eveniet asperiores nam et tenetur veniam delectus! Voluptas ");

     // Random key
     int **key = calloc(4,sizeof(int*));
     for (int i = 0; i < 4; i++)
     {
          key[i] = calloc(4,sizeof(int));
     };
     
     
     Block *l_mat_etat = create_list_block(str);
     int nb_block = strlen(str)/16 + 1;
     print_list_block(l_mat_etat,nb_block);
     */

     if(argc != 2){
          printf("Too many arguments or Too few arguments");
          return 1;
     }

     char *binary = lecture(argv[1]);

     matrices(binary);

     free(binary);
    
     /*
     SubOctet(l_mat_etat,nb_block);
     print_list_block(l_mat_etat,nb_block); //(2)

     DecaleLignes(l_mat_etat,nb_block);
     print_list_block(l_mat_etat,nb_block); //(3)

     addroundkey(l_mat_etat, key, nb_block);
     print_list_block(l_mat_etat,nb_block); //(4)

     MelangeColonnes(l_mat_etat,nb_block);
     print_list_block(l_mat_etat,nb_block);

     for (int i = 0; i < 4; i++)
     {
          free(key[i]);
     };
     free(key);
     free(str);
     free(l_mat_etat);
     */

     return 0;
}
