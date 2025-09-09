#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define poste1 "Gardien"
#define poste2 "Defenseur"
#define poste3 "Milieu"
#define poste4 "Attaquant"

#define status1 "Titulaire"
#define status2 "Remplacent"

#define MaxJoueur 100

typedef struct date{
    int day;
    int mounth;
    int year;
}date;

typedef struct Joueur{
    char id[20];
    char nom[20];
    char prenom[20];
    char numeroMaillot[10];
    int poste;
    int age;
    int but;
    date dateInscription;
    int status;
}Joueur;
Joueur Equipe[MaxJoueur];
int CntJoueur = 0; // le nombre des joueurs enregistre dans l'equipe

void AjouterJoueur(){
    int choix;
    printf("\n1.Ajoute simple. \n2.Ajuote multiple.\n");
    printf("Votre choix : ");
    scanf("%d",&choix);
    
    
}



