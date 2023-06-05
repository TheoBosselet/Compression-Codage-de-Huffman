#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "structure.h"
#include "tri.h"
#include "liste_chaine.h"


void creation_arbre_huff(Liste *pile, Liste* Arbre){/* Initialisation des données */
    arbre **noeudrecupe =malloc(sizeof(arbre));
    supprimer_file(Arbre,(void**) noeudrecupe);
    while((size_liste(pile) != 0) || (size_liste(Arbre) !=1)){ /* Tant que l'arbre n'est pas fait */
        int a=0,b =0;
        arbre *noeud_g = malloc(sizeof(arbre));
        arbre *noeud_d = malloc(sizeof(arbre));
        arbre *noeud   = malloc(sizeof(arbre));

        if (size_liste(Arbre) ==0){ /* Premier element de l'arbre */
            supprimer_pile(pile,(void**)&noeud_g); 
            supprimer_pile(pile,(void**)&noeud_d);
        }



        else if(size_liste(pile) > 1 && size_liste(Arbre) >0){
            if(size_liste(Arbre) ==1){
                if(get_freque(pile,2) < get_freque(Arbre,1)){ 
                    supprimer_pile(pile,(void**)&noeud_g);
                    supprimer_pile(pile,(void**)&noeud_d); 
                }
                else{
                    supprimer_file(Arbre,(void**)&noeud_g);
                    supprimer_pile(pile,(void**)&noeud_d);


                }
            }
            else{
                if(get_freque(Arbre,size_liste(Arbre)-1) <= get_freque(pile,1) ){
                        supprimer_file(Arbre,(void**)&noeud_g); 
                        supprimer_file(Arbre,(void**)&noeud_d);
                }
                else{
                    if(get_freque(pile,2) < get_freque(Arbre,size_liste(Arbre))){
                        supprimer_pile(pile,(void**)&noeud_g);
                        supprimer_pile(pile,(void**)&noeud_d); 
                    }
                    else{
                        supprimer_file(Arbre,(void**)&noeud_g);
                        supprimer_pile(pile,(void**)&noeud_d);
                    }
                }
            }
        }

        else if(size_liste(pile) == 0){ 
            if(size_liste(Arbre)>1){
                supprimer_file(Arbre,(void**)&noeud_g);
                supprimer_file(Arbre,(void**)&noeud_d);
            }
        }

        else{
            supprimer_pile(pile,(void**)&noeud_g);
            supprimer_file(Arbre,(void**)&noeud_d);
        }
        (*noeud).gauche = (((*noeud_g).frequence<=(*noeud_d).frequence)? noeud_g : noeud_d );
        (*noeud).droite = (((*noeud_g).frequence>(*noeud_d).frequence)? noeud_g : noeud_d );
        a = (*noeud_g).frequence; 
        b = (*noeud_d).frequence;
        (*noeud).symbole = NULL; 
        (*noeud).frequence = a+b;
        ajouter(Arbre,noeud);
        /* Pour debug 
        printf("------\n");
        afficher(pile);
        afficher(Arbre);
        */
    }
    
}

void frequences(FILE *fichier, int tab[]){
    unsigned int r;
    while ( (r=fgetc(fichier)) != EOF){ /* Tant que le fichier est pas fin */
        tab[r]++;
    }
}


void creation_foret(int *tab_frequence, Liste *tab){
    int i;
    arbre **noeudrecupe =malloc(sizeof(arbre));
    for( i=0 ; i<=ALPHABET_SIZE ; i++){
        if(tab_frequence[i]!=0){
            arbre *noeud =malloc(sizeof(arbre));
            (*noeud).symbole = i;
            (*noeud).frequence = tab_frequence[i];
            (*noeud).gauche = NULL;
            (*noeud).droite = NULL;
            printf("%d->%d\n", (*noeud).symbole , (*noeud).frequence);
            ajouter(tab,noeud);
        }
    }
    supprimer_file(tab,(void**)noeudrecupe);
}
bool est_feuille(arbre *noeud){
    return noeud->gauche == NULL;
}

int afficher_arbre(arbre *noeud,int prof){
    int i;
    if(noeud ==NULL ){return 0;}

    arbre *actuel_d = noeud->droite;
    afficher_arbre(actuel_d,prof+1);

    for(i=0;i<=prof;i++){printf("\t");}
    if(est_feuille(noeud)){
        printf("[%d , %d] \n",noeud->symbole,noeud->frequence);
        return 0;
    }
    else{
        printf("(%d) \n",noeud->frequence);
    }
    
    arbre *actuel_g = noeud->gauche;
    afficher_arbre(actuel_g,prof+1);    
    

}

void afficher_Huffman(Liste *Arbre ){
        Element *actuel= Arbre->premier;
        arbre *noeud_afficher = actuel->noeud;
        afficher_arbre(noeud_afficher,0);
}