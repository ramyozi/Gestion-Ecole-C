#include "eleve.h"

void AfficherDate(struct tm date_eleve)//Angelique
{
printf("La date de naissance de l'eleve est : %d/%d/%d\n",date_eleve.tm_mday,date_eleve.tm_mon+1,date_eleve.tm_year+1900);
}//ajout +1 a mois et +1900 a annee car utilisation de la struct tm (annee basee a partir de 1900 / mois a partir de 0)

void SaisirDate(struct tm *date_eleve)//Angelique
{
//memset(&date_eleve,0,sizeof(date_eleve));//remise à 0 de toutes les données de la struct tm date eleve
printf("Saisir la date naissance de l'eleve au format jj/mm/aaaa : \n");
scanf("%d/%d/%d",&date_eleve->tm_mday,&date_eleve->tm_mon,&date_eleve->tm_year);
date_eleve->tm_mon=date_eleve->tm_mon-1;
date_eleve->tm_year=date_eleve->tm_year-1900;
}

void AfficherEleve(const Eleve_t *Eleve)//Angelique
{
printf("Le nom et prenom de l'eleve est %s %s\n",Eleve->nom_eleve,Eleve->prenom_eleve);
AfficherDate(Eleve->date_eleve);//Appel de la fonction date de naissance de l'eleve
}

void SaisirEleve(Eleve_t *Eleve)//Angelique
{
printf("Saisir le nom et prenom de l'eleve\n");
scanf("%s %s",Eleve->nom_eleve,Eleve->prenom_eleve);
SaisirDate(&Eleve->date_eleve);//Appel de la fonction de saisie de la date de naissance de l'eleve
}


