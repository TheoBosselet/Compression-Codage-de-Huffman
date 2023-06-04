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
    while((size_liste(pile) != 0) || (size_liste(Arbre) !=1)){
        printf("------\n");
        int a=0,b =0;
        arbre *noeud_g = malloc(sizeof(arbre));
        arbre *noeud_d = malloc(sizeof(arbre));
        arbre *noeud   = malloc(sizeof(arbre));
        arbre *noeud1   = malloc(sizeof(arbre));
        arbre *noeud2  = malloc(sizeof(arbre));

        if (size_liste(Arbre) ==0){
            supprimer_pile(pile,&noeud_g); 
            supprimer_pile(pile,&noeud_d);
            (*noeud).gauche = noeud_g;  a = (*noeud_g).frequence;  
            (*noeud).droite = noeud_d;  b = (*noeud_d).frequence;
        }



        else if(size_liste(pile) > 1 && size_liste(Arbre) >0){
            if(size_liste(Arbre) ==1){
                if(get_freque(pile,2) < get_freque(Arbre,1)){
                    printf("1 b<c\n"); 
                    supprimer_pile(pile,&noeud_g);
                    supprimer_pile(pile,&noeud_d); 
                    (*noeud).gauche = noeud_g; a = (*noeud_g).frequence;   
                    (*noeud).droite = noeud_d; b = (*noeud_d).frequence;
                }
                else{
                    printf("1 b>=c\n"); 
                    supprimer_file(Arbre,&noeud1);
                    supprimer_pile(pile,&noeud_g);
                    (*noeud).gauche = noeud_g; a = (*noeud_g).frequence; /* surrement mettre un if apres*/  
                    (*noeud).droite = noeud1; b = (*noeud1).frequence;
                }
            }
            else{
                if(get_freque(Arbre,size_liste(Arbre)-1) <= get_freque(pile,1) ){
                    printf("blabla\n"); 
                        supprimer_file(Arbre,&noeud1); 
                        supprimer_file(Arbre,&noeud2);
                        (*noeud).gauche = &noeud1; a = (*noeud1).frequence;
                        (*noeud).droite = &noeud2; b = (*noeud2).frequence;
                }
                else{
                    if(get_freque(pile,2) < get_freque(Arbre,size_liste(Arbre))){
                        printf("2 b<c\n"); 
                        supprimer_pile(pile,&noeud_g);
                        supprimer_pile(pile,&noeud_d); 
                        (*noeud).gauche = noeud_g; a = (*noeud_g).frequence;   
                        (*noeud).droite = noeud_d; b = (*noeud_d).frequence;
                    }
                    else{
                        printf("2 b>=c\n"); 
                        supprimer_file(Arbre,&noeud1);
                        supprimer_pile(pile,&noeud_g);
                        (*noeud).gauche = noeud_g; a = (*noeud_g).frequence; /* surrement mettre un if apres*/  
                        (*noeud).droite = noeud1; b = (*noeud1).frequence;
                    }
                }
            }
        }

        else if(size_liste(pile) == 0){ 
            if(size_liste(Arbre)>1){
                supprimer_file(Arbre,&noeud_g);
                supprimer_file(Arbre,&noeud_d);
                (*noeud).gauche = noeud_g; a = (*noeud_g).frequence;
                (*noeud).droite  = noeud_d; b = (*noeud_d).frequence;
            }
        }

        else{
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

/*
void afficher_arbre(Liste *Arbre){
    Element *actuel;
    int i=0;
    if (liste == NULL) {
        exit(EXIT_FAILURE);
    }
    actuel = liste->premier;
    while (actuel != NULL) {
        arbre *noeud_afficher = actuel->noeud;
        actuel = actuel->suivant;
        i++;

    }
    

}*/