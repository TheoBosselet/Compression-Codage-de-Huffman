#include <stdlib.h>
#include <stdio.h>
#include "tri.h"
#include "liste_chaine.h"
/*
void tri_fusion(int debut , int fin , int* tab){
    
    if(fin > debut){
    int moitie = (debut + fin )/2;
    tri_fusion(debut,moitie,tab);
    tri_fusion(moitie+1,fin,tab);
    fusion(debut,moitie,fin,tab);}
    
}

void fusion(int debut, int milieu, int fin , int* tab){
    int n1= 1+ milieu - debut,n2 = fin - milieu;
    int *tab_g, *tab_d;
    int i,j,k;
    tab_g = malloc(sizeof(int) * n1);
    tab_d = malloc(sizeof(int)*n2);
    for( i = 0; i<n1;i++){tab_g[i] = tab[debut + i];}
    for( j = 0; j<n2;j++){tab_d[j] = tab[milieu+ 1 + j];}

    i=0,j=0,k=debut;
    while(i <n1 && j <n2){
        if(tab_g[i]<= tab_d[j]){ tab[k] = tab_g[i]; i++; }
        else {tab[k]= tab_d[j]; j++;}
        k++;
    }
    while (i<n1){
        tab[k]=tab_g[i];
        i++;
        k++;
    }
    while (j<n2){
        tab[k]=tab_d[j];
        j++;
        k++;
    }
    free(tab_d);
    free(tab_g);

}

int compare(a,b){
    int res = 0;
    if(a.frequence > b.frequence){res = -1;}
    else if(a.frquence <= b.frequence){res = 1;}
    return res;
  }

def sort(forest[], compare):
  tri_fusion(forest[], compare)
*/
void tri_a_bulle(Liste* liste) {
    if (liste->premier == liste->queue) {
        return;
    }

    int estTriee = 0;
    while (!estTriee) {
        estTriee = 1;
        Element* actuel = liste->premier;
        while (actuel != NULL && actuel->suivant != NULL) {
            arbre* noeudCourant = actuel->noeud;
            arbre* noeudSuivant = actuel->suivant->noeud;

            if (noeudCourant->frequence > noeudSuivant->frequence) {
            
                void* temp = actuel->noeud;
                actuel->noeud = actuel->suivant->noeud;
                actuel->suivant->noeud = temp;
                estTriee = 0;
            }

            actuel = actuel->suivant;
        }
    }
}