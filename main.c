#include "matrices.h"
#include "SubOctet.h"
#include "decalelignes.h"
int main (int argc, char* argv[]){

     //Pour tester
     char *str = malloc(2048);
     strcpy(str,"Lorem ipsum dolor consectetur adipisicing elit. Vitae repellendus quod saepe eveniet asperiores nam et tenetur veniam delectus! Voluptas ");
     
     Block *l_mat_etat = create_list_block(str);
     int nb_block = strlen(str)/16 + 1;
     //print_list_block(l_mat_etat,nb_block);

     lecture(argv[1]);
    
     SubOctet(l_mat_etat,nb_block);
     print_list_block(l_mat_etat,nb_block); //(2)

     DecaleLignes(l_mat_etat,nb_block);

     free(str);
     free(l_mat_etat);
     return 0;
}
