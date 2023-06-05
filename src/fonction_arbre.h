#ifndef FONCTION_ARBRE_H
#define FONCTION_ARBRE_H
#include "structure.h"
#include "structure.h"
#include <stdbool.h>
void creation_arbre_huff(Liste *pile,Liste* arbre);
void frequences(FILE *fichier, int tab[]);
void creation_foret(int *tab_frequence, Liste *tab);
bool est_feuille(void *noeud);
int afficher_arbre(arbre *noeud,int prof);
void afficher_Huffman(Liste *Arbre );
#endif