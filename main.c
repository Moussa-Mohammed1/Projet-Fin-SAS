#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define poste1 "Gardien"
#define poste2 "Defenseur"
#define poste3 "Milieu"
#define poste4 "Attaquant"

#define status1 "Titulaire"
#define status2 "Remplacent"

#define MaxJoueur 100

typedef struct Player{
    int ID;
    char nom[20];
    char prenom[20];
    int numeroMaillot;
    char poste[20];
    int age;
    int buts;
    char status[20];
}Player;
// declaration d'un tableau des joueurs
Player Equipe[MaxJoueur];
int Cnttitulaire = 0;
char rechercheJ[20];
int CntJoueur = 0; // le nombre des joueurs enregistre dans l'equipe
int idplayer = 1000;
    // fonction qui resoudre les problems d'espaces avant nom. et mettre le premier caractere en majuscule
void Majuscule(char str[]) {
    int i = 0, j = 0,c = 0, lng = 0;
    while (str[i] == ' ') i++;
    while (str[i]) {
        str[j++] = str[i++];
    } 
    str[j] = '\0';
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] = str[0] - 32;
    }
}
// fonction qui genere un id pour chaque player(pas des doublons)
int GenerateurID() {
    return idplayer ++;
}
void AjouterJoueur(){
ValidateAj:
    int choix;
    printf("\n--------------------------------------------------\n");
    printf("1.Ajoute simple. \t2.Ajoute multiple.\n");
    printf("\nVotre choix : ");
    scanf("%d",&choix);
    getchar();
    printf("\n--------------------------------------------------\n");
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
        do{
            printf("Entrer le numero de maillot du joueur: ");
            scanf("%d",&Equipe[CntJoueur].numeroMaillot);
            getchar();
        }while(Equipe[CntJoueur].numeroMaillot < 1);
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
            printf("Entrer l'age du joueur (20 - 40) :");
            scanf("%d",&Equipe[CntJoueur].age);
            getchar();
        } while(Equipe[CntJoueur].age < 20 || Equipe[CntJoueur].age > 40);
        do{
        printf("Entrer le nombre de buts marque par cette joueur :");
        scanf("%d",&Equipe[CntJoueur].buts);
        getchar();
        }while(Equipe[CntJoueur].buts <=0);
    Vstatus:
        int choix4;
        printf("Entrer la status du joueur:\n");
        printf("1- Titulaire\t 2- remplacant\n");
        printf("\nVotre choix:");
        scanf("%d",&choix4);
        getchar();
        switch (choix4)
        {
        case 1:
            if(Cnttitulaire < 11){
                strcpy(Equipe[CntJoueur].status,status2);
            }
            else {
                printf("\nL'equipe a deja 11 joueurs titulaire !\n Joueur entrer en status : remplacant !\n");
                strcpy(Equipe[CntJoueur].status,status1);
            }
            Cnttitulaire ++;
            break;
        case 2:
            strcpy(Equipe[CntJoueur].status,status2);
            break;
        default:
            printf("\nEntrer un choix valide !\n");
            goto Vstatus;
        }
        Equipe[CntJoueur].ID = GenerateurID();
        printf("Joueur %s enregister avec success. Son ID = %d\n",Equipe[CntJoueur].nom, Equipe[CntJoueur].ID);
        CntJoueur ++;
        break;
    case 2:
        int Adds, Addscount = 0;
        printf("Entrer le nombre des joueurs que vous voulez ajouter:");
        scanf("%d",&Adds);
        getchar();
        do
        {
            int choix2;
            printf("\nEntrer le nom du joueur: ");
            fgets(Equipe[CntJoueur].nom, sizeof(Equipe[CntJoueur].nom), stdin);
            Equipe[CntJoueur].nom[strcspn(Equipe[CntJoueur].nom, "\n")]= '\0';
            Majuscule(Equipe[CntJoueur].nom);
            printf("Entrer le prenom du joueur: ");
            fgets(Equipe[CntJoueur].prenom, sizeof(Equipe[CntJoueur].prenom), stdin);
            Equipe[CntJoueur].prenom[strcspn(Equipe[CntJoueur].prenom, "\n")]= '\0';
            Majuscule(Equipe[CntJoueur].prenom);
            do{
            printf("Entrer le numero de maillot du joueur: ");
            scanf("%d",&Equipe[CntJoueur].numeroMaillot);
            getchar();
            }while(Equipe[CntJoueur].numeroMaillot < 1);
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
                printf("\nEntrer l'age du joueur (20 - 40):");
                scanf("%d",&Equipe[CntJoueur].age);
                getchar();
            } while(Equipe[CntJoueur].age < 20 || Equipe[CntJoueur].age > 40);
            do{
            printf("Entrer le nombre de buts marque par cette joueur :");
            scanf("%d",&Equipe[CntJoueur].buts);
            getchar();
            }while(Equipe[CntJoueur].buts <=0);
            Equipe[CntJoueur].ID = GenerateurID();
        Status:
            int choix4;
            printf("Entrer la status du joueur:\n");
            printf("1- Titulaire\t 2- remplacant\n");
            printf("\nVotre choix:");
            scanf("%d",&choix4);
            getchar();
            switch (choix4)
            {
            case 1:
                if(Cnttitulaire < 11){
                strcpy(Equipe[CntJoueur].status,status2);
                }
                else {
                    printf("\nL'equipe a deja 11 joueurs titulaire !\n Joueur entrer en status : remplacant !\n");
                    strcpy(Equipe[CntJoueur].status,status1);
                }
                Cnttitulaire ++;
                break;
            case 2:
                strcpy(Equipe[CntJoueur].status,status2);
                break;
            default:
                printf("\nEntrer un choix valide !\n");
                goto Status;
            }
            printf("Joueur %s enregister avec success. Son ID = %d\n",Equipe[CntJoueur].nom, Equipe[CntJoueur].ID);
            CntJoueur ++;
            Addscount ++;
            printf("\n--------------------------------------------------");
            printf("\n L'ajoute %d terminee avec success !\n",Addscount );
            printf("--------------------------------------------------\n");
        } while (Addscount < Adds);

        break;
    default:
        printf("\nEntrer un choix valide !\n");
        goto ValidateAj;
    }
}

void AfficherListe(){
validAffichage:
    if (CntJoueur == 0){printf("\nAucune joueur a afficher !\n");}
    else {
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
        TriType1:
            int choix01;
            printf("\n1- Trie Ascendent(A-Z)\t2-Trie Descendent(Z-A)\n");
            printf("Entrer un choix valide : ");
            scanf("%d",&choix01);
            getchar();
            switch (choix01)
            {
            case 1:
            // Ascendent
                for (int i= 0; i < CntJoueur - 1; i++) {
                    for (int j = 0; j < CntJoueur - i - 1; j++) {
                        if (strcmp(Equipe[j].nom, Equipe[j + 1].nom) > 0) {
                            Player temp = Equipe[j];
                            Equipe[j] = Equipe[j + 1];
                            Equipe[j + 1] = temp;
                        }
                    }
                }
                printf("\nLes joueurs tries en alphabetique (Ascendent):\n");
                for (int i = 0; i < CntJoueur; i++){
                     printf("\n--------------------------------------------------\n");
                    printf("ID : %d\nNom et prenom : %s %s\nNumero Maillot : %d\nPoste : %s\nAge : %d\nButs Marque: %d\nStatus : %s", Equipe[i].ID,Equipe[i].nom,
                            Equipe[i].prenom, Equipe[i].numeroMaillot,Equipe[i].poste, Equipe[i].age,Equipe[i].buts, Equipe[i].status);          
                }
                break;
            case 2:
            // Descendent
                for (int i= 0; i < CntJoueur - 1; i++) {
                    for (int j = 0; j < CntJoueur - i - 1; j++) {
                        if (strcmp(Equipe[j].nom, Equipe[j + 1].nom) < 0) {
                            Player temp = Equipe[j];
                            Equipe[j] = Equipe[j + 1];
                            Equipe[j + 1] = temp;
                        }
                    }
                }
                printf("\nLes joueurs tries en alphabetique (Descendent):\n");
                for (int i = 0; i < CntJoueur; i++){
                    printf("\n--------------------------------------------------\n");
                    printf("ID : %d\nNom et prenom : %s %s\nNumero Maillot : %d\nPoste : %s\nAge : %d\nButs Marque: %d\nStatus : %s", Equipe[i].ID,Equipe[i].nom,
                            Equipe[i].prenom, Equipe[i].numeroMaillot,Equipe[i].poste, Equipe[i].age,Equipe[i].buts,  Equipe[i].status);          
                }
                break;
            default:
                printf("\nEntrer un choix valide !\n");
                goto TriType1;
            }
            break;
        case 2:
            //Trier les joueurs par age.
        TriType2:
            int choix11;
            printf("\n1- Trie Croissant\t2-Trie Decroissant\n");
            printf("Entrer un choix valide : ");
            scanf("%d",&choix11);
            getchar();
            switch (choix11)
            {
            case 1:
                // Croissant
                for (int i= 0; i < CntJoueur - 1; i++) 
                {
                    for (int j = 0; j < CntJoueur - i - 1; j++) 
                    {
                        if (Equipe[j].age > Equipe[j + 1].age) {
                            Player temp = Equipe[j];
                            Equipe[j] = Equipe[j + 1];
                            Equipe[j + 1] = temp;
                        }
                    }
                }
                printf("\nLes joueurs tries par age (Croissant):\n");
                for (int i = 0; i < CntJoueur; i++){
                    printf("\n--------------------------------------------------\n");
                    printf("ID : %d\nNom et prenom : %s %s\nNumero Maillot : %d\nPoste : %s\nAge : %d\nButs Marque: %d\nStatus : %s", Equipe[i].ID,Equipe[i].nom,
                            Equipe[i].prenom, Equipe[i].numeroMaillot,Equipe[i].poste, Equipe[i].age,Equipe[i].buts,  Equipe[i].status);          
                    }
                break;
            case 2:
                // Decroissant
                for (int i= 0; i < CntJoueur - 1; i++) {
                    for (int j = 0; j < CntJoueur - i - 1; j++) {
                        if (Equipe[j].age < Equipe[j + 1].age) {
                            Player temp = Equipe[j];
                            Equipe[j] = Equipe[j + 1];
                            Equipe[j + 1] = temp;
                        }
                    }
                }
                printf("\nLes joueurs tries par age (Decroissant):\n");
                for (int i = 0; i < CntJoueur; i++){
                    printf("\n--------------------------------------------------\n");
                    printf("ID : %d\nNom et prenom : %s %s\nNumero Maillot : %d\nPoste : %s\nAge : %d\nButs Marque: %d\nStatus : %s", Equipe[i].ID,Equipe[i].nom,
                            Equipe[i].prenom, Equipe[i].numeroMaillot,Equipe[i].poste, Equipe[i].age,Equipe[i].buts,Equipe[i].status);          
                }
                break;
            default:
                printf("\nChoix invalide!\n");
                goto TriType2;
            }
            break;
        case 3:
            //Afficher les joueurs par poste
            printf("\n--------------------------------------------------\n");
            printf("Afficher par poste : \n");
            printf(" Poste Gardien :\n");
            for (int  i = 0; i < CntJoueur; i++)
            {
                if (strcmp(Equipe[i].poste, poste1)==0)
                {
                    printf("\n--------------------------------------------------\n");
                    printf("ID : %d\nNom et prenom : %s %s\nNumero Maillot : %d\nPoste : %s\nAge : %d\nButs Marque: %d\nStatus : %s", Equipe[i].ID,Equipe[i].nom,
                    Equipe[i].prenom, Equipe[i].numeroMaillot,Equipe[i].poste, Equipe[i].age,Equipe[i].buts, Equipe[i].status);
                }
            }
            printf("\n--------------------------------------------------\n");
            printf("Afficher par poste : \n");
            printf(" Poste Defenseur :\n");
            for (int  i = 0; i < CntJoueur; i++)
            {
                if (strcmp(Equipe[i].poste, poste2)==0)
                {
                    printf("\n--------------------------------------------------\n");
                    printf("ID : %d\nNom et prenom : %s %s\nNumero Maillot : %d\nPoste : %s\nAge : %d\nButs Marque: %d\nStatus : %s", Equipe[i].ID,Equipe[i].nom,
                    Equipe[i].prenom, Equipe[i].numeroMaillot,Equipe[i].poste, Equipe[i].age,Equipe[i].buts,Equipe[i].status);
                }
            }
            printf("\n--------------------------------------------------\n");
            printf("Afficher par poste : \n");
            printf(" Poste Milieu :\n");
            for (int  i = 0; i < CntJoueur; i++)
            {
                if (strcmp(Equipe[i].poste, poste3)==0)
                {
                    printf("\n--------------------------------------------------\n");
                    printf("ID : %d\nNom et prenom : %s %s\nNumero Maillot : %d\nPoste : %s\nAge : %d\nButs Marque: %d\nStatus : %s", Equipe[i].ID,Equipe[i].nom,
                    Equipe[i].prenom, Equipe[i].numeroMaillot,Equipe[i].poste, Equipe[i].age,Equipe[i].buts,  Equipe[i].status);
                }
            }
            printf("\n--------------------------------------------------\n");
            printf("Afficher par poste : \n");
            printf(" Poste Attaquant :\n");
            for (int  i = 0; i < CntJoueur; i++)
            {
                if (strcmp(Equipe[i].poste, poste4)==0)
                {
                    printf("\n--------------------------------------------------\n");
                    printf("ID : %d\nNom et prenom : %s %s\nNumero Maillot : %d\nPoste : %s\nAge : %d\nButs Marque: %d\nStatus : %s", Equipe[i].ID,Equipe[i].nom,
                    Equipe[i].prenom, Equipe[i].numeroMaillot,Equipe[i].poste, Equipe[i].age,Equipe[i].buts,  Equipe[i].status);
                }
            }
            break;
        default:
            printf("\nEntrer un choix valide !\n");
            goto validAffichage;
        }
    }
}
void ModifierJoueur(){
    repeat:
    if(CntJoueur == 0){printf("\nAucun joueur a modifier !\n");}
    else
    {   
        int choix02;
        do{
        printf("\n1- Modifier le poste d'un joueur.");
        printf("\n2- Modifier l'age d'un joueur.");
        printf("\n3- Modifier le nombre de buts marques par un joueur.\n");
        printf("Entrer votre choix:");
        scanf("%d",&choix02);       // choix de modification
        getchar();
        }while( choix02 < 1 || choix02 > 3 );
        int RechJ[100];
        int j = 0;
        printf("\nEntrer le nom du joueur que vous voulez modifier: ");
        fgets(rechercheJ, sizeof(rechercheJ), stdin);
        rechercheJ[strcspn(rechercheJ, "\n")]= '\0';
        Majuscule(rechercheJ);
        for (int i = 0; i < CntJoueur; i++)
        {
            if (strcmp(Equipe[i].nom, rechercheJ) == 0)
            {
                RechJ[j]=i;
                j++;
            }
        }
        if (j == 0) {printf("\nAucun joueur correspond au nom entrer !\n");}
        else
        {
            printf("\nLes Joueurs correspond au ce nom est : %d",j);
            for(int i = 0; i < j ; i++)
            {
                int index = RechJ[i];
                printf("\n--------------------------------------------------\n");
                printf("joueur Numero %d :\n ID : %d \nNom et prenom : %s %s\nNumero Maillot : %d\nPoste : %s\nAge : %d\nButs Marque: %d\nStatus : %s",i+1, Equipe[index].ID, Equipe[index].nom,
                        Equipe[index].prenom, Equipe[index].numeroMaillot,Equipe[index].poste, Equipe[index].age, Equipe[index].buts,  Equipe[index].status);
            }
            int choix03;
            do {
                printf("\nEntrer le numero du joueur (entre 1 et %d) :",j);
                scanf("%d",&choix03);
                getchar();
            }while(choix03 < 1 || choix03 > j);
            int indexJoueur = RechJ[choix03 - 1];
            printf("\nTu choisi le joueur %s  \t ID : %d\t status : %s \n",Equipe[indexJoueur].nom, Equipe[indexJoueur].ID, Equipe[indexJoueur].status);
            switch(choix02)
            {
                case 1:
                    printf("choisi son nouveau poste : \t1- Gardien \t2- Defenseur \t3- Milieu \t4- Attaquant\n");
                UpdateStatus:
                    int choix001;
                    printf("Entrer un choix valide : ");
                    scanf("%d",&choix001);
                    getchar();
                    switch (choix001)
                    {
                    case 1:
                        strcpy(Equipe[indexJoueur].poste, poste1);
                        break;
                    case 2:
                        strcpy(Equipe[indexJoueur].poste, poste2);
                        break;
                    case 3:
                        strcpy(Equipe[indexJoueur].poste, poste3);
                        break;
                    case 4:
                        strcpy(Equipe[indexJoueur].poste, poste4);
                        break;
                    default:
                        printf("\nChoix invalide !\n");
                        goto UpdateStatus;
                    }
                    printf("Poste modifie avec success !\n");
                    break;
                case 2:
                    do{
                        printf("\nEntrer le nouveau age :");
                        scanf("%d",&Equipe[choix03].age);
                        getchar();
                    }while(Equipe[choix03].age  < 20 || Equipe[choix03].age  > 40);
                    printf("Age modifie avec success !\n");
                break;
                case 3:
                    printf("\nEntrer le nouveau nombre des buts du joueurs :");
                    scanf("%d",&Equipe[choix03].buts);
                    getchar();
                    break;
            }
        }
    }
}
void supprimerJoueur(){
    if (CntJoueur == 0){printf("\nAucune joueur a supprimer !\n");}
    else{
        int targetID;
        int exist = -1;
        printf("Entrer l'identifient ID du joueur que vous voulez supprimer :");
        scanf("%d",&targetID);
        for (int i = 0; i < CntJoueur; i++)
        {
            if (Equipe[i].ID == targetID)
            {
                exist = i;
                break;
            }
        }
        if (exist == -1){
            printf("l'ID %d ne correspond au aucun joueur !",targetID);
        }
        else {
            printf("\nL'identifient %d correspond au joueur %s\n", Equipe[exist].ID, Equipe[exist].nom);
        confirmation:
            int choix002;
            printf("Voulez vous vraiment supprimer ce joueur?\n1- continue \t2- annuler ");
            printf("\nEntrer votre choix:");
            scanf("%d",&choix002);
            getchar();
            switch (choix002)
            {
            case 1:
                for (int i = exist; i < CntJoueur - 1; i++)
                {
                    Equipe[i]=Equipe[i + 1];
                }
                CntJoueur --;
                printf("\n--------------------------------------------------\n");
                printf("l'identifient %d est supprime avec success !\n",targetID);
                break;
            case 2:
                break;
            default:
                printf("\nChoix invalide !\n");
                goto confirmation;
            }
        }
    }
}

void rechercheJoueur(){
    if (CntJoueur == 0){
        printf("Aucun joueur enregistrer dans l'equipe");
    }
    else{
        search:
        int choix003;
        printf("\n1- Rechercher un joueur par Identifiant.");
        printf("\n2- Rechercher un joueur par Nom.\n");
        printf("Votre choix : ");
        scanf("%d",&choix003);
        getchar();
        switch (choix003)
        {
        case 1:
            int IDrech;
            printf("Entrer l'identifient du joueur a rechercher :");
            scanf("%d",&IDrech);
            getchar();
            int IDindex = -1;
            for (int i = 0; i < CntJoueur; i++){
                if (Equipe[i].ID == IDrech)
                {
                    IDindex = i;
                    break;
                }
            }
            
            if (IDindex == -1){
                printf("\nAucun joueur correspond au identifient entre !\n");
            }
            else{   
                printf("Joueur trouve !\n");
                printf("--------------------------------------------------\n");
                printf("ID : %d\n",Equipe[IDindex].ID);
                printf("Nom et Prenom : %s %s \n",Equipe[IDindex].nom, Equipe[IDindex].prenom);
                printf("Numero maillot : %d\n",Equipe[IDindex].numeroMaillot);
                printf("Poste : %s\n",Equipe[IDindex].poste);
                printf("Age : %d\n",Equipe[IDindex].age);
                printf("Nombre des buts marque : %d\n",Equipe[IDindex].buts);
                printf("Status : %s\n",Equipe[IDindex].status);
                printf("--------------------------------------------------\n");
            }
            break;
        case 2:
            printf("\nEntrer le nom du joueur a rechercher :");
            fgets(rechercheJ, sizeof(rechercheJ), stdin);
            rechercheJ[strcspn(rechercheJ, "\n")]='\0';
            Majuscule(rechercheJ);
            int NomIndex = -1;
            for (int  i = 0; i < CntJoueur; i++)
            {
                if (strcmp(Equipe[i].nom, rechercheJ)== 0)
                {
                    NomIndex = i;
                    break;
                }
            }
            
            if (NomIndex == -1){
                printf("\nAucun joueur correspond au nom entre !\n");
            }
            else{   
                printf("Joueur trouve !\n");
                printf("--------------------------------------------------\n");
                printf("ID : %d\n",Equipe[NomIndex].ID);
                printf("Nom et Prenom : %s %s \n",Equipe[NomIndex].nom, Equipe[NomIndex].prenom);
                printf("Numero maillot : %d\n",Equipe[NomIndex].numeroMaillot);
                printf("Poste : %s\n",Equipe[NomIndex].poste);
                printf("Age : %d\n",Equipe[NomIndex].age);
                printf("Nombre des buts marque : %d\n",Equipe[NomIndex].buts);
                printf("Status : %s\n",Equipe[NomIndex].status);
                printf("--------------------------------------------------\n");
            }
            break;
        default:
            printf("\nEntrer un choix valide !\n");
            goto search;
        }
    }
}
    // les fonctions des statistiques
void AfficheNbrtotale(){
        printf("\nLe nombre totale des joueurs dans l'equipe est : %d\n", CntJoueur);
}
void Agemoyenne(){
    int SommeAge = 0;
    int AgeMoyenne;
    for (int i = 0; i < CntJoueur; i++){
        SommeAge += Equipe[i].age;
    }
    AgeMoyenne = SommeAge/ (CntJoueur);
    printf("\nl'age moyenne des joueurs est:%d \n",AgeMoyenne);
}
void FiltrerParButs(){
    int nbrButs;
    int Butsfiltr[100];
    int j = 0;
    printf("Entrer le nombre des buts que vous voulez filtrer les joueurs par :");
    scanf("%d",&nbrButs);
    for (int i = 0; i < CntJoueur; i++){
        if (Equipe[i].buts > nbrButs){
            Butsfiltr[j] =i;
            j++;
        }
    }
    if (j == 0){
        printf("\nAucun joueur a marque plus de %d Buts !\n",nbrButs);
    }
    else{
        int index;
        printf("Les joueurs ayant marque plus de %d buts sont :\n");
        for (int i = 0; i < j; i++){
             index = Butsfiltr[i];
            printf("--------------------------------------------------\n");
            printf("ID : %d\nNom : %s\nPrenom : %s\nNumero maillot : %d\nPoste : %s\nAge : %d\nButs : %d\nStatus : %s\n",
            Equipe[index].ID, Equipe[index].nom, Equipe[index].prenom, Equipe[index].numeroMaillot, Equipe[index].poste, Equipe[index].age, Equipe[index].buts,Equipe[index].status);
        }
    }
}
void MeilleurButeur(){
    int Meilleur;
    int Meilleurindex = 0;
    Meilleur = Equipe[0].buts;
    for (int i = 0; i < CntJoueur; i++){
        if (Meilleur < Equipe[i].buts){
            Meilleur = Equipe[i].buts;
            Meilleurindex = i;
        }
    }
    if (Meilleurindex != -1){

        printf("\nLe le Meilleur Buteurs d'equipe est :\nID : %d\nNom : %s\nPrenom : %s\nNumero maillot : %d\nPoste : %s\nAge : %d\nButs : %d\nStatus : %s\n", 
         Equipe[Meilleurindex].ID, Equipe[Meilleurindex].nom, Equipe[Meilleurindex].prenom, Equipe[Meilleurindex].numeroMaillot, Equipe[Meilleurindex].poste, Equipe[Meilleurindex].age, Equipe[Meilleurindex].buts, Equipe[Meilleurindex].status);
    }
}
void MinMaxAge() {
    if (CntJoueur > 0) {
        int Jeune = Equipe[0].age;
        int Age = Equipe[0].age;
        int Jeuneindex = 0, Ageindex = 0;

        for (int i = 1; i < CntJoueur; i++) {
            if (Equipe[i].age < Jeune) {
                Jeune = Equipe[i].age;
                Jeuneindex = i;
            }
            if (Equipe[i].age > Age) {
                Age = Equipe[i].age;
                Ageindex = i;
            }
        }

        printf("\n--------------------------------------------------\n");

        if (Jeuneindex != Ageindex) {
            printf("Le joueur le plus jeune est : \nID: %d\nNom : %s\nPrenom : %s\nNumero maillot : %d\nPoste : %s\nAge : %d\nButs : %d\nStatus : %s\n\n",
                Equipe[Jeuneindex].ID, Equipe[Jeuneindex].nom, Equipe[Jeuneindex].prenom,
                Equipe[Jeuneindex].numeroMaillot, Equipe[Jeuneindex].poste, Equipe[Jeuneindex].age,
                Equipe[Jeuneindex].buts, Equipe[Jeuneindex].status);
                printf("\n--------------------------------------------------\n");
            printf("Le joueur le plus age est : \nID: %d\nNom : %s\nPrenom : %s\nNumero maillot : %d\nPoste : %s\nAge : %d\nButs : %d\nStatus : %s\n",
                Equipe[Ageindex].ID, Equipe[Ageindex].nom, Equipe[Ageindex].prenom,
                Equipe[Ageindex].numeroMaillot, Equipe[Ageindex].poste, Equipe[Ageindex].age,
                Equipe[Ageindex].buts, Equipe[Ageindex].status);
        } else {
            printf("Un seul joueur enregistré !\n");
            printf("ID : %d\nNom : %s\nPrenom : %s\nNumero maillot : %d\nPoste : %s\nAge : %d\nButs : %d\nStatus : %s\n",
                Equipe[Ageindex].ID, Equipe[Ageindex].nom, Equipe[Ageindex].prenom,
                Equipe[Ageindex].numeroMaillot, Equipe[Ageindex].poste, Equipe[Ageindex].age,
                Equipe[Ageindex].buts, Equipe[Ageindex].status);
        }

        printf("--------------------------------------------------\n");
    } else {
        printf("Aucun joueur enregistré.\n");
    }
}
void MenuPrincipale();
void MenuStatistiques(){
    statistique:
    int choixstatistique;
    printf("\n-----------------------------Statistique Menu-----------------------------\n");
    printf("\t1 -Afficher le nombre total de joueurs dans l'equipe.\n");
    printf("\t2- Afficher l'age moyen des joueurs.\n");
    printf("\t3- Afficher les joueurs ayant marque plus de X buts (X introduit par l'utilisateur).\n");
    printf("\t4- Afficher le meilleur buteur (joueur avec le maximum de buts).\n");
    printf("\t5- Afficher le joueur le plus jeune et le plus age.\n");
    printf("\t6- Return au menu.\n");
    printf("\n Votre choix : ");
    scanf("%d",&choixstatistique);
    getchar();
    switch (choixstatistique)
    {
    case 1:
        system("cls");
        AfficheNbrtotale();
        break;
    case 2:
        system("cls");
        Agemoyenne();
        break;
    case 3:
        system("cls");
        FiltrerParButs();
        break;
    case 4:
        system("cls");
        MeilleurButeur();
        break;
    case 5:
        system("cls");
        MinMaxAge();
        break;
    case 6:
        system("cls");
        MenuPrincipale();
        break;
    default:
        printf("\nChoix invalide !\n");
        goto statistique;
        break;
    }
}
void MenuPrincipale(){
    int MenuChoix;
    do{
        printf("\n-------------- Systeme de gestion d'equipe de football YouCode--------------\n");
        printf("\t1- Ajouter un joueur.\n");
        printf("\t2- Afficher la liste de tous les joueurs.\n");
        printf("\t3- Modifier un joueur.\n");
        printf("\t4- Supprimer un joueur.\n");
        printf("\t5- Rechercher un joueur.\n");
        printf("\t6- Entrer au menu des statistiques.\n"); 
        printf("\t0- Termine le program\n");
        printf("--------------------------------------------------\n");
        printf("Entrer votre choix :");
        scanf("%d",&MenuChoix);
        getchar();
        system("cls");
        switch (MenuChoix)
        {
        case 0:
            break;
        case 1:
            AjouterJoueur();
            break;
        case 2:
            AfficherListe();
            break;
        case 3:
            ModifierJoueur();
            break;
        case 4:
            supprimerJoueur();
            break;
        case 5:
            rechercheJoueur();
            break;
        case 6:
            MenuStatistiques();
            break;
        default:
            printf("\nchoix invalide!");
        }
    }while(MenuChoix != 6);

}
int main(){
// fake data dor testing 

Equipe[CntJoueur++] = (Player){1001, "Benali", "Amine", 1, poste1, 30, 0, status1};
Equipe[CntJoueur++] = (Player){1002, "El Idrissi", "Youssef", 2, poste2, 28, 1, status1};
Equipe[CntJoueur++] = (Player){1003, "Zouhair", "Sami", 3, poste2, 25, 2, status2};
Equipe[CntJoueur++] = (Player){1004, "Karim", "Taha", 4, poste2, 29, 1, status1};
Equipe[CntJoueur++] = (Player){1005, "Omar", "Rachid", 5, poste3, 27, 5, status1};
Equipe[CntJoueur++] = (Player){1006, "Omar", "Karim", 6, poste3, 24, 3, status2};
Equipe[CntJoueur++] = (Player){1007, "Yassir", "Amar", 7, poste3, 22, 4, status2};
Equipe[CntJoueur++] = (Player){1008, "Nabil", "Ayoub", 8, poste4, 26, 10, status1};
Equipe[CntJoueur++] = (Player){1009, "Rania", "Salma", 9, poste4, 23, 7, status2};
Equipe[CntJoueur++] = (Player){1010, "Leila", "Meriem", 10, poste4, 21, 6, status1};


MenuPrincipale();
    return 0;
}