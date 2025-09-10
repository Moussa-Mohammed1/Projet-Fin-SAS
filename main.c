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
// declaration d'un tableau des joueurs
Player Equipe[MaxJoueur];
char rechercheJ[20];
int CntJoueur = 0; // le nombre des joueurs enregistre dans l'equipe
int idplayer = 1;
    // fonction qui resoudre les problems d'espaces avant nom. et mettre le premier caractere en majuscule
void Majuscule(char str[]) {
    int i = 0, j = 0,c = 0;
    while (str[i] == ' ') i++;
    while (str[i]) {
        str[j++] = str[i++];
        c ++;
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
    printf("\n1.Ajoute simple. \t2.Ajoute multiple.\n");
    printf("Votre choix : ");
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
            strcpy(Equipe[CntJoueur].status,status1);
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
            printf("Entrer le numero de maillot du joueur: ");
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
            }while( Equipe[CntJoueur].dateInscription.day < 1 || Equipe[CntJoueur].dateInscription.day > 31 ||
                    Equipe[CntJoueur].dateInscription.mounth < 1 || Equipe[CntJoueur].dateInscription.mounth > 12 ||
                    Equipe[CntJoueur].dateInscription.year < 1985 || Equipe[CntJoueur].dateInscription.year > 2005 );
            
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
                strcpy(Equipe[CntJoueur].status,status1);
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
            printf("\n%d Ajoute terminee avec sucess !\n",Addscount +1);
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
                    printf("ID : %d\nNom et prenom : %s %s\nNumero Maillot : %d\nPoste : %s\nAge : %d\nButs Marque: %d\nDate d'inscription: %d %d %d\nStatus : %s", Equipe[i].ID,Equipe[i].nom,
                            Equipe[i].prenom, Equipe[i].numeroMaillot,Equipe[i].poste, Equipe[i].age,Equipe[i].buts, Equipe[i].dateInscription.day, Equipe[i].dateInscription.mounth, Equipe[i].dateInscription.year, Equipe[i].status);          
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
                    printf("ID : %d\nNom et prenom : %s %s\nNumero Maillot : %d\nPoste : %s\nAge : %d\nButs Marque: %d\nDate d'inscription: %d %d %d\nStatus : %s", Equipe[i].ID,Equipe[i].nom,
                            Equipe[i].prenom, Equipe[i].numeroMaillot,Equipe[i].poste, Equipe[i].age,Equipe[i].buts, Equipe[i].dateInscription.day, Equipe[i].dateInscription.mounth, Equipe[i].dateInscription.year, Equipe[i].status);          
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
                    printf("ID : %d\nNom et prenom : %s %s\nNumero Maillot : %d\nPoste : %s\nAge : %d\nButs Marque: %d\nDate d'inscription: %d %d %d\nStatus : %s", Equipe[i].ID,Equipe[i].nom,
                            Equipe[i].prenom, Equipe[i].numeroMaillot,Equipe[i].poste, Equipe[i].age,Equipe[i].buts, Equipe[i].dateInscription.day, Equipe[i].dateInscription.mounth, Equipe[i].dateInscription.year, Equipe[i].status);          
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
                    printf("ID : %d\nNom et prenom : %s %s\nNumero Maillot : %d\nPoste : %s\nAge : %d\nButs Marque: %d\nDate d'inscription: %d %d %d\nStatus : %s", Equipe[i].ID,Equipe[i].nom,
                            Equipe[i].prenom, Equipe[i].numeroMaillot,Equipe[i].poste, Equipe[i].age,Equipe[i].buts, Equipe[i].dateInscription.day, Equipe[i].dateInscription.mounth, Equipe[i].dateInscription.year, Equipe[i].status);          
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
                    printf("ID : %d\nNom et prenom : %s %s\nNumero Maillot : %d\nPoste : %s\nAge : %d\nButs Marque: %d\nDate d'inscription: %d %d %d\nStatus : %s", Equipe[i].ID,Equipe[i].nom,
                    Equipe[i].prenom, Equipe[i].numeroMaillot,Equipe[i].poste, Equipe[i].age,Equipe[i].buts, Equipe[i].dateInscription.day, Equipe[i].dateInscription.mounth, Equipe[i].dateInscription.year, Equipe[i].status);
                }
            }
            printf("\n--------------------------------------------------\n");
            printf("Afficher par poste : \n");
            printf(" Poste Defenseur :\n");
            for (int  i = 0; i < CntJoueur; i++)
            {
                if (strcmp(Equipe[i].poste, poste2)==0)
                {
                    printf("--------------------------------------------------\n");
                    printf("ID : %d\nNom et prenom : %s %s\nNumero Maillot : %d\nPoste : %s\nAge : %d\nButs Marque: %d\nDate d'inscription: %d %d %d\nStatus : %s", Equipe[i].ID,Equipe[i].nom,
                    Equipe[i].prenom, Equipe[i].numeroMaillot,Equipe[i].poste, Equipe[i].age,Equipe[i].buts, Equipe[i].dateInscription.day, Equipe[i].dateInscription.mounth, Equipe[i].dateInscription.year, Equipe[i].status);
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
                    printf("ID : %d\nNom et prenom : %s %s\nNumero Maillot : %d\nPoste : %s\nAge : %d\nButs Marque: %d\nDate d'inscription: %d %d %d\nStatus : %s", Equipe[i].ID,Equipe[i].nom,
                    Equipe[i].prenom, Equipe[i].numeroMaillot,Equipe[i].poste, Equipe[i].age,Equipe[i].buts, Equipe[i].dateInscription.day, Equipe[i].dateInscription.mounth, Equipe[i].dateInscription.year, Equipe[i].status);
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
                    printf("ID : %d\nNom et prenom : %s %s\nNumero Maillot : %d\nPoste : %s\nAge : %d\nButs Marque: %d\nDate d'inscription: %d %d %d\nStatus : %s", Equipe[i].ID,Equipe[i].nom,
                    Equipe[i].prenom, Equipe[i].numeroMaillot,Equipe[i].poste, Equipe[i].age,Equipe[i].buts, Equipe[i].dateInscription.day, Equipe[i].dateInscription.mounth, Equipe[i].dateInscription.year, Equipe[i].status);
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
        printf("\n2- Modifier l'âge d'un joueur.");
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
            for(int i = j - 1; i>=0 ; i--)
            {
                int index = RechJ[i];
                printf("\n--------------------------------------------------\n");
                printf("joueur Numero %d :\n ID : %d \nNom et prenom : %s %s\nNumero Maillot : %d\nPoste : %s\nAge : %d\nButs Marque: %d\nDate d'inscription: %d %d %d\nStatus : %s",(-1)*(i-j), Equipe[index].ID, Equipe[index].nom,
                        Equipe[index].prenom, Equipe[index].numeroMaillot,Equipe[index].poste, Equipe[index].age, Equipe[index].buts, Equipe[index].dateInscription.day, Equipe[index].dateInscription.mounth, Equipe[index].dateInscription.year, Equipe[index].status);
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
                    printf("\nEntrer le nouveau age :");
                    scanf("%d",&Equipe[choix03].age);
                    getchar();
                    printf("Age modifie avec success !\n");
                break;
                case 3:
                    printf("\nEntrer le nouveau nombre des buts du joueurs :");
                    scanf("%d",&Equipe[choix03].buts);
                    getchar();
                    break;
            }
        invalide:
            char repeat;
            printf("Essayer a nouveau ? (o/n):");// o: oui, n: non
            scanf("%c",&repeat);
            getchar();
            if(repeat == 'o'){goto repeat;}
            else if(repeat == 'n'){ }// si non , sortir de la fonction
            else{goto invalide;}
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
                exist =i;
                printf("\nJoueur exist !ID : %d \nNom et prenom : %s %s\nNumero Maillot : %d\nPoste : %s\nAge : %d\nButs Marque: %d\nDate d'inscription: %d %d %d\nStatus : %s \n", Equipe[i].ID, Equipe[i].nom, 
                    Equipe[i].prenom, Equipe[i].numeroMaillot, Equipe[i].poste, Equipe[i].age, Equipe[i].buts, Equipe[i].dateInscription.day, Equipe[i].dateInscription.mounth, Equipe[i].dateInscription.year);
                break;
            }
        }
        if (exist == -1){
       
            printf("l'ID %d ne correspond au aucun joueur !",targetID);
        }
        else{
        confirmation:
            int choix002;
            printf("Voulez vous vraiment supprimer ce joueur?\n1- continue \t2- annuler ");
            printf("\nEntrer votre choix:");
            scanf("%d",&choix002);
            getchar();
            switch (choix002)
            {
            case 1:
                for (int i = exist - 1; i < CntJoueur - 1; i++)
                {
                    Equipe[i]=Equipe[i + 1];
                }
                CntJoueur --;
                printf("l'identifient %d est supprime avec success !\n");
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
int main(){
// fake data dor testing
Equipe[CntJoueur++] = (Player){1011, "Benali", "Amine", 1, poste1, 30, 0, {12, 6, 2020}, status1};
Equipe[CntJoueur++] = (Player){1002, "El Idrissi", "Youssef", 2, poste2, 28, 1, {5, 2, 2019}, status1};
Equipe[CntJoueur++] = (Player){1003, "Zouhair", "Sami", 3, poste2, 25, 2, {20, 7, 2021}, status2};
Equipe[CntJoueur++] = (Player){1004, "Karim", "Taha", 8, poste2, 29, 1, {18, 11, 2019}, status1};
Equipe[CntJoueur++] = (Player){1005, "Omar", "Rachid", 4, poste3, 27, 5, {1, 1, 2018}, status1};
Equipe[CntJoueur++] = (Player){1006, "Omar", "Karim", 5, poste3, 24, 3, {15, 3, 2022}, status2};
Equipe[CntJoueur++] = (Player){1007, "Yassir", "Amar", 9, poste3, 22, 4, {30, 6, 2022}, status2};
Equipe[CntJoueur++] = (Player){1008, "Nabil", "Ayoub", 6, poste4, 26, 10, {10, 5, 2020}, status1};
Equipe[CntJoueur++] = (Player){1009, "Rania", "Salma", 7, poste4, 23, 7, {2, 9, 2021}, status2};
Equipe[CntJoueur++] = (Player){1010, "Leila", "Meriem", 10, poste4, 21, 6, {12, 12, 2021}, status1};
supprimerJoueur();
AjouterJoueur();
ModifierJoueur();
AfficherListe();
    return 0;
}



