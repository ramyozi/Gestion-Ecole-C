# Projet de Gestion d'École Primaire

## Description
Ce projet est une application de gestion d'école primaire développée en langage C. L'application permet de gérer les informations liées aux élèves, aux classes et à l'école en général.

## Fonctionnalités Principales
- Saisir les informations de l'école :
  - Nom de l'école.
  - Nom du directeur.
  - Année scolaire en cours.
  - Nombre maximum d'élèves par classe.
- Gérer les classes :
  - Créer, modifier ou supprimer des classes.
  - Associer un professeur à chaque classe.
  - Afficher la liste des classes.
- Gérer les élèves :
  - Ajouter, modifier ou supprimer des élèves.
  - Associer chaque élève à une classe en fonction de sa date de naissance.
  - Rechercher des élèves par nom et prénom.
  - Vérifier si un élève est déjà inscrit.
- Sauvegarde et Lecture :
  - Sauvegarder les données de l'école dans un fichier.
  - Lire les données sauvegardées depuis un fichier.

## Interface Utilisateur (UI)
L'application dispose d'une interface utilisateur conviviale qui permet aux utilisateurs de saisir facilement les informations nécessaires et d'interagir avec les fonctionnalités du programme. Une interface en ligne de commande (CLI) simple est utilisée pour ce projet.

## Technologies Utilisées
- Langage de programmation C.
- Bibliothèques standard C (stdio.h, string.h, time.h, etc.).

## Contraintes Techniques
- Les données de l'école sont stockées en mémoire pendant l'exécution de l'application.
- Les données sont sauvegardées dans un fichier binaire pour permettre une lecture ultérieure.

## Livrables Attendus
- Le code source de l'application.
- Le fichier exécutable de l'application.
- La documentation utilisateur.
- Le rapport de projet décrivant les choix techniques, la conception de l'application et les étapes de développement.

## Compilation avec Makefile
Pour compiler le projet, utilisez le fichier `Makefile` fourni. Vous pouvez compiler le projet sur Windows avec cmd ou sur Linux. Voici comment :

### Sur Linux
1. Ouvrez un terminal dans le répertoire du projet.
2. Exécutez les commandes suivantes pour compiler le projet :
   `make`
  `./Ecole_groupe1.exe`
### Sur Windows
1. Ouvrez cmd dans le répertoire du projet.
2. Exécutez les commandes suivantes pour compiler le projet :
  `make`
  `Ecole_groupe1.exe`
