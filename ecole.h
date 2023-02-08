#include <stdlib.h>
#include "classe.h"

#ifndef ECOLE_H
#define ECOLE_H

#define MAXCLASSE 10

typedef struct
{
    char nom_ecole[256];
    char nom_directeur[256];
    int nb_classe;
    int anneescolaire;
    int max_eleve;
    Classe_t TAB_classe[MAXCLASSE];
}Ecole_t;


void AfficherEcole(const Ecole_t *Ecole); // Affiche le nom de l'ecole et du directeur, le nb de classe de l'ecole, l'annee en cours, le nb d'eleve max par classe et un tableau de classe avec la fonction AfficherClasse
void SaisirEcole(Ecole_t *Ecole); // Permet de saisir le nom de l'ecole et du directeur, le nb de classe de l'ecole, l'annee en cours, le nb d'eleve max par classe et un tableau de classe avec la fonction SaisirClasse
int RechercherEleve(const Ecole_t *Ecole);// Recherche un eleve dans l'école en scannant chaque eleve d'une classe et ce pour chaque classe
void ModifierEleve(Ecole_t *Ecole); //Permet de modifier le nom, prenom et date de naissance d'un eleve deja inscrit
void Verification (Ecole_t *Ecole); // Permet d'inscrire un eleve avec la fonction AffecterEleve apres avoir verifier qu'il n'etait pas deja inscrit avec la fonction RechercherEleve
void AffecterEleve(Ecole_t *Ecole); // Permet de saisir le nom, prenom et date de naissance d'un eleve et de l'affecter dans un tableau d'eleve dans la classe a laquelle il est associe (en fonction de son age)

void EnregistrerFwrite(const char *file_name, Ecole_t Ecole);//Enregistrement dans un fichierves donnees en binaire
void LireEnregistrement(const char *file_name, Ecole_t Ecole);//Lecture de l'enregistrement binaire, dans un format Ecole/classe1/liste des élèves/classe2/liste des élèves

#endif // ecole.h
