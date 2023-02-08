#include "ecole.h"

void AfficherEcole(const Ecole_t *Ecole) // Leandre
{
printf("Le nom de l'école est : %s\n", Ecole->nom_ecole);
printf("Le nom du directeur est : %s\n", Ecole->nom_directeur);

    int i;
    // int j;

    for (i=0; i<Ecole->nb_classe; i++)//boucle de classe
    {
        AfficherClasse(&Ecole->TAB_classe[i]);
    /*
        printf("Dans la classe %s, le professeur est %s", Ecole->TAB_classe[i].nom_classe, TAB_classe[i].nom_prof);

        for (j=0; i<nb_eleve; j++)
        {
            AfficherEleve(Ecole->TAB_classe[i].TAB_eleve[j].nom_eleve, Ecole->TAB_classe[i].TAB_eleve[j].prenom_eleve);

            printf("%s %s est présent(e)", Ecole->TAB_classe[i].TAB_eleve[j].nom_eleve, TAB_classe[i].TAB_eleve[j].prenom_eleve);

        }*/
    }
}
void SaisirEcole(Ecole_t *Ecole) // Leandre
{
printf("Saisir le nom de l'école : \n");
scanf("%s", Ecole->nom_ecole);
printf ("Saisir le nom du directeur : \n");
scanf("%s", Ecole->nom_directeur);
printf("Entrez le nombre d'eleve max par classe : \n");
scanf("%d",&Ecole->max_eleve);
printf("Entrez l'annee en cours : \n");
scanf("%d",&Ecole->anneescolaire);

    int i;
    //int j;

    for (i=0; i<Ecole->nb_classe; i++)//boucle de classe
    {
        printf("\n------Classe %s-------\n",Ecole->TAB_classe[i].nom_classe);
        SaisirClasse(&Ecole->TAB_classe[i]);
    /*
        printf("Saisissez une classe : ");
        scanf("%s", Ecole->TAB_classe[i].nom_classe);
        printf("Saisissez un professeur : ");
        scanf("%s", Ecole->TAB_classe[i].nom_prof);

        for (j=0; j<nb_eleve; j++)
        {
            SaisirEleve(Ecole->TAB_classe[i].TAB_eleve[j].nom_eleve, TAB_classe[i].TAB_eleve[j].prenom_eleve);

            printf("Saisissez un nom : ");
            scanf("%s", Ecole->TAB_classe[i].TAB_eleve[j].nom_eleve);
            printf("Saisissez un prénom : ");
            scanf("%s", Ecole->TAB_classe[i].TAB_eleve[j].prenom_eleve);

        }
         */
    }
}
int RechercherEleve(const Ecole_t *Ecole)// Bernard
{
int i;      //compteur pour les classes
int j;  // compteur pour les élèves
char nom_recherche[20]={0};
char prenom_recherche[20]={0};


    //printf("\n-------------------------------------------------------------------------------------\n");
   // printf("Quel élève souhaitez-vous rechercher? (format nom prénom)\n");
    scanf("%s %s",nom_recherche,prenom_recherche);      // valorisation de la recherche

    for(i=0;i<Ecole->nb_classe;i++)        // boucle des classes
    {
        for(j=0;j<Ecole->TAB_classe[i].nb_eleve;j++)  // boucle des élèves
        {
            if((strcmp(Ecole->TAB_classe[i].TAB_eleve[j].nom_eleve,nom_recherche)==0)&&(strcmp(Ecole->TAB_classe[i].TAB_eleve[j].prenom_eleve,prenom_recherche)==0))    // la recherche a trouvée
            {
                return i;       // i= quel classe occupe l'élève qui correspond à la recherche nom+prénom
            }
        }
    }
      return -1;     // si pas de match, résultat=-1 (aucun élève ne correspond à la recherche)
}

void Verification (Ecole_t *Ecole) // Angelique
{
int resultat;
char reponse[5]={0};

resultat=RechercherEleve(Ecole);

    if (resultat==-1) //recupere le resultat de la fonction RechercherEleve
        {
        printf("Cet eleve n'est pas inscrit\n");
        }
    else
        {
        printf("L'élève est déjà inscrit!\n");
        }

    do  // boucle do/while pour que au moins un oui ou non soit saisi
    {printf("Souhaitez vous l'inscrire oui ou non ? ");
     scanf("%s",reponse);

     if (strcmp(reponse,"oui")==0||strcmp(reponse,"OUI")==0)
        AffecterEleve(Ecole);
     else if (strcmp(reponse,"non")==0||strcmp(reponse,"NON")==0)
        printf("Réponce prise en compte!\nSortie de la fonction verification\n");
     else
        printf("Erreur de saisie\n");
    //printf("!!%c!!",reponse);
        /*switch(reponse)
        {
            case 'o':
            case 'O': AffecterEleve(Ecole);
                 break;
            case 'n':
            case 'N':printf("Réponce prise en compte!\nSortie de la fonction verification\n");
                    break;
            default:
                 printf("Erreur de saisie\n"); //Juste au cas où
        }*/
     }while(strcmp(reponse,"non")!=0&&strcmp(reponse,"NON")!=0&&strcmp(reponse,"oui")!=0&&strcmp(reponse,"OUI")!=0);
     //while((reponse!='o')&&(reponse!='n')&&(reponse!='O')&&(reponse!='N'));
}
void AffecterEleve(Ecole_t *Ecole)// Groupe
{
char nom[26];
char prenom[26];
int jour=0;
int mois=0;
int annee=0;
int resultat;
int nb=0;
char reponse[5]={0};
//Creation de variable temporaire pour pouvoir verifier la date de naissance de l'eleve avant de l'inscrire dans un tableau d'eleve
    do //boucle do/while pour pouvoir affecter un eleve tant que la reponse est oui. Non, sortie de boucle
    {

        printf("Saisissez le nom et prénom de l'élève\n");
        scanf("%s %s",nom,prenom);
        printf("Saisissez la date naissance de l'élève au format jj/mm/aaaa : \n");
        scanf("%d/%d/%d",&jour, &mois, &annee);

        resultat=(Ecole->anneescolaire)-annee; //Calcul l'age d'un eleve  pour pouvoir l'affecter dans une classe

            switch(resultat)
            {
                case 6 :nb=Ecole->TAB_classe[0].nb_eleve; //L'eleve a 6 ans il est affecte a la classe CP en position TAB[O]
                    strcpy(Ecole->TAB_classe[0].TAB_eleve[nb].nom_eleve,nom);
                    strcpy(Ecole->TAB_classe[0].TAB_eleve[nb].prenom_eleve,prenom);
                    Ecole->TAB_classe[0].TAB_eleve[nb].date_eleve.tm_mday=jour;
                    Ecole->TAB_classe[0].TAB_eleve[nb].date_eleve.tm_mon=mois;
                    Ecole->TAB_classe[0].TAB_eleve[nb].date_eleve.tm_year=annee;
                    Ecole->TAB_classe[0].nb_eleve=Ecole->TAB_classe[0].nb_eleve +1;
                    break;
                case 7 : nb=Ecole->TAB_classe[1].nb_eleve;//L'eleve a 7 ans il est affecte a la classe CE1 en position TAB[1]
                    strcpy(Ecole->TAB_classe[1].TAB_eleve[nb].nom_eleve,nom);
                    strcpy(Ecole->TAB_classe[1].TAB_eleve[nb].prenom_eleve,prenom);
                    Ecole->TAB_classe[1].TAB_eleve[nb].date_eleve.tm_mday=jour;
                    Ecole->TAB_classe[1].TAB_eleve[nb].date_eleve.tm_mon=mois;
                    Ecole->TAB_classe[1].TAB_eleve[nb].date_eleve.tm_year=annee;
                    Ecole->TAB_classe[1].nb_eleve= Ecole->TAB_classe[1].nb_eleve+1;
                    break;
                case 8 : nb=Ecole->TAB_classe[2].nb_eleve;//L'eleve a 8 ans il est affecte a la classe CE2 en position TAB[2]
                    strcpy(Ecole->TAB_classe[2].TAB_eleve[nb].nom_eleve,nom);
                    strcpy(Ecole->TAB_classe[2].TAB_eleve[nb].prenom_eleve,prenom);
                    Ecole->TAB_classe[2].TAB_eleve[nb].date_eleve.tm_mday=jour;
                    Ecole->TAB_classe[2].TAB_eleve[nb].date_eleve.tm_mon=mois;
                    Ecole->TAB_classe[2].TAB_eleve[nb].date_eleve.tm_year=annee;
                    Ecole->TAB_classe[2].nb_eleve=Ecole->TAB_classe[2].nb_eleve +1;
                    break;
                case 9 : nb=Ecole->TAB_classe[3].nb_eleve;//L'eleve a 9 ans il est affecte a la classe CM1 en position TAB[3]
                    strcpy(Ecole->TAB_classe[3].TAB_eleve[nb].nom_eleve,nom);
                    strcpy(Ecole->TAB_classe[3].TAB_eleve[nb].prenom_eleve,prenom);
                    Ecole->TAB_classe[3].TAB_eleve[nb].date_eleve.tm_mday=jour;
                    Ecole->TAB_classe[3].TAB_eleve[nb].date_eleve.tm_mon=mois;
                    Ecole->TAB_classe[3].TAB_eleve[nb].date_eleve.tm_year=annee;
                    Ecole->TAB_classe[3].nb_eleve =Ecole->TAB_classe[3].nb_eleve+1;
                    break;
                case 10 : nb=Ecole->TAB_classe[4].nb_eleve;//L'eleve a 10 ans il est affecte a la classe CM2 en position TAB[4]
                    strcpy(Ecole->TAB_classe[4].TAB_eleve[nb].nom_eleve,nom);
                    strcpy(Ecole->TAB_classe[4].TAB_eleve[nb].prenom_eleve,prenom);
                    Ecole->TAB_classe[4].TAB_eleve[nb].date_eleve.tm_mday=jour;
                    Ecole->TAB_classe[4].TAB_eleve[nb].date_eleve.tm_mon=mois;
                    Ecole->TAB_classe[4].TAB_eleve[nb].date_eleve.tm_year=annee;
                    Ecole->TAB_classe[4].nb_eleve=Ecole->TAB_classe[4].nb_eleve +1;
                    break;
                default :
                    printf("L'élève n'est pas dans la bonne tranche d'age.\nSaisie de l'élève annulée!\n");

            }
            do      //boucle do/while pour validé la saisie de l'utilisateur
            {
                printf("Souhaitez-vous saisir un autre élève ? \nsaisir oui ou non\n");
                scanf("%s",reponse);
                if((strcmp(reponse,"non")!=0&&strcmp(reponse,"NON")!=0)&&(strcmp(reponse,"oui")!=0&&strcmp(reponse,"OUI")!=0))
                {
                    printf("Saisie éronnée!\n");
                }

            }
                while((strcmp(reponse,"non")!=0&&strcmp(reponse,"NON")!=0)&&(strcmp(reponse,"oui")!=0&&strcmp(reponse,"OUI")!=0));
    }
    while(strcmp(reponse,"non")!=0&&strcmp(reponse,"NON")!=0);
}

void ModifierEleve(Ecole_t *Ecole) // Angelique - Bernard
{
int i;
int j;
int resultat;
int resultat2;
char reponse[5]={0};
char nom_modif[20];
char prenom_modif[20];


printf("Veuillez entrer le nom et prenom de l'eleve a modifier : \n");
scanf("%s %s",nom_modif,prenom_modif);
for(i=0;i<Ecole->nb_classe;i++)        // boucle des classes
    {
        for(j=0;j<Ecole->TAB_classe[i].nb_eleve;j++)  // boucle des élèves
        {
            if((strcmp(Ecole->TAB_classe[i].TAB_eleve[j].nom_eleve,nom_modif)==0)&&(strcmp(Ecole->TAB_classe[i].TAB_eleve[j].prenom_eleve,prenom_modif)==0))    // la recherche a trouvée
            {

                resultat2=j;
                resultat=i;
            }
            else
                resultat=-1;
        }

    }

    if (resultat==-1) //recupere le resultat de la fonction RechercherEleve
        {
        printf("Cet eleve n'est pas inscrit. Annulation de la modification.\n");
        return;
        }
    else
        {
        printf("L'eleve se trouve dans la classe %s\n",Ecole->TAB_classe[resultat].nom_classe);
        }

    do  // boucle do/while pour que au moins un oui ou non soit saisi
    {printf("Souhaitez vous modifier l'eleve oui ou non ? ");
     scanf("%s",reponse);

     if (strcmp(reponse,"oui")==0||strcmp(reponse,"OUI")==0)
        {
        printf("Entrez le nouveau nom et prenom : \n");
        scanf("%s %s",nom_modif,prenom_modif);
        strcpy(Ecole->TAB_classe[resultat].TAB_eleve[resultat2].nom_eleve,nom_modif);
        strcpy(Ecole->TAB_classe[resultat].TAB_eleve[resultat2].prenom_eleve,prenom_modif);
        printf("Saisir la nouvelle date de naissance de l'eleve au format jj/mm/aaaa : \n");
        scanf("%d/%d/%d",&Ecole->TAB_classe[resultat].TAB_eleve[resultat2].date_eleve.tm_mday,&Ecole->TAB_classe[resultat].TAB_eleve[resultat2].date_eleve.tm_mon-1,&Ecole->TAB_classe[resultat].TAB_eleve[resultat2].date_eleve.tm_year-1900);
        printf("Votre eleve a ete modifie\n");
        }
     else if (strcmp(reponse,"non")==0||strcmp(reponse,"NON")==0)
        printf("Réponce prise en compte!\nSortie de la fonction modification\n");
     else
        printf("Erreur de saisie\n");

     }while(strcmp(reponse,"non")!=0&&strcmp(reponse,"NON")!=0&&strcmp(reponse,"oui")!=0&&strcmp(reponse,"OUI")!=0);

}

void EnregistrerFwrite(const char *file_name, Ecole_t Ecole)    //Bernard
{
FILE *ptr_sauvegarde;   //pointeur sur le fichier
ptr_sauvegarde=fopen(file_name,"w");    //ouverture en mode écriture

    if (ptr_sauvegarde==NULL)      //vérification de l'ouverture du fichier
    {
        perror("impossible d'ouvrir le fichier");
        return ;
    }
    fwrite(&Ecole,sizeof(Ecole_t),1,ptr_sauvegarde);    //écriture sur le fichier
    printf("----Le fichier a bien été sauvegardé.----\n");
    fclose(ptr_sauvegarde); // fermeture du fichier
}
void LireEnregistrement(const char *file_name, Ecole_t Ecole)   //Bernard   //lecture de l'enregistrement binaire, dans un format Ecole/classe1/liste des élèves/classe2/liste des élèves
{
    int i;  //compteur classe
    int j;  //compteur élève
    FILE *ptr_sauvegarde;
    ptr_sauvegarde=fopen(file_name, "r");   // ouverture fichier.bin en mode lecture

    if (ptr_sauvegarde==NULL)   //vérif ouverture
        {
        perror("impossible d'ouvrir le fichier");
        return ;    //retour au menu si ouverture impossible
        }

    while(fread(&Ecole,sizeof(Ecole_t),1,ptr_sauvegarde))   //lecture du fichier .bin
    {
        printf("\n------------Nom école : %s-------------\n\nNom du directeur : %s\nAnnée scolaire en cours : %d\nNombre de classe(s) : %d\tElèves max par classe : %d\n",Ecole.nom_ecole,Ecole.nom_directeur,Ecole.anneescolaire,Ecole.nb_classe,Ecole.max_eleve); //affichage des données de la structure Ecole
        for(i=0;i<Ecole.nb_classe;i++)  //boucle des classes
            {
            printf("\n---------------Nom de la classe : %s-------------------\nNom professeur : %s\n",Ecole.TAB_classe[i].nom_classe,Ecole.TAB_classe[i].nom_prof); //affichage des données des structures Ecole.tabclasse
            for(j=0;j<Ecole.TAB_classe[i].nb_eleve;j++) //boucle des élèves
                {
                printf("%d\t\t%s\t%s\t%d-%d-%d\n",i,Ecole.TAB_classe[i].TAB_eleve[j].nom_eleve,Ecole.TAB_classe[i].TAB_eleve[j].prenom_eleve,Ecole.TAB_classe[i].TAB_eleve[j].date_eleve.tm_mday,Ecole.TAB_classe[i].TAB_eleve[j].date_eleve.tm_mon,Ecole.TAB_classe[i].TAB_eleve[j].date_eleve.tm_year);   //Affichage des données des structures Ecole.tabclasse.tabeleve
                }
            }

    }
fclose(ptr_sauvegarde); //fermeture du fichier
}
void Liresauvegarde(const char *file_name, Ecole_t Ecole)
{
FILE *ptr_sauvegarde;
    ptr_sauvegarde=fopen(file_name, "r");   // ouverture fichier.bin en mode lecture

    if (ptr_sauvegarde==NULL)   //vérif ouverture
        {
        perror("impossible d'ouvrir le fichier");
        return ;    //retour au menu si ouverture impossible
        }

    fread(&Ecole,sizeof(Ecole_t),1,ptr_sauvegarde);

fclose(ptr_sauvegarde);
}
