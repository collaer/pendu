/**************************************************************/
/* Programme Pendu                                       */
/*============================================================*/
/* Auteur    : Espitia Yorley.                                */
/* Date      : 2020-05-05                                         */
/**************************************************************/

/*= Directives de précompilation =============================*/
#include <stdio.h>
#include <myconio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "fichiers.h"


int joueurEstPret(Joueur* leJoueur)
{

    if(leJoueur->difficulty > 0)
        if (strlen(leJoueur->nom) > 0)
            return 1;
    return 0;
}


void Info_jouer(Joueur* leJoueur)
{
    /*- Traitements ------------------------------------------*/
    clrscr();

    gotoxy(41, 12); printf("Votre nom    : ");
    gotoxy(57, 12); scanf("%s", leJoueur->nom);
    gotoxy(41, 13); printf("Votre prenom : ");
    gotoxy(57, 13); scanf("%s", leJoueur->prenom);

}


char execute_menu (Joueur* leJoueur, char* error_message)
{
    char reponse;

    _setcursortype(_SOLIDCURSOR);

        clrscr();

        /*- Affichage -----------------------------------------------------------------------------------*/
        textcolor(LIGHTGREEN);
        gotoxy(34, 6); printf("*  O  O  O  O  O  O  O  O  O  O  O  O  O  O  O  O  O  *");
        gotoxy(34, 7); printf("* /|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\ *");
        gotoxy(34, 8); printf("* / \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\ *");
        gotoxy(34,9); printf("*  O                                               O  *");
        gotoxy(34,10); printf("* /|\\         BIENVENUE DANS LE PENDU !           /|\\ *");
        gotoxy(34,11); printf("* / \\                                             / \\ *");
        gotoxy(34,12); printf("* / \\                                             / \\ *");
        gotoxy(34,13); printf("* / \\                                             / \\ *");
        gotoxy(34,14); printf("* / \\                                             / \\ *");
        gotoxy(34,15); printf("*  O  O  O  O  O  O  O  O  O  O  O  O  O  O  O  O  O  *");
        gotoxy(34,16); printf("* /|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\ *");
        gotoxy(34,17); printf("* / \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\ *");
        textcolor(LIGHTCYAN);
        gotoxy(49,18); printf("<1>    Information du Joueur");
        //Si le joueur n' est pas pret. Sa configuration : dico y nom pas defini ill ne peut pas jouer
        if (joueurEstPret(leJoueur) == 0)
            textcolor(LIGHTGRAY);
        gotoxy(49,19); printf("<2>    Nouvelle partie");
        textcolor(LIGHTCYAN);
        gotoxy(49,20); printf("<3>    Options de jeu");
        gotoxy(49,21); printf("<4>    Quitter");

        //Si le nom de l' utilisateur exite, on affihce le message:
        if (strlen(leJoueur->nom) > 0)
            gotoxy(47,12); printf(" Bonne chance %s %s ", leJoueur->prenom, leJoueur->nom);

        //Si il y a un message d' erreur on affiche le message:
        if (strlen(error_message) > 0)
        {
            textcolor(RED);
            gotoxy(50,13); printf("%s", error_message);
            textcolor(LIGHTCYAN);
        }


        gotoxy(56,22); printf("Votre choix : ");

        /*- Encoder le choix -----------------------------------------------------------------------------*/
        gotoxy(70,22); scanf(" %c", &reponse);


        return reponse;

}

char execute_menu_options (Joueur* leJoueur, char* error_message)
{
    char reponse;

    _setcursortype(_SOLIDCURSOR);
    clrscr();

    /*- Affichage -----------------------------------------------------------------------------------*/
    textcolor(LIGHTGREEN);
    gotoxy(30, 7); printf("*******************************************************");
    gotoxy(30,8); printf("*  O                                               O  *");
    gotoxy(30,9); printf("* /|\\               OPTIONS DE JEU !              /|\\ *");
    gotoxy(30,10); printf("* / \\                                             / \\ *");
    gotoxy(30,11); printf("* / \\                                             / \\ *");
    gotoxy(30,12); printf("* / \\                                             / \\ *");
    gotoxy(30,13); printf("* / \\                                             / \\ *");
    gotoxy(30,14); printf("* / \\                                             / \\ *");
    gotoxy(30,15); printf("*******************************************************");


    if (leJoueur->invisible == 1)
    {
        gotoxy(45,11); printf("Mode visible actif");
    }
    else
        if (leJoueur->invisible == 2)
        {
            textcolor(LIGHTRED);
            gotoxy(45,11); printf("Mode intermediaire actif");
            textcolor(LIGHTGREEN);
        }
        else
            if (leJoueur->invisible == 3)
            {
                textcolor(RED);
                gotoxy(45,11); printf("Mode invisible actif");
                textcolor(LIGHTGREEN);
            }
            else
            {
                        textcolor(LIGHTRED);
                        gotoxy(45,11); printf("Mode non selectionne");
                        textcolor(LIGHTGREEN);
            }

    if (leJoueur->difficulty == 0)
    {
        textcolor(LIGHTRED);
        gotoxy(45,12); printf("Dictionaire non selectionne");
        textcolor(LIGHTGREEN);
    }
    else
    {
        gotoxy(45,12); printf("Dictionaire de niveau %d", leJoueur->difficulty);
    }

    //Si il y a un message d' erreur on affiche le message:
    if (strlen(error_message) > 0)
    {
        textcolor(RED);
        gotoxy(45,13); printf("%s", error_message);
        textcolor(LIGHTGREEN);
    }

    textcolor(LIGHTCYAN);
    gotoxy(34,18); printf("<1>    Difficulte du dictionnaire");
    gotoxy(34,19); printf("<2>    Mode visible / intermediaire / invisible");
    gotoxy(34,20); printf("<4>    Quitter options");
    gotoxy(34,21); printf("Votre choix : ");
    gotoxy(49,21); scanf(" %c", &reponse);

    return reponse;

}

void Option_jeu (Joueur* leJoueur)
{
    char choix;
    char errorMessage[100];
    errorMessage[0] = '\0';

    do
    {
        choix = execute_menu_options(leJoueur, errorMessage);
        errorMessage[0] = '\0';

        switch(choix)
        {
            case '1': leJoueur->difficulty = Dif_dictionnaire();
                      break;

            case '2': leJoueur->invisible = Mode();
                      break;

            default:  strncpy(errorMessage, "Option non trouvee.", 100);

        }
    }
    while (choix != '4');

}

int Mode ()
{
    clrscr();
    int choix;

    gotoxy(41,14); printf("Mode ?");
    gotoxy(41,16); printf("<1>        Visible");
    gotoxy(41,17); printf("<2>        Intermediaire");
    gotoxy(41,18); printf("<3>        Invisible");
    gotoxy(41,19); printf("Votre choix : ");
    gotoxy(55,19); scanf(" %d", &choix);

    return choix;
}

int Dif_dictionnaire()
{
    clrscr();
    char choix;
    int difficulte;

    gotoxy(41,12); printf("Selectionner la difficulte du dictionnaire (1 a 5)");
    gotoxy(41,14); printf("<1>        Facile");
    gotoxy(41,15); printf(" |        ");
    gotoxy(41,16); printf(" |        ");
    gotoxy(41,17); printf("<5>        Complexe");
    gotoxy(34,19); printf("Votre choix : ");
    gotoxy(49,19); scanf(" %c", &choix);

    switch(choix)
    {
        case '1': difficulte = 1;
                  break;
        case '2': difficulte = 2;
                  break;
        case '3': difficulte = 3;
                  break;
        case '4': difficulte = 4;
                  break;
        case '5': difficulte = 5;
                  break;
        default:  difficulte = 2;
    }
    return difficulte;
}

void nouvelle_partie(Joueur* leJoueur)
{
    /*- Déclarations -----------------------------------------*/
    Partie laPartie;
    long i = 0;
    //char lettre = 0; // Stocke la lettre proposée par
                     //l'utilisateur (retour du scanf)

    /*- Creation nouvelle partie -----------------------------*/
    laPartie.coupsRestants = 6;
    piocherMot(laPartie.motSecret, leJoueur->difficulty);
    laPartie.tailleMot = strlen(laPartie.motSecret);
    laPartie.lettreTrouvee = malloc(laPartie.tailleMot * sizeof(int));
    for (i = 0 ; i < laPartie.tailleMot ; i++)
        laPartie.lettreTrouvee[i] = 0;

    menu_jeu(leJoueur, &laPartie);
}

void menu_jeu(Joueur* leJoueur, Partie* laPartie)
{
    char lettre = 0; // Stocke la lettre proposée par
                     //l'utilisateur (retour du scanf)
    long i = 0;
    long membresDuPendu = 0;
    char lettresGagnantes[40] = " ";
    char lettresPerdantes[40] = " ";
    char *tmpString;



    for (i = 0 ; i < laPartie->tailleMot ; i++)
        laPartie->lettreTrouvee[i];

    while (laPartie->coupsRestants > 0 && !gagne(laPartie->lettreTrouvee, laPartie->tailleMot))
    {

        clrscr();
        textcolor(LIGHTGREEN);
        gotoxy(30, 7); printf("*******************************************************");
        gotoxy(30,8); printf("*  O      Le pendu!    Coups restants:             O  *");
        gotoxy(69,8);  printf("%ld",laPartie->coupsRestants);
        gotoxy(30,9); printf("* /|\\                                             /|\\ *");
        gotoxy(30,10); printf("* / \\                                             / \\ *");
        gotoxy(30,11); printf("* / \\                                             / \\ *");
        gotoxy(30,12); printf("* / \\                                             / \\ *");
        gotoxy(30,13); printf("* / \\                                             / \\ *");
        gotoxy(30,14); printf("* / \\                                             / \\ *");
        gotoxy(30,15); printf("*******************************************************");
        gotoxy(30,16); printf("* Quel est le mot secret ?                            *");
        gotoxy(30,17); printf("*                                                     *");
        gotoxy(30,18); printf("*******************************************************");
        gotoxy(34,21); printf("Proposez une lettre ? ");

        switch (membresDuPendu)
        {
            case 6:  gotoxy(50,10);printf("X");
            case 5:  gotoxy(52,13);printf("-");
            case 4:  gotoxy(48,13);printf("-");
            case 3:  gotoxy(49,12);printf("/ \\");
            case 2:  gotoxy(49,11);printf("/|\\");
            case 1:  gotoxy(50,10);printf("O");
            default: gotoxy(43,9);printf("--------");
                     gotoxy(43,10);printf("|");
                     gotoxy(43,11);printf("|");
                     gotoxy(43,12);printf("|");
                     gotoxy(42,13);printf("/|\\");
                     gotoxy(40,14);printf("_/   \\_");
        }

        for (i = 0 ; i < laPartie->tailleMot ; i++)
        {

                switch(leJoueur->invisible)
                {
                    case 3:
                        /*= INVISIBLE---------------------------------------*/
                        if (laPartie->lettreTrouvee[i])
                        {
                            gotoxy(57+i,16); printf("+"); // On l'affiche comme les invisible
                        }
                        else
                        {
                            gotoxy(57+i,16); printf("?");
                        }
                        break;
                    case 2:
                        /*= INTERMEDIAIRE------------------------------------*/
                        if (laPartie->lettreTrouvee[i])
                        {
                            gotoxy(57+i,16); printf("%c", laPartie->motSecret[i]); // On l'affiche sous forme de point dinterrogation
                        }
                        else
                        {
                            gotoxy(57+i,16); printf("*");
                        }
                        break;
                    case 1:
                    default:
                        /*= VISIBLE------------------------------------------*/
                        gotoxy(32,17); printf("%s [%s ]", lettresGagnantes, lettresPerdantes);
                        if (laPartie->lettreTrouvee[i])
                        {
                            gotoxy(57+i,16); printf("%c", laPartie->motSecret[i]); // On l'affiche
                        }
                        else
                        {
                            gotoxy(57+i,16); printf("*");
                        }
                        break;
                }

        }

        //gotoxy(42+i, 17); printf("%c ", lettre);/* nombreLettresTrouvees(laPartie->lettreTrouvee, laPartie->tailleMot), laPartie->tailleMot);*/

        gotoxy(56,21); lettre = lireCaractere();

        if (!rechercheLettre(lettre, laPartie->motSecret, laPartie->lettreTrouvee))
        {
            laPartie->coupsRestants--;
            membresDuPendu++;
            strncat(lettresPerdantes, &lettre, 1);
        }
        else
        {
            strncat(lettresGagnantes, &lettre, 1);
        }
    }


    if (gagne(laPartie->lettreTrouvee, laPartie->tailleMot))
        printf("\n\nGagne ! Le mot secret etait bien : %s", laPartie->motSecret);
    else
    {
        gotoxy(69,8);  printf("0");
        gotoxy(50,10); printf("X");
        gotoxy(1,23);  printf("\n\nPerdu ! Le mot secret etait : %s", laPartie->motSecret);
    }


    free(laPartie->lettreTrouvee); // On libère la mémoire allouée dynamiquement

}

char lireCaractere()
{
    char caractere = 0;

    caractere = getchar();

    if (caractere == '\n')
        caractere = getchar();

    caractere = toupper(caractere);

    while (getchar() != '\n')
        ;

    return caractere;
}

/*int nombreLettresTrouvees(int lettreTrouvee[], int tailleMot)
{
    int i = 0;
    int nb = 0;
    for (i = 0 ; i < tailleMot ; i++)
    {
        if (lettreTrouvee[i] == 1)
            nb++;
    }
    return nb;
}*/

int gagne(int* lettreTrouvee, long tailleMot)
{
    long i = 0;
    int joueurGagne = 1;

    for (i = 0 ; i < tailleMot ; i++)
        if (lettreTrouvee[i] == 0)
            joueurGagne = 0;


    return joueurGagne;
}

int rechercheLettre(char lettre, char motSecret[], int* lettreTrouvee)
{
    long i = 0;
    int bonneLettre = 0;

    for (i = 0 ; motSecret[i] != '\0' ; i++)
        if (lettre == motSecret[i])
        {
            bonneLettre = 1;
            lettreTrouvee[i] = 1;
        }


    return bonneLettre;
}
