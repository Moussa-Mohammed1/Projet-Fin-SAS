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

typedef struct Player{
    int ID;
    char nom[20];
    char prenom[20];
    int numeroMaillot;
    char poste[20];
    int age;
    int buts;
    date dateInscription;
    char status[20];
}Player;
Player Equipe[MaxJoueur];
char rechercheJ[20];
int CntJoueur = 0; // le nombre des joueurs enregistre dans l'equipe

    // fonction qui resoudre les problems d'espaces avant nom. et mettre le premier caractere en majuscule
void Majuscule(char str[]) {
    int i = 0, j = 0;
    while (str[i] == ' ') i++;
    while (str[i]) {
        str[j++] = str[i++];
    }
    str[j] = '\0';
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] = str[0] - ('a' - 'A');
    }
}
// fonction qui genere un id pour chaque player(pas des doublons)
int GenerateurID() {
    IDvalidate:
    int idplayer;
    srand(time(NULL));
    int min=1001;
    int max=1200;
    idplayer = rand() % (max - min + 1) + max;
    for (int i = 0; i < CntJoueur; i++){
        if(Equipe[CntJoueur].ID == idplayer){
            goto IDvalidate;
        }
    }
    return idplayer;
}
void AjouterJoueur(){
ValidateAj:
    int choix;
    printf("\n--------------------------------------------------\n");
    printf("\n1.Ajoute simple. \t2.Ajoute multiple.\n");
    printf("Votre choix : ");
    scanf("%d",&choix);
    getchar();
    switch (choix)
    {
    case 1:
        int choix1;
        printf("Entrer le nom du joueur: ");
        fgets(Equipe[CntJoueur].nom, sizeof(Equipe[CntJoueur].nom), stdin);
        Equipe[CntJoueur].nom[strcspn(Equipe[CntJoueur].nom, "\n")]= '\0';
        Majuscule(Equipe[CntJoueur].nom);
        printf("Entrer le prenom du joueur: ");
        fgets(Equipe[CntJoueur].prenom, sizeof(Equipe[CntJoueur].prenom), stdin);
        Equipe[CntJoueur].prenom[strcspn(Equipe[CntJoueur].prenom, "\n")]= '\0';
        Majuscule(Equipe[CntJoueur].prenom);
        printf("Entrer le numero de maillot du joueur: ");
        scanf("%d",&Equipe[CntJoueur].numeroMaillot);
        getchar();
    valide :
        printf("le poste du joueur : \t1- Gardien \t2- Defenseur \t3- Milieu \t4- Attaquant\n");
        printf("Entrer un choix valide : ");
        scanf("%d",&choix1);
        getchar();
        switch (choix1)
        {
        case 1:
            strcpy(Equipe[CntJoueur].poste, poste1);
            break;
        case 2:
            strcpy(Equipe[CntJoueur].poste, poste2);
            break;
        case 3:
            strcpy(Equipe[CntJoueur].poste, poste3);
            break;
        case 4:
            strcpy(Equipe[CntJoueur].poste, poste4);
            break;
        default:
            printf("\nChoix invalide !\n");
            goto valide;
            break;
        }
        do{
            printf("Entrer l'age du joueur :");
            scanf("%d",&Equipe[CntJoueur].age);
            getchar();
        } while(Equipe[CntJoueur].age < 20 || Equipe[CntJoueur].age > 40);
        printf("Entrer le nombre de buts marque par cette joueur :");
        scanf("%d",&Equipe[CntJoueur].buts);
        getchar();
        do{
            printf("Entrer la date d'inscription du joueur (JJ MM AAAA): ");
            scanf("%d %d %d",&Equipe[CntJoueur].dateInscription.day,&Equipe[CntJoueur].dateInscription.mounth,&Equipe[CntJoueur].dateInscription.year);
            getchar();
        }while( Equipe[CntJoueur].dateInscription.day < 0 || Equipe[CntJoueur].dateInscription.day > 31 ||
                Equipe[CntJoueur].dateInscription.mounth < 0 || Equipe[CntJoueur].dateInscription.mounth > 12 ||
                Equipe[CntJoueur].dateInscription.year < 1985 || Equipe[CntJoueur].dateInscription.year > 2005 );

        Equipe[CntJoueur].ID = GenerateurID();
    Vstatus:
        int choix4;
        printf("Entrer la status du joueur:\n");
        printf("1- Titulaire\t2- remplacant\n");
        printf("\nVotre choix:");
        scanf("%d",&choix4);
        getchar();
        switch (choix4)
        {
        case 1:
            strcpy(Equipe[CntJoueur].status,status1);
            break;
        case 2:
            strcpy(Equipe[CntJoueur].status,status2);
        default:
            printf("\nEntrer un choix valide !\n");
            goto Status;
        }
        printf("Joueur %s enregister avec success. Son ID = %d\n",Equipe[CntJoueur].nom, Equipe[CntJoueur].ID);
        CntJoueur ++;
        break;
    case 2:
        int Adds, Addscount = 0;
        printf("Entrer le nombre des joueurs que vous voulez :");
        scanf("%d",&Adds);
        getchar();
        do
        {
            int choix2;
            printf("Entrer le nom du joueur: ");
            fgets(Equipe[CntJoueur].nom, sizeof(Equipe[CntJoueur].nom), stdin);
            Equipe[CntJoueur].nom[strcspn(Equipe[CntJoueur].nom, "\n")]= '\0';
            Majuscule(Equipe[CntJoueur].nom);
            printf("\nEntrer le prenom du joueur: ");
            fgets(Equipe[CntJoueur].prenom, sizeof(Equipe[CntJoueur].prenom), stdin);
            Equipe[CntJoueur].prenom[strcspn(Equipe[CntJoueur].prenom, "\n")]= '\0';
            Majuscule(Equipe[CntJoueur].prenom);
            printf("\nEntrer le numero de maillot du joueur: ");
            scanf("%d",&Equipe[CntJoueur].numeroMaillot);
            getchar();
        valide2 :
            printf("\nle poste du joueur : \t1- Gardien \t2- Defenseur \t3- Milieu \t4- Attaquant\n");
            printf("Entrer un choix valide : ");
            scanf("%d",&choix2);
            getchar();
            switch (choix2)
            {
            case 1:
                strcpy(Equipe[CntJoueur].poste, poste1);
                break;
            case 2:
                strcpy(Equipe[CntJoueur].poste, poste2);
                break;
            case 3:
                strcpy(Equipe[CntJoueur].poste, poste3);
                break;
            case 4:
                strcpy(Equipe[CntJoueur].poste, poste4);
                break;
            default:
                printf("\nChoix invalide !\n");
                goto valide2;
                break;
            }
            do{
                printf("\nEntrer l'age du joueur :");
                scanf("%d",&Equipe[CntJoueur].age);
                getchar();
            } while(Equipe[CntJoueur].age < 20 || Equipe[CntJoueur].age > 40);
            printf("Entrer le nombre de buts marque par cette joueur :");
            scanf("%d",&Equipe[CntJoueur].buts);
            getchar();
            do{
                printf("Entrer la date d'inscription du joueur (JJ MM AAAA): ");
                scanf("%d %d %d",&Equipe[CntJoueur].dateInscription.day,&Equipe[CntJoueur].dateInscription.mounth,&Equipe[CntJoueur].dateInscription.year);
                getchar();
            }while( Equipe[CntJoueur].dateInscription.day < 0 || Equipe[CntJoueur].dateInscription.day > 31 ||
                    Equipe[CntJoueur].dateInscription.mounth < 0 || Equipe[CntJoueur].dateInscription.mounth > 12 ||
                    Equipe[CntJoueur].dateInscription.year < 1985 || Equipe[CntJoueur].dateInscription.year > 2005 );
            
            Equipe[CntJoueur].ID = GenerateurID();
        Status:
            int choix4;
            printf("Entrer la status du joueur:\n");
            printf("1- Titulaire\t2- remplacant\n");
            printf("\nVotre choix:");
            scanf("%d",&choix4);
            getchar();
            switch (choix4)
            {
            case 1:
                strcpy(Equipe[CntJoueur].status,status1);
                break;
            case 2:
                strcpy(Equipe[CntJoueur].status,status2);
            default:
                printf("\nEntrer un choix valide !\n");
                goto Status;
            }
            printf("Joueur %s enregister avec success. Son ID = %d\n",Equipe[CntJoueur].nom, Equipe[CntJoueur].ID);
            CntJoueur ++;
            break;
        } while (Addscount < Adds);
    default:
        printf("\nEntrer un choix valide !\n");
        goto ValidateAj;
    }
}
void AfficherListe(){
validTRI:
    int choix3;
    printf("\n--------------------------------------------------\n");
    printf("\n1- Trier les joueurs par ordre alphabetique (Nom).\n");
    printf("2- Trier les joueurs par age.\n");
    printf("3- Afficher les joueurs par poste.\n");
    printf("Entrer un choix valide :");
    scanf("%d",&choix3);
    getchar();
    switch (choix3)
    {
    case 1: //Trier les joueurs par ordre alphabetique (Nom).
        for (int i= 0; i < CntJoueur - 1; i++) {
            for (int j = 0; j < CntJoueur - i - 1; j++) {
                if (strcmp(Equipe[j].nom, Equipe[j + 1].nom) > 0) {
                    Player temp = Equipe[j];
                    Equipe[j] = Equipe[j + 1];
                    Equipe[j + 1] = temp;
                }
            }
        }
        break;
    case 2://Trier les joueurs par age.
        for (int i= 0; i < CntJoueur - 1; i++) {
            for (int j = 0; j < CntJoueur - i - 1; j++) {
                if (strcmp(Equipe[j].age, Equipe[j + 1].age) > 0) {
                    Player temp = Equipe[j];
                    Equipe[j] = Equipe[j + 1];
                    Equipe[j + 1] = temp;
                }
            }
        }
        break;
    case 3://Afficher les joueurs par poste
        printf("Afficher par poste : \n");
        printf(" Poste Gardien :\n");
        for (int  i = 0; i < CntJoueur; i++)
        {
            if (strcmp(Equipe[i].poste, poste1)==0)
            {
                printf("\n--------------------------------------------------\n");
                printf("ID : %d\nNom et prenom : %s %s\nNumero Maillot : %d\nPoste : %s\nAge : %d\nButs Marque: %d\nDate d'inscription: %d %d %d\nStatus : %s", Equipe[i].ID,Equipe[i].nom,
                Equipe[i].prenom, Equipe[i].numeroMaillot,Equipe[i].poste, Equipe[i].age,Equipe[i].buts, Equipe[i].dateInscription.day, Equipe[i].dateInscription.mounth, Equipe[i].dateInscription.year, Equipe[i].status);
            }
        }
        printf("Afficher par poste : \n");
        printf(" Poste Defenseur :\n");
        for (int  i = 0; i < CntJoueur; i++)
        {
            if (strcmp(Equipe[i].poste, poste2)==0)
            {
                printf("\n--------------------------------------------------\n");
                printf("ID : %d\nNom et prenom : %s %s\nNumero Maillot : %d\nPoste : %s\nAge : %d\nButs Marque: %d\nDate d'inscription: %d %d %d\nStatus : %s", Equipe[i].ID,Equipe[i].nom,
                Equipe[i].prenom, Equipe[i].numeroMaillot,Equipe[i].poste, Equipe[i].age,Equipe[i].buts, Equipe[i].dateInscription.day, Equipe[i].dateInscription.mounth, Equipe[i].dateInscription.year, Equipe[i].status);
            }
        }
        printf("Afficher par poste : \n");
        printf(" Poste Attaquant :\n");
        for (int  i = 0; i < CntJoueur; i++)
        {
            if (strcmp(Equipe[i].poste, poste3)==0)
            {
                printf("\n--------------------------------------------------\n");
                printf("ID : %d\nNom et prenom : %s %s\nNumero Maillot : %d\nPoste : %s\nAge : %d\nButs Marque: %d\nDate d'inscription: %d %d %d\nStatus : %s", Equipe[i].ID,Equipe[i].nom,
                Equipe[i].prenom, Equipe[i].numeroMaillot,Equipe[i].poste, Equipe[i].age,Equipe[i].buts, Equipe[i].dateInscription.day, Equipe[i].dateInscription.mounth, Equipe[i].dateInscription.year, Equipe[i].status);
            }
        }
        break;
    default:
        printf("\nEntrer un choix valide !\n");
        goto validTRI;
    }
}

void supprimerJoueur(){
    
}
int main(){
// fake data dor testing
Equipe[CntJoueur++] = (Player){1, "Benali", "Amine", 1, poste1, 30, 0, {12, 6, 2020}, status1};
Equipe[CntJoueur++] = (Player){2, "El Idrissi", "Youssef", 2, poste2, 28, 1, {5, 2, 2019}, status1};
Equipe[CntJoueur++] = (Player){3, "Zouhair", "Sami", 3, poste2, 25, 2, {20, 7, 2021}, status2};
Equipe[CntJoueur++] = (Player){8, "Karim", "Taha", 8, poste2, 29, 1, {18, 11, 2019}, status1};
Equipe[CntJoueur++] = (Player){4, "Hassan", "Rachid", 4, poste3, 27, 5, {1, 1, 2018}, status1};
Equipe[CntJoueur++] = (Player){5, "Omar", "Karim", 5, poste3, 24, 3, {15, 3, 2022}, status2};
Equipe[CntJoueur++] = (Player){9, "Yassir", "Amar", 9, poste3, 22, 4, {30, 6, 2022}, status2};
Equipe[CntJoueur++] = (Player){6, "Nabil", "Ayoub", 6, poste4, 26, 10, {10, 5, 2020}, status1};
Equipe[CntJoueur++] = (Player){7, "Rania", "Salma", 7, poste4, 23, 7, {2, 9, 2021}, status2};
Equipe[CntJoueur++] = (Player){10, "Leila", "Meriem", 10, poste4, 21, 6, {12, 12, 2021}, status1};

    AjouterJoueur();
    AfficherListe();
    return 0;
}



