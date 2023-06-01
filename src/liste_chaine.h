#ifndef LISTE_CHAINE_H
#define LISTE_CHAINE_H

#include "structure.h"
#include "structure.h"

typedef struct Element{
    void* noeud;
    struct Element *suivant;
    struct Element *precedent;
}Element;

typedef struct Liste{
    void* noeud;
    struct Element *premier;
    struct Element *queue;
}Liste;

struct Liste *initialisation();
void ajouter(struct Liste *liste, void *n_noeud);
void supprimer_pile(struct Liste *liste, void **);
void supprimer_file(struct Liste *liste, void **);
void afficher(struct Liste *liste);
int size_liste(Liste *liste);
#endif


