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
//#include <time.h>

#include "fichiers.h"


// not ready until difficulty level, name are defined
// 1: ready / 0: not ready
int joueurIsReady(Joueur* elJugador)
{
    int dif;
    dif = elJugador->difficulty;
    char nom;
    nom = elJugador->nom;

    if(elJugador->difficulty > 0)
        if (strlen(elJugador->nom) > 0)
            return 1;
    return 0;
}


void Info_jouer(Joueur* elJugador)
{
    /*- Traitements ------------------------------------------*/
    clrscr();

    gotoxy(41, 12); printf("Votre nom    : ");
    gotoxy(57, 12); scanf("%s", elJugador->nom);
    gotoxy(41, 13); printf("Votre prenom : ");
    gotoxy(57, 13); scanf("%s", elJugador->prenom);

    //Ahora se hace en el menu mismo si existe un nombre
    //printf("\nBonne chance %s %s.\n", elJugador->nom , elJugador->prenom);

}


char execute_menu (Joueur* elJugador, char *error_message)
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
        if (joueurIsReady(elJugador) == 0)
            textcolor(LIGHTGRAY);
        gotoxy(49,19); printf("<2>    Nouvelle partie");
        textcolor(LIGHTCYAN);
        gotoxy(49,20); printf("<3>    Options de jeu");
        gotoxy(49,21); printf("<4>    Quitter");

        //Si le nom de l' utilisateur exite, on affihce le message:
        if (strlen(elJugador->nom) > 0)
            gotoxy(44,12); printf(" Bonne chance %s %s ", elJugador->prenom, elJugador->nom);

        //Si il y a un message d' erreur on affiche le message:
        if (strlen(error_message) > 0)
        {
            textcolor(RED);
            gotoxy(40,13); printf(" %s ", error_message);
            textcolor(LIGHTCYAN);
        }


        gotoxy(56,22); printf("Votre choix : ");

        /*- Encoder le choix -----------------------------------------------------------------------------*/
        gotoxy(70,22); scanf(" %c", &reponse);


        return reponse;

}

char execute_menu_options (Joueur* elJugador, char *error_message)
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

    if (elJugador->invisible == 0)
    {
        textcolor(GREEN);
        gotoxy(45,11); printf("Mode invisible off");
        textcolor(LIGHTGREEN);
    }
    else
    {
        textcolor(RED);
        gotoxy(45,11); printf("Mode invisible actif");
        textcolor(LIGHTGREEN);
    }

    if (elJugador->difficulty == 0)
    {
        textcolor(LIGHTRED);
        gotoxy(45,12); printf("Dictionaire non selectionne");
        textcolor(LIGHTGREEN);
    }
    else
    {
        gotoxy(45,12); printf("Dictionaire de niveau %d", elJugador->difficulty);
    }

    //Si il y a un message d' erreur on affiche le message:
    if (strlen(error_message) > 0)
    {
        textcolor(RED);
        gotoxy(40,13); printf(" %s ", error_message);
        textcolor(LIGHTGREEN);
    }

    textcolor(LIGHTCYAN);
    gotoxy(34,18); printf("<1>    Difficulte du dictionnaire");
    gotoxy(34,19); printf("<2>    Mode visible / invisible");
    gotoxy(34,20); printf("<4>    Quitter options");
    gotoxy(34,21); printf("Votre choix : ");
    gotoxy(49,21); scanf(" %c", &reponse);

    return reponse;

}


void Option_jeu (Joueur* elJugador)
{
    char choix;
    char errorMessage[100];
    errorMessage[0] = '\0';

    do
    {
        choix = execute_menu_options(elJugador, &errorMessage);
        errorMessage[0] = '\0';

        switch(choix)
        {
            case '1':
                elJugador->difficulty = Dif_dictionnaire();
            break;

            case '2':
                elJugador->invisible = Mode();
            break;

            default:
                strncpy(errorMessage, "Option not found.", 100);

        }
    }
    while (choix != '4');

}


int Mode ()
{
    /*- Traitements ------------------------------------------*/
    clrscr();
    char choix;

    gotoxy(41,14); printf("Mode invisible?");
    gotoxy(41,16); printf("<1>        Oui");
    gotoxy(41,17); printf("<2>        Non");
    gotoxy(34,19); printf("Votre choix : ");
    gotoxy(49,19); scanf(" %c", &choix);

    if (choix == '1')
    {
        return 1;
    }
    return 0;
}


int Dif_dictionnaire()
{
    /*- Traitements ------------------------------------------*/
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
        case '1':
            difficulte = 1;
        break;
        case '2':
            difficulte = 2;
        break;
        case '3':
            difficulte = 3;
        break;
        case '4':
            difficulte = 4;
        break;
        case '5':
            difficulte = 5;
        break;
        default:
            difficulte = 0;
    }
    return difficulte;

    //Leiremos usando dico.c y dico.h luege
    /*
    FILE* Niveau_dif = NULL;
    int op_dictionnaire;

    printf("Indiquez le niveau de difficulte de dictionnare : ");
    scanf("%d", &op_dictionnaire);

    switch(op_dictionnaire)
    {
        case 1 : Niveau_dif = fopen("dico/Difficulte1", "r");
                 break;
        case 2 : Niveau_dif = fopen("dico/Difficulte2", "r");
                 break;
        case 3 : Niveau_dif = fopen("dico/Difficulte3", "r");
                 break;
        case 4 : Niveau_dif = fopen("dico/Difficulte4", "r");
                 break;
        case 5 : Niveau_dif = fopen("dico/Difficulte5", "r");
                 break;

        return Niveau_dif;
    }
    */

}
/*int piocherMot (char* motPioche)
{

    int   nombreMots = 0;
          numMotChoisi = 0;
          caracterLu = 0;

    FILE* dico = NULL;

    dico = Dif_dictionnaire();

    if (dico == NULL)
    {
        printf("\nImpossible de charger le dictionnaire de mots");
        return 0;
    }

    do
    {
        caracterLu = fgetc(dico);
        if (caracterLu == '\n')
            nombreMots++;
    }
    while (caracterLu != EOF);

    numMotChoisi = nombreAleatoire(nombreMots);

    rewind(dico);

    while (numMotChoisi > 0)
    {
        caracterLu = fgetc(dico);
        if (caracterLu == '\n')
            numMotChoisi--;
    }
    fgets(motPioche, 100, dico);

    motPioche[strlen(motPioche) - 1] = '\0';
    fclose(dico);

    return 1;

}
int nombreAleatoire (int nombreMax)
{
    srand(time(NULL));
    return (rand() % nombreMax);
}*/
