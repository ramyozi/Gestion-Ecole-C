#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

#ifndef ELEVE_H
#define ELEVE_H

typedef struct
{
    char nom_eleve[256];
    char prenom_eleve[256];
    struct tm date_eleve;
}Eleve_t;

void AfficherDate(struct tm date_eleve); //Traite uniquement la date de naissance de l'eleve
void SaisirDate(struct tm *date_eleve);
void AfficherEleve(const Eleve_t *Eleve); // Afficher le détail de l'élève
void SaisirEleve(Eleve_t *Eleve);//Permet de saisir le nom, prenom et date de naissance

#endif
