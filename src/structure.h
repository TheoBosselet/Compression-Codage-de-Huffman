#ifndef STRUCTURE_H
#define STRUCTURE_H

#define ALPHABET_SIZE 255

/* Definition de l'arbre */
typedef struct arbre{
 struct arbre* gauche;
 struct arbre* droite;
 unsigned int frequence;
 unsigned char symbole;
}arbre;

#endif