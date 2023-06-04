#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "structure.h"
#include "tri.h"
#include "liste_chaine.h"


void creation_arbre_huff(Liste *pile, Liste* Arbre){
    int i;
    arbre **noeudrecupe =malloc(sizeof(arbre));
    supprimer_file(Arbre,noeudrecupe);
    printf("------\n");
    while((size_liste(pile) != 0) || (size_liste(Arbre) !=1)){
        printf("------\n");
        int a=0,b =0;
        arbre *noeud_g = malloc(sizeof(arbre));
        arbre *noeud_d = malloc(sizeof(arbre));
        arbre *noeud   = malloc(sizeof(arbre));
        arbre *noeud1   = malloc(sizeof(arbre));
        arbre *noeud2  = malloc(sizeof(arbre));

        if (size_liste(Arbre) ==0){
    printf("test 1\n");
            supprimer_pile(pile,&noeud_g); 
            supprimer_pile(pile,&noeud_d);
            afficher(pile);
            (*noeud).gauche = noeud_g;  a = (*noeud_g).frequence;  
            (*noeud).droite = noeud_d;  b = (*noeud_d).frequence;
        }



        else if(size_liste(pile) > 1 && size_liste(Arbre) >0){
    printf("test 2\n");
            supprimer_pile(pile,&noeud_g); 
            supprimer_pile(pile,&noeud_d); 
            supprimer_file(Arbre,&noeud1);

            if((*noeud_d).frequence+(*noeud_g).frequence <= (*noeud1).frequence){
    printf("test 3\n");
                printf("%d\n",(*noeud_g).frequence);
                ajouter(Arbre,noeud1);

                    afficher(pile);
        afficher(Arbre);
                (*noeud).gauche = noeud_g; a = (*noeud_g).frequence;   
                (*noeud).droite = noeud_d; b = (*noeud_d).frequence;
            }
            else if((*noeud_d).frequence+(*noeud_g).frequence > (*noeud1).frequence){
    printf("test 4\n");
                if(size_liste(Arbre)>1){
    printf("test 4.1\n");
                    supprimer_file(Arbre,&noeud2);
                    if((*noeud2).frequence + (*noeud1).frequence <= (*noeud_g).frequence + (*noeud_d).frequence){
    printf("test 4.1.1\n");
                        ajouter(pile,noeud_d); 
                        ajouter(pile,noeud_g);

    
                        
                        (*noeud).gauche = &noeud1; a = (*noeud1).frequence;
                        (*noeud).droite = &noeud2; b = (*noeud2).frequence;
                    }
                }
                else{
    printf("test 4.2\n");
                    
                    ajouter(pile,noeud_d);

                    (*noeud).gauche = noeud_g; a = (*noeud_g).frequence;
                    (*noeud).droite = noeud1; b = (*noeud1).frequence;
                }
            }
        }




        else if(size_liste(pile) == 0){ 
    printf("test 5\n");
            if(size_liste(Arbre)>1){
    printf("test 5.1\n");
                supprimer_file(Arbre,&noeud_g);
                supprimer_file(Arbre,&noeud_d);
                (*noeud).gauche = noeud_g; a = (*noeud_g).frequence;
                (*noeud).droite  = noeud_d; b = (*noeud_d).frequence;
            }
        }




        else{
    printf("test 6\n");
            supprimer_pile(pile,&noeud_g);
            supprimer_file(Arbre,&noeud_d);
            (*noeud).gauche = noeud_g; a = (*noeud_g).frequence;
            (*noeud).droite  = noeud_d; b = (*noeud_d).frequence;

        }
        (*noeud).symbole = NULL; 
        (*noeud).frequence = a+b;
        ajouter(Arbre,noeud);
        afficher(pile);
        afficher(Arbre);
    }
    
}

void frequences(FILE *fichier, int tab[]){
    char r;
    while ( (r=fgetc(fichier)) != EOF){
        tab[r]++;
    }
}


void creation_foret(int *tab_frequence, Liste *tab){
    int i;
    arbre **noeudrecupe =malloc(sizeof(arbre));
    for( i=0 ; i<ALPHABET_SIZE ; i++){
        if(tab_frequence[i]!=0){
            arbre *noeud =malloc(sizeof(arbre));
            (*noeud).symbole = i;
            (*noeud).frequence = tab_frequence[i];
            printf("%c->%d\n", (*noeud).symbole , (*noeud).frequence);
            ajouter(tab,noeud);
        }
    }
    supprimer_file(tab,noeudrecupe);
}
