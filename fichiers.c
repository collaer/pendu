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
/*#include <string.h>
#include <time.h>*/

#include "fichiers.h"


char Info_jouer(Jouer* Info)
{
    char MenuP;
    /*- Traitements ------------------------------------------*/
    clrscr();

    gotoxy(41, 12); printf("Votre nom    : ");
    gotoxy(57, 12); scanf("%s", Info->nom);
    gotoxy(41, 13); printf("Votre prenom : ");
    gotoxy(57, 13); scanf("%s", Info->prenom);

    printf("\nBonne chance %s %s.\n", Info->nom , Info->prenom);

    return MenuP = execute_menu();
}
char execute_menu ()
{
    char reponse;

    _setcursortype(_SOLIDCURSOR);

        clrscr();
        /*- Affichage -----------------------------------------------------------------------------------*/
        textcolor(LIGHTGREEN);
        gotoxy(34, 7); printf("*  O  O  O  O  O  O  O  O  O  O  O  O  O  O  O  O  O  *");
        gotoxy(34, 8); printf("* /|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\ *");
        gotoxy(34, 9); printf("* / \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\ *");
        gotoxy(34,10); printf("*  O                                               O  *");
        gotoxy(34,11); printf("* /|\\         BIENVENUE DANS LE PENDU !           /|\\ *");
        gotoxy(34,12); printf("* / \\                                             / \\ *");
        gotoxy(34,13); printf("*  O  O  O  O  O  O  O  O  O  O  O  O  O  O  O  O  O  *");
        gotoxy(34,14); printf("* /|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\ *");
        gotoxy(34,15); printf("* / \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\ *");
        textcolor(LIGHTCYAN);
        gotoxy(49,17); printf("<1>    Information du Jouer");
        gotoxy(49,18); printf("<2>    Nouvelle partie");
        gotoxy(49,19); printf("<3>    Options de jeu");
        gotoxy(49,20); printf("<4>    Quitter");
        gotoxy(56,22); printf("Votre choix : ");

        /*- Encoder le choix -----------------------------------------------------------------------------*/
        gotoxy(70,22); scanf(" %c", &reponse);


        return reponse;

}
void Option_jeu (char *mode_fonct)
{
    FILE* Mots;


    _setcursortype(_SOLIDCURSOR);
    clrscr();

        /*- Affichage -----------------------------------------------------------------------------------*/
        textcolor(LIGHTGREEN);
        gotoxy(30, 9); printf("*******************************************************");
        gotoxy(30,10); printf("*  O                                               O  *");
        gotoxy(30,11); printf("* /|\\               OPTIONS DE JEU !              /|\\ *");
        gotoxy(30,12); printf("* / \\                                             / \\ *");
        gotoxy(30,13); printf("*******************************************************");
        textcolor(LIGHTCYAN);
        gotoxy(34,16); printf("<1>    Difficulte du dictionnaire");
        gotoxy(34,17); printf("<2>    Mode visible / intermediaire / invisible");
        gotoxy(34,18); printf("<3>    Quitter options");
        gotoxy(34,20); printf("Votre choix : ");
        gotoxy(49,20); scanf(" %c", mode_fonct);

    do
    {

        switch(*mode_fonct)
        {
            case 1: Mots = Dif_dictionnaire();
            case 2: Mode();
        }
    }
    while (mode_fonct != 3);


}
void Mode ()
{
    printf("Mode visible, intermediaire, invisible \n");
}

char* Dif_dictionnaire()
{
    FILE* Niveau_dif = NULL;
    int op_dictionnaire;

    printf("Indiquez le niveau de difficulte de dictionnare : ");
    scanf("%d", &op_dictionnaire);

    switch(op_dictionnaire)
    {
        case 1 : Niveau_dif = fopen("Difficulte1", "r");
                 break;
        case 2 : Niveau_dif = fopen("Difficulte2", "r");
                 break;
        case 3 : Niveau_dif = fopen("Difficulte3", "r");
                 break;
        case 4 : Niveau_dif = fopen("Difficulte4", "r");
                 break;
        case 5 : Niveau_dif = fopen("Difficulte5", "r");
                 break;

        return Niveau_dif;
    }

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
