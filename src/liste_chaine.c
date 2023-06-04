#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "liste_chaine.h"
#include "structure.h"


Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));
    arbre *noeud_init = malloc(sizeof(arbre));
    if (liste == NULL || element == NULL){ free(liste); free(element); exit(EXIT_FAILURE); }

    (*noeud_init).frequence = 0;
    
    element->noeud = noeud_init;
    element->suivant = NULL;
    element->precedent = NULL;
    liste->queue = element;
    liste->premier = element;
    return liste;

}

void ajouter(Liste *liste, void *n_noeud)
{
    Element *n_element = malloc(sizeof(*n_element));
    if (n_element == NULL) {
        exit(EXIT_FAILURE);
    }
    
    /*printf("%d->%d\n", (*n_noeud).symbole , (*n_noeud).frequence);*/
    n_element->noeud = n_noeud;
    n_element->suivant = (liste)->premier;
    n_element->precedent = NULL;
    
    if ((liste)->queue == NULL) {
        (liste)->queue = n_element;
    } else {
        (liste)->premier->precedent = n_element;
    }
    
    (liste)->premier = n_element;
}

void supprimer_pile(Liste* liste, void** noeud)
{
    if (liste == NULL || liste->premier == NULL) { exit(EXIT_FAILURE);}

    Element* supprime_p = liste->premier;
    *noeud = supprime_p->noeud;

    liste->premier = supprime_p->suivant;

    if (liste->premier != NULL) {
        liste->premier->precedent = NULL;
    } 
    else {
        liste->queue = NULL;
    }
    free(supprime_p);
}

void supprimer_file(Liste* liste, void** noeud)
{
    if (liste == NULL || liste->queue == NULL) {
        exit(EXIT_FAILURE);
    }

    Element* supprime_f = liste->queue;
    *noeud = supprime_f->noeud;

    liste->queue = supprime_f->precedent;

    if (liste->queue != NULL) {
        liste->queue->suivant = NULL;
    } else {
        liste->premier = NULL;
    }

    free(supprime_f);
}

void afficher(Liste *liste) {
    Element *actuel;
    if (liste == NULL) {
        exit(EXIT_FAILURE);
    }
    actuel = liste->premier;
    while (actuel != NULL) {
        arbre *noeud_afficher = actuel->noeud;
        printf("%d->", noeud_afficher->frequence);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}

int size_liste(Liste *liste){
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
    return i;
}

int get_freque(Liste *liste,int j){
    Element *actuel;
    int i;
    int frequence;
    if (liste == NULL) {
        exit(EXIT_FAILURE);
    }
    actuel = liste->premier;
    for(i=0;i<j;i++) {
        arbre *noeud_afficher = actuel->noeud;
        frequence = noeud_afficher->frequence;
        actuel = actuel->suivant;
    }
    return frequence;
}

