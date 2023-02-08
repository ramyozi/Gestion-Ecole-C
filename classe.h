#include "eleve.h"

#ifndef CLASSE_H
#define CLASSE_H

#define MAXELEVE 30

typedef struct
{
    char nom_classe[256];
    char nom_prof[256];
    int nb_eleve;
    Eleve_t TAB_eleve[MAXELEVE];
}Classe_t;

void AfficherClasse(const Classe_t *Classe); // Affiche le nom de la classe, le nom du professeur et un tableau d'eleves avec la fonction AfficherEleve
void SaisirClasse(Classe_t *Classe); // Permet de saisir le nom de la classe et du professeur et un tableau d'élève avec la fonction SaisirEleve

#endif // classe.h
