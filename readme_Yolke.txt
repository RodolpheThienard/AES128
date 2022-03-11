(1) : l_mat_etat[i/16].matrice[i%4][(i/4)%4]=(int)str[i];

-[i/16] -> pour le nombre de block 
(on passe au 2ième block au 17ieme caractère)
-[i%4] axe 'X' -> va suivre 0 1 2 3,à la chaine pour remplir ligne par ligne
-[(i/4)%4] axe 'Y' -> va suivre 0 0 0 0, 1 1 1 1, 2 2 2 2, pour remplir colonne par colonne

on ce retrouve avec XY qui augmente de la façon suivante :
     [0][0], [1][0], .. [3][0] puis -> [0][1]

-(int)str[i];
On caste la valeur char en int 
-> ici atoi ne fonctionne pas car il attend un char*
int atoi(const char *nptr);

->(int)'A' devient -> 65 valeur ascii en decimale

(2)
explication première valeur (41)
L -(ascii)-> 76(10) -> 0x4C --(AES_table)--> 0x29 -> 41(10)
o -(ascii)-> 111(10)-> 0x6F --(AES_table)--> OxA8 -> 168(10)

