#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ecole.h"

int main()
{
Ecole_t monecole={};
strcpy(monecole.TAB_classe[0].nom_classe,"CP");
strcpy(monecole.TAB_classe[1].nom_classe,"CE1");
strcpy(monecole.TAB_classe[2].nom_classe,"CE2");
strcpy(monecole.TAB_classe[3].nom_classe,"CM1");
strcpy(monecole.TAB_classe[4].nom_classe,"CM2");
monecole.nb_classe=5;
int choix=0;
int resultat_recherche=0;
int resultat_char=0;

printf("Bienvenue sur votre application de gestion d'école primaire!\n");
if (monecole.nom_ecole==NULL) //Si les donnees de l'ecole n'ont jamais ete enregistrees, il y a une etape obligatoire d'enregistrement

    {
    printf("\n\t!!!étape obligatoire : renseigner les données de l'école!!!\n\n");
    SaisirEcole(&monecole);
    }

do
{//  Erwan  Menu de choix propose a l'utilisateur
    //do
    {
        printf("\n_________________________________________\n");
        printf("Saisir le numero associé a votre demande\n");
        printf("1 : Affecter Eleve\n");
        printf("2 : Rechercher eleve\n");
        printf("3 : Verifier eleve\n");
        printf("4 : Sauvegarder dans un fichier\n");
        printf("5 : Lire depuis la sauvegarde\n");
        printf("6 : Saisir ecole\n");
        printf("7 : Modifier eleve\n");
        printf("0 : Quitter\n");
        printf("\n_________________________________________\n");

        scanf("%d",&choix);
/*
getchar();
    resultat_char=(isdigit(choix));
    printf("\n!!!!!!%d!!!!!!!\n",resultat_char);

        if (resultat_char==0)
            {
            printf("!! Erreur de saisie\n");
            printf("Veuillez saisir un chiffre entre 0 et 7\n\n");
            }
*/
        if (choix!=0 && choix!=1 && choix!=2 && choix!=3 && choix!=4 && choix!=5 && choix!=6 && choix!=7)
        {
            printf("Erreur de saisie\n");
            printf("Veuillez saisir un chiffre entre 0 et 7\n\n");
        }

    }
    while((resultat_char==0) &&(choix!=0 && choix!=1 && choix!=2 && choix!=3 && choix!=4 && choix!=5 && choix!=6 && choix!=7));

    switch (choix)//Chaque choix renvoie a des fonctions
    {
        case 1 : AffecterEleve(&monecole);
            break;
        case 2 : printf("Veuillez saisir une recherche au format nom prenom :\n");
            resultat_recherche=RechercherEleve(&monecole);

            if(resultat_recherche<0)
            printf("Aucun eleve portant ce nom/prenom n'est inscrit.\n");
            else
            printf("L'eleve recherche se trouve dans la classe %s",monecole.TAB_classe[resultat_recherche].nom_classe);
            break;
        case 3 : printf("Avant l'enregistrement nous allons verifier que l'eleve n'est pas deja inscrit.\n");
            printf("Saisir le nom de l'eleve au format nom prenom : \n");
            Verification (&monecole);
            break;
        case 4 : EnregistrerFwrite("ficsaveecole.bin", monecole);
            break;
        case 5 : LireEnregistrement("ficsaveecole.bin", monecole);
            break;
        case 6 : SaisirEcole(&monecole);
            break;
        case 7 : ModifierEleve(&monecole);
            break;
        case 0 : printf("Aurevoir");
                break;
        default:
            printf("Saisie incorrect");
    }
}
while (choix!=0);
}
