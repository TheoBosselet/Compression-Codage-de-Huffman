#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "structure.h"
#include "tri.h"
#include "liste_chaine.h"
#include "fonction_arbre.h"

/* Ouvrir un fichier */
int main(int argc, char *argv[]){
    FILE* fichier = NULL;
    int tab_frequence[ALPHABET_SIZE] ={0};
    printf("coucou\n");
    Liste *tab = initialisation();
    Liste *arbre = initialisation();

    fichier = fopen("test.txt", "r+");
    if (fichier != NULL){
        frequences(fichier,tab_frequence);
        creation_foret(tab_frequence,tab);
        tri_a_bulle(tab);

        creation_arbre_huff(tab,arbre);
        
        

        fclose(fichier);
    }
    else{
        printf("Impossible d'ouvrir le fichier test.txt");
    }
    return 0;
}

/* dire que le tab[ALPHABET_SIZE] */
/* calculer les frequences*/
/* Creation de l'arbre */




