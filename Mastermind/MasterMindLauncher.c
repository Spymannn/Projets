/* *************************************
* PROJET : JEU MASTERMIND
* LABORATOIRE DE BASE DE PROGRAMMATION
* 1I groupe A
* HANINI Samir
* ANNEE 2012-2013
****************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
// ci dessus, les bibliothèques j'ai eu besoin pour le programme
//ci dessous, les fonctions créée pour le programme du mastermind
void entete();
int rejouer();
void menu();
void regles();
void genereCombiAleatoire(char tab_lettre[6]);
void afficheCombiAleatoire(char tab_lettre[6]);
void init(char tab_jeux[10][4]);
void afficheCouleurDispo();
int combinaisonVerifier(char tab_jeux[4], char tab_lettre[4]);
void tableauJeu(char tab_jeux[10][4],char tab_lettre[4]);
void correctionEntre(char tab_entree[4]);
void letplay();

int main()// le main
{
    int choixRejouer;
    int quitter = 0;
    char choixx;
    int choix = 0;

    entete();//affichage de l'en-tête par la fonction entete();

    do{
        do {

        menu();//affichange du menu
        scanf("%c",&choixx);//on entre un choix (1) (2) ou (3)
        fflush(stdin);
        printf("\n");
        choix = choixx;
            if(choix < 49 || choix > 51) printf("Choix incorrect ! \n");//si le choix n'est pas compris entre 1 et 3, on recommence, condition via la table ascii
        }
        while(choixx != '1' && choixx != '2' && choixx!= '3');



                switch(choixx)
            {
                case '1' :
                            letplay();//lancement du jeu lors du choix (1)
                            choixRejouer = rejouer();// lancement de la fonction rejouer en fin de partie
                            if(choixRejouer == 2)
                            {
                                quitter = 1;
                                break;
                                system("pause");
                            }
                            if(choixRejouer == 1)
                            {
                                break;
                            }
                            break;


                case '2' :
                            regles();// affichage des règles du jeu
                            break;


                case '3' :
                            printf("Au revoir ! \n");
                            quitter = 1;

                            system("pause");// on quitte le jeu
            }
    }
    while(quitter == 0);

return 0;
}
void entete()//en-tête du programme
{
    char eaccent1 = 130;// on utilise le code ascii pour pouvoir avoir les "e" accent et "a" accent sous l'invite de commande
    char eaccent2 = 138;

    printf("----------------------------------------");
    printf("\nProgramme r%calis%c par : Hanini Samir  ",eaccent1,eaccent1);
    printf("\nSection : informatique  Groupe : 1    ");
    printf("\nAnn%ce acad%cmique : 2010-2011          ",eaccent1,eaccent1);
    printf("\nNom de l'enseignant : Meganck        ");
    printf("\nProjet : Jeu du mastermind            ");
    printf("\n---------------------------------------\n\n\n");
}
int rejouer()// fonction rejouer qui retourne un int
{
    char rejouer;
    int nbreRejouer = 1;
    do{
    printf("Voulez-vous rejouer? O/N : ");
    scanf("%c",&rejouer);
    printf("\n");
    fflush(stdin);
    if((rejouer != 'O') && (rejouer !='N'))
    {
        printf("Mauvaise entrée, recommencez \n");
    }
    else if(rejouer =='N')
    {
        nbreRejouer = 2;
    }
    else
    {
        nbreRejouer = 0;
    }
    }while(nbreRejouer == 1);
    return nbreRejouer;

}
void menu()// fonction menu, qui affichera donc le menu
{
    char eaccent1 = 130,eaccent2 = 138;

        printf("======== Menu ========\n\n");
        printf(" (1) : Jouer \n");
        printf(" (2) : R%cgles \n",eaccent2);
        printf(" (3) : Quitter \n\n");
        printf("======================\n\n");
}
void regles()//fonction regles qui affichera les règles
{
    char eaccent1 = 130,eaccent2 = 138,eaccent3 = 136,aaccent = 133;
  printf("                           Les r%cgles sont :            \n ",eaccent2);
  printf("Le jeu se compose d'un grand nombre de plots de six couleurs diff%crentes, et d'une collection de petits plots noirs et blancs pour la correction.\n",eaccent1);
  printf("L'ordinateur agence une combinaison de quatre jetons formant la clef secr%cte que l'autre joueur devra trouver.\n",eaccent1);
  printf("Sauf indications contraires, rien n'interdit que la clef comporte plusieurs exemplaires d'un m%cme plot.\n",eaccent3);
  printf("Chaque fois que le joueur propose une combinaison, le meneur de jeu, donc l'ordinateur, dispose des jetons blancs et des jetons noirs.\n");
  printf("chaque jeton noir indique un plot pr%csent dans la clef, et plac%c correctement.\n",eaccent1,eaccent1);
  printf("chaque jeton blanc indique un plot pr%csent dans la clef, mais dans une position erron%ce.\n",eaccent1,eaccent1);
  printf("le correcteur dispose les jetons blancs et noirs dans un ordre quelconque.\n");
  printf("Le joueur a droit %c dix essais, pour d%cterminer la clef par d%cduction logique.\n\n",aaccent,eaccent1,eaccent1);

}
void genereCombiAleatoire(char tab_lettre[4])// fonction qui génère 4 couleurs, placer dans un tableau nommé tab_lettre
{
    int nbre = 0,i = 1;

srand(time(NULL));// utilisation d'un random

for( i = 0; i<=3; i++)
{

    nbre = (rand()%6)+1;// utilisation d'un random de 1 à 6

    if(nbre == 1)
    {
        tab_lettre[i]='R';
    }
    else if(nbre == 2)
    {
       tab_lettre[i]='V';
    }
    else if(nbre == 3)
    {
        tab_lettre[i]='B';
    }
    else if(nbre == 4)
    {
        tab_lettre[i]='J';
    }
    else if(nbre == 5)
    {
        tab_lettre[i]='O';
    }
    else
    {
        tab_lettre[i]='M';
    }
}

}

void afficheCombiAleatoire(char tab_lettre[4])// permet d'afficher les 4 couleurs choisies aléatoirement dans la fonction ci dessus
{
    int i = 0;
    printf(" La combinaison gagnante est donc : ");

    for (i = 0; i<4; i++)
    {
        printf("%c",tab_lettre[i]);
    }
    printf("\n");
}
void init(char tab_jeux[10][4])// fonction qui initiatilise le tableau de jeux avec des *
{
 int i = 0, j = 0;

 for( i=0; i<10; i++)
 {
     for (j = 0; j<4; j++)
     {
         tab_jeux[i][j] = '*';
     }
 }
}

void afficheCouleurDispo()// fonction qui affiche les couleurs disponible pour le jeux
{
    printf("Couleurs disponibles : \n");
    printf("==========================================================\n");
    printf("R=Rouge - V=Vert - B=Bleu - J=Jaune - O=Orange - M=Marron\n");
    printf("==========================================================\n\n");

}
int combinaisonVerifier(char tab_jeux[4], char tab_lettre[4])//fonction qui permettra de vérifier la combinaison en renvoyant un int qui sera soit true, soit false
{
   int i=0;

    for (i=0 ; i<4 ; i++)
    {
        if (tab_lettre[i] != tab_jeux[i])
        {
        return 0;// le O renvoi un false
        }
    }
    return 1;// le 1 renvoi un true
}
void tableauJeu(char tab_jeux[10][4],char tab_lettre[4])// fonction void qui affichera le tableau, et qui mettra le 'N' ou le 'B' à leur place au le déroulement de la partie
{
    int i = 0, j = 0,nbre = 0, nbre2 = 0;

    printf("--------------------------\n");
    for ( i = 9; i >= 0; i--)
    {
        char tab_correction[4] = {'.', '.', '.', '.'};// on initialise le tableau de corrction par des '.' comme demander, qui seront remplacer par la suite par des 'N' ou des 'B'

        for ( j = 0; j < 4; j++)
        {
            if (tab_lettre[j] == tab_jeux[i][j])// condition si la lettre entrée est la lettre choisie au hasard par l'ordinateur, au même position
            {
                tab_correction[j] = 'N';
            }
            for (nbre= 0; nbre<4; nbre++)
            {
                if (tab_correction[nbre] !='N')
                    {
                        for(nbre2 = 0; nbre2<4; nbre2++)
                        {
                            if (tab_lettre[nbre2] == tab_jeux[i][nbre])
                            {
                                tab_correction[nbre] = 'B';
                            }
                        }
                    }
            }
        }
    printf("[%d] - [ (%c) (%c) (%c) (%c)]  [(%c)(%c)(%c)(%c)]\n",i+1,tab_jeux[i][0],tab_jeux[i][1],tab_jeux[i][2],tab_jeux[i][3],tab_correction[0],tab_correction[1],tab_correction[2],tab_correction[3]);// On imprime ici le tableau de jeu ainsi que les lettres choisies et les correction 'N' et/ou 'B'
    fflush(stdout);
    }
    printf("=======================================\n");

}
void correctionEntre(char tab_entree[4])//Fonction de correction des lettres entrées.
{
    int i = 0;
    int bon = 1;

    do
    {
        fflush(stdin);

        bon = 1;
        char tab_rentre[10];
        scanf("%s",tab_rentre);
        fflush(stdin);


        if(strlen(tab_rentre)>4)// condition si on entre un nombre trop grand de lettre
        {
            printf("Trop grand nombre entrer, recommenez !\n");
            bon = 0;
        }
        else
        {
            for(i = 0; i<4; i++)
            {
                tab_rentre[i] = toupper(tab_rentre[i]);// grâce à toupper, on met toute les lettres en majuscules

                if ((tab_rentre[i]!='R') && (tab_rentre[i]!='V') && (tab_rentre[i]!='B') && (tab_rentre[i]!='J') && (tab_rentre[i]!='O') && (tab_rentre[i]!='M'))// condition, si les lettres ne sont pas parmis les couleurs qu'il faut
                {
                    printf("Mauvaise entree, recommencez !\n");
                    bon = 0;
                    break;
                }

            tab_entree[i] = tab_rentre[i];
            }
        }
    }
    while(bon == 0);

}
void letplay()// fonction du jeu en entier
{
 char tab_jeux[10][4];
 char tab_lettre[4];
 int i = 0;
 int fini = 0;

 init(tab_jeux);// on lance la fonction init avec le tableau de jeux créer dans la fonction letplay, plus haut
 genereCombiAleatoire(tab_lettre);// on genere avec cette fonction une combinaison de lettre aléatoire

 for (i = 0; i<10; i++)
 {
    afficheCouleurDispo();// on affiche les couleurs disponibles, dans la boucle, à chaque fois que l'on doit entrer notre combinaison, afin de ne pas oublier les couleurs qu'il y a
    printf("\nEssai n# %d :\n",i+1);// on a en tout 10essai, d'où la boucle for ci dessus, les essais sont ainsi numérotés.
    correctionEntre(tab_jeux[i]);// on lance la fonction correctionEntre qui corrige si notre entrée est valibe ou pas
    tableauJeu(tab_jeux,tab_lettre);// on lance la fonction tableauJeu, qui imprimera le tableau de jeu, et qui mettra les 'N' et 'B' à leur place

    if(combinaisonVerifier(tab_jeux[i],tab_lettre))// condition, si on a trouver la bonne combinaison
    {
        printf(" Felicitations, vous avez gagnez !\n");
        afficheCombiAleatoire(tab_lettre);// on affiche la combinaison choisie au hasard par l'ordinateur
        fini = 1;
        break;
    }
 }
        if (fini == 0)// fini reste à 0, on n'a pas trouver la combinaison avant les 10 essais, c'est perdu !
        {
            printf("Dommage, vous avez perdu !\n");//Vous avez perdu, on imprime le message de perte à l'écran
            afficheCombiAleatoire(tab_lettre);// on affiche la combinaison qu'il fallait trouver !
        }
}
