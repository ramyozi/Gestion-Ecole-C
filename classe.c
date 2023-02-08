#include "classe.h"

void AfficherClasse(const Classe_t *Classe) // Erwan
{
int i;//boucle d'eleve pour remplir le tableau d'eleve de la classe
printf("Le/la professeur %s de la classe de %s : \n liste des eleves : \n",Classe->nom_prof, Classe->nom_classe);
for (i=0;i<Classe->nb_eleve;i++)
    {
    printf("Eleve %d",i);
    AfficherEleve(Classe->TAB_eleve);
    }
}
void SaisirClasse(Classe_t *Classe) // Erwan
{
printf("Saisir le nom du professeur : \n");
scanf("%s", Classe->nom_prof);
}//Pas de boucle de classes car les classes sont creee grace aux affectations des eleves selon leur date de naissance
